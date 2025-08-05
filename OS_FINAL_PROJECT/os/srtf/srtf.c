#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100

// Structure to store process details
typedef struct {
    char id[10];
    int arrivalTime;
    int burstTime;
    int remainingTime;
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
        processes[count].remainingTime = processes[count].burstTime;
        processes[count].responseTime = -1; // Response time not yet set
        processes[count].isCompleted = 0;
        count++;
    }
    fclose(file);
    return count;
}

// Function to simulate Shortest Remaining Time First (SRTF) Scheduling
void srtfScheduling(Process processes[], int n) {
    int currentTime = 0, completed = 0;
    
    while (completed < n) {
        int shortest = -1;
        int minRemaining = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted && processes[i].remainingTime < minRemaining) {
                minRemaining = processes[i].remainingTime;
                shortest = i;
            }
        }
        
        if (shortest == -1) {
            currentTime++;
            continue;
        }
        
        if (processes[shortest].responseTime == -1) {
            processes[shortest].responseTime = currentTime - processes[shortest].arrivalTime;
        }
        
        processes[shortest].remainingTime--;
        currentTime++;
        
        if (processes[shortest].remainingTime == 0) {
            processes[shortest].completionTime = currentTime;
            processes[shortest].turnaroundTime = processes[shortest].completionTime - processes[shortest].arrivalTime;
            processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
            processes[shortest].isCompleted = 1;
            completed++;
        }
    }
}

// Function to display process details
void displayProcesses(Process processes[], int n) {
    printf("\nProcess\tArrival\tBurstCompletion TAT\tWaiting\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d   \t%d \t%d \t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, 
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime, processes[i].responseTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n = readProcesses(processes, "processes.txt");
    if (n == -1) return 1;
    
    srtfScheduling(processes, n);
    displayProcesses(processes, n);

    float totalWT = 0, totalTAT = 0;
    int minArrivalTime = processes[0].arrivalTime;
    int maxCompletionTime = processes[0].completionTime;

    for (int i = 0; i < n; i++) {
        totalWT += processes[i].waitingTime;
        totalTAT += processes[i].turnaroundTime;

        if (processes[i].arrivalTime < minArrivalTime)
            minArrivalTime = processes[i].arrivalTime;

        if (processes[i].completionTime > maxCompletionTime)
            maxCompletionTime = processes[i].completionTime;
    }

    float throughput = (float)n / (maxCompletionTime - minArrivalTime); // processes per unit time

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);
    printf("Throughput = %.2f processes/unit time\n", throughput);

    return 0;
}
