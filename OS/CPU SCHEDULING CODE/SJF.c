#include <stdio.h>

typedef struct {
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int wt;   // Waiting Time
    int tat;  // Turnaround Time
    int ct;   // Completion Time
    int completed; // Process completion status (0 = not completed, 1 = completed)
} Process;

// Function to find the process with the shortest burst time that has arrived
int findShortestJob(Process p[], int n, int currentTime) {
    int shortest = -1;
    int minBurstTime = __INT_MAX__;
    for (int i = 0; i < n; i++) {
        if (p[i].at <= currentTime && !p[i].completed && p[i].bt < minBurstTime) {
            minBurstTime = p[i].bt;
            shortest = i;
        }
    }
    return shortest;
}

// Function to calculate waiting time, turnaround time, and completion time
void calculateTimes(Process p[], int n) {
    int currentTime = 0, completed = 0;

    while (completed < n) {
        int index = findShortestJob(p, n, currentTime);
        if (index != -1) {
            currentTime = (currentTime < p[index].at) ? p[index].at : currentTime;
            p[index].wt = currentTime - p[index].at;
            p[index].ct = currentTime + p[index].bt;
            p[index].tat = p[index].ct - p[index].at;
            p[index].completed = 1;
            currentTime = p[index].ct;
            completed++;  //this was binded from this function
        } else {
            currentTime++;
        }
    }
}

// Function to display and calculate average times
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
        p[i].completed = 0;
    }

    calculateTimes(p, n);
    findAverageTime(p, n);

    return 0;
}
