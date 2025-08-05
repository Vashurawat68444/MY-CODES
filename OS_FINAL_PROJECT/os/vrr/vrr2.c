#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define QUANTUM 5

typedef struct {
    char pid[10];
    int arrival;
    int burst;
    int remaining;
    int io_start;
    int io_burst;
    int io_done;
    int io_start_time;
    int response_time;
    int waiting_time;
    int turnaround_time;
    int first_cpu_time;
    int completed;
} Process;

int read_processes(Process p[]) {
    FILE *file = fopen("processes.txt", "r");
    if (!file) {
        printf("Error: Cannot open processes.txt\n");
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%[^;];%d;%d;%d;%d\n", p[count].pid, &p[count].arrival, &p[count].burst,
                  &p[count].io_start, &p[count].io_burst) == 5) {
        p[count].remaining = p[count].burst;
        p[count].io_done = 0;
        p[count].io_start_time = -1;
        p[count].response_time = -1;
        p[count].waiting_time = 0;
        p[count].turnaround_time = 0;
        p[count].first_cpu_time = -1;
        p[count].completed = 0;
        count++;
    }
    fclose(file);
    return count;
}

void enqueue(int queue[], int *rear, int pid) {
    queue[++(*rear)] = pid;
}

int dequeue(int queue[], int *front, int *rear) {
    if (*front > *rear) return -1;
    return queue[(*front)++];
}

int main() {
    Process p[MAX];
    int n = read_processes(p);
    int time = 0, completed = 0;
    int ready_q[MAX], io_q[MAX], io_ret_q[MAX];
    int rqf = 0, rqr = -1, iqf = 0, iqr = -1, irf = 0, irr = -1;
    int visited[MAX] = {0};

    while (completed < n) {
        // Add new arrivals to ready queue
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && !visited[i]) {
                enqueue(ready_q, &rqr, i);
                visited[i] = 1;
            }
        }

        // I/O completion check
        for (int i = iqf; i <= iqr; i++) {
            int pid = io_q[i];
            if (time - p[pid].io_start_time >= p[pid].io_burst) {
                enqueue(io_ret_q, &irr, pid);
                // remove from io_q
                io_q[i] = -1;
            }
        }

        // Compact io_q
        int tmp[MAX], tmpf = 0, tmpr = -1;
        for (int i = iqf; i <= iqr; i++) {
            if (io_q[i] != -1) {
                enqueue(tmp, &tmpr, io_q[i]);
            }
        }
        memcpy(io_q, tmp, sizeof(int) * MAX);
        iqf = 0;
        iqr = tmpr;

        int current = -1;
        if (irf <= irr) {
            current = dequeue(io_ret_q, &irf, &irr);
        } else if (rqf <= rqr) {
            current = dequeue(ready_q, &rqf, &rqr);
        }

        if (current == -1) {
            time++;
            continue;
        }

        if (p[current].response_time == -1)
            p[current].response_time = time - p[current].arrival;

        int run_time = QUANTUM;
        for (int t = 0; t < QUANTUM && p[current].remaining > 0; t++) {
            time++;
            p[current].remaining--;

            // Check for I/O start
            if (!p[current].io_done && (p[current].burst - p[current].remaining) == p[current].io_start) {
                p[current].io_start_time = time;
                p[current].io_done = 1;
                enqueue(io_q, &iqr, current);
                run_time = t + 1;
                break;
            }

            // Check for new arrivals during execution
            for (int i = 0; i < n; i++) {
                if (p[i].arrival == time && !visited[i]) {
                    enqueue(ready_q, &rqr, i);
                    visited[i] = 1;
                }
            }
        }

        if (p[current].remaining == 0) {
            p[current].turnaround_time = time - p[current].arrival;
            p[current].waiting_time = p[current].turnaround_time - p[current].burst;
            p[current].completed = 1;
            completed++;
        } else if (p[current].io_done == 0) {
            enqueue(ready_q, &rqr, current);
        }
        // else: process is already sent to io_q
    }

    // Output
    printf("PID\tTurnaround\tWaiting\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t%d\n", p[i].pid, p[i].turnaround_time, p[i].waiting_time, p[i].response_time);
    }

    float throughput = (float)n / time;
    printf("\nSystem Throughput: %.2f processes/unit time\n", throughput);

    return 0;
}
