#include <stdio.h>

typedef struct {
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int remainingBt; // Remaining Burst Time
    int wt;    // Waiting Time
    int tat;   // Turnaround Time
    int ct;    // Completion Time
} Process;

void calculateTimes(Process p[], int n, int timeQuantum) {
    int currentTime = 0, completed = 0, queue[n], front = 0, rear = 0;
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        p[i].remainingBt = p[i].bt; // Initialize remaining burst time
    }

    // Add the first process to the queue if it has arrived
    for (int i = 0; i < n; i++) {
        if (p[i].at <= currentTime) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            currentTime++; // CPU idle
            for (int i = 0; i < n; i++) {
                if (p[i].at <= currentTime && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int index = queue[front++ % n]; // Circular queue

        if (p[index].remainingBt > timeQuantum) {
            currentTime += timeQuantum;
            p[index].remainingBt -= timeQuantum;
        } else {
            currentTime += p[index].remainingBt;
            p[index].remainingBt = 0;
            p[index].ct = currentTime; // Completion Time
            p[index].tat = p[index].ct - p[index].at; // Turnaround Time
            p[index].wt = p[index].tat - p[index].bt; // Waiting Time
            completed++;
        }

        // Add newly arrived processes to the queue
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // Add the current process back to the queue if it's not completed
        if (p[index].remainingBt > 0) {
            queue[rear++] = index;
        }
    }
}

void findAverageTime(Process p[], int n) {
    int totalWT = 0, totalTAT = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat, p[i].ct);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTAT / n);
}

int main() {
    int n, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process p[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    calculateTimes(p, n, timeQuantum);
    findAverageTime(p, n);

    return 0;
}
