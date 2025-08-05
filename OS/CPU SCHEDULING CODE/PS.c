#include <stdio.h>

typedef struct {
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int priority; // Priority (lower number = higher priority)
    int wt;    // Waiting Time
    int tat;   // Turnaround Time
    int ct;    // Completion Time
} Process;

// Function to sort processes by priority and arrival time
void sortByPriority(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j + 1].priority || 
                (p[j].priority == p[j + 1].priority && p[j].at > p[j + 1].at)) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to calculate times
void calculateTimes(Process p[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        currentTime = (currentTime < p[i].at) ? p[i].at : currentTime;
        p[i].wt = currentTime - p[i].at;
        p[i].ct = currentTime + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        currentTime = p[i].ct;
    }
}

// Function to display and calculate average times
void findAverageTime(Process p[], int n) {
    int totalWT = 0, totalTAT = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].wt, p[i].tat, p[i].ct);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTAT / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];

    printf("Enter Arrival Time, Burst Time, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Process %d Priority: ", i + 1);
        scanf("%d", &p[i].priority);
    }

    sortByPriority(p, n);
    calculateTimes(p, n);
    findAverageTime(p, n);

    return 0;
}
