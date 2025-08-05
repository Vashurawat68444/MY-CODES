#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int remainingBt; // Remaining Burst Time
    int wt;    // Waiting Time
    int tat;   // Turnaround Time
    int ct;    // Completion Time
} Process;

void calculateTimes(Process p[], int n) {
    int completed = 0, currentTime = 0, minRemainingBt, index;
    while (completed < n) {
        minRemainingBt = INT_MAX;
        index = -1;

        // Find process with the shortest remaining burst time
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && p[i].remainingBt > 0 && p[i].remainingBt < minRemainingBt) {
                minRemainingBt = p[i].remainingBt;
                index = i;
            }
        }

        if (index == -1) {
            currentTime++; // No process is ready, so CPU stays idle
            continue;
        }

        p[index].remainingBt--; // Execute the process

        // If the process is completed
        if (p[index].remainingBt == 0) {
            completed++;
            p[index].ct = currentTime + 1; // Completion Time
            p[index].tat = p[index].ct - p[index].at; // Turnaround Time
            p[index].wt = p[index].tat - p[index].bt; // Waiting Time
        }

        currentTime++;
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
    int n;

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
        p[i].remainingBt = p[i].bt; // Initially, remaining burst time = burst time
    }

    calculateTimes(p, n);
    findAverageTime(p, n);

    return 0;
}
