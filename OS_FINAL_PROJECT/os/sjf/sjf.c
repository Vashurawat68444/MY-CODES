#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100

// Structure to store process details
typedef struct {
    char id[10];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int responseTime;
    int isCompleted;
} Process;

// Function to read processes from file
int readProcesses(Process processes[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%[^;];%d;%d;%*d;%*d\n", processes[count].id, &processes[count].arrivalTime, &processes[count].burstTime) != EOF) {
        processes[count].isCompleted = 0;
        count++;
    }
    fclose(file);
    return count;
}

// Function to simulate SJF (Non-Preemptive) Scheduling
void sjfScheduling(Process processes[], int n) {
    int currentTime = 0, completed = 0;
    
    while (completed < n) {
        int shortest = -1;
        int minBurst = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted && processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                shortest = i;
            }
        }
        
        if (shortest == -1) {
            currentTime++;
            continue;
        }
        
        processes[shortest].completionTime = currentTime + processes[shortest].burstTime;
        processes[shortest].turnaroundTime = processes[shortest].completionTime - processes[shortest].arrivalTime;
        processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
        processes[shortest].responseTime = processes[shortest].waitingTime;
        
        processes[shortest].isCompleted = 1;
        completed++;
        currentTime = processes[shortest].completionTime;
    }
}

// Function to display process details
void displayProcesses(Process processes[], int n) {
    printf("\nProcess\tArrival\tBurstCompletion TAT\tWaiting\tResponse\n ");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t  %d \t%d \t%d \t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, 
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime, processes[i].responseTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n = readProcesses(processes, "processes.txt");
    if (n == -1) return 1;
    
    sjfScheduling(processes, n);
    displayProcesses(processes, n);


    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        totalWT += processes[i].waitingTime;
        totalTAT += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);
    return 0;
}
