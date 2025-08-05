//---------------------------------------FCFS use for this--------------------------------------
#include <stdio.h>

// Define a structure for the process
typedef struct {
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int wt;   // Waiting Time
    int tat;  // Turnaround Time
    int ct;   // Completion Time
} Process;

// Function to sort processes by arrival time
void sortByArrival(Process p[], int n) {   //bubble sort use here.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {  //swaping code easy
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time, turnaround time, and completion time
void calculateTimes(Process p[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at; // CPU remains idle until process arrives
        }
        p[i].wt = currentTime - p[i].at;
        p[i].ct = currentTime + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        currentTime = p[i].ct;
    }
}

// Function to calculate and display average times
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
    }

    sortByArrival(p, n);
    calculateTimes(p, n);
    findAverageTime(p, n);

    return 0;
}
