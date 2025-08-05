#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100
#define QUANTUM 5

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
        count++;
    }
    fclose(file);
    return count;
}

// Function to simulate Round Robin Scheduling
void roundRobinScheduling(Process processes[], int n) {
    int currentTime = 0, completed = 0;
    int queue[MAX_PROCESSES], front = 0, rear = 0;
    int inQueue[MAX_PROCESSES] = {0};
    
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime == 0) {
            queue[rear++] = i;
            inQueue[i] = 1;
        }
    }
    
    while (completed < n) {
        if (front == rear) {
            currentTime++;
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && processes[i].arrivalTime <= currentTime) {
                    queue[rear++] = i;
                    inQueue[i] = 1;
                }
            }
            continue;
        }
        
        int index = queue[front++];
        if (processes[index].responseTime == -1) {
            processes[index].responseTime = currentTime - processes[index].arrivalTime;
        }
        
        int executeTime = (processes[index].remainingTime > QUANTUM) ? QUANTUM : processes[index].remainingTime;
        processes[index].remainingTime -= executeTime;
        currentTime += executeTime;
        
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && processes[i].arrivalTime <= currentTime) {
                queue[rear++] = i;
                inQueue[i] = 1;
            }
        }
        
        if (processes[index].remainingTime > 0) {
            queue[rear++] = index;
        } else {
            processes[index].completionTime = currentTime;
            processes[index].turnaroundTime = processes[index].completionTime - processes[index].arrivalTime;
            processes[index].waitingTime = processes[index].turnaroundTime - processes[index].burstTime;
            completed++;
        }
    }
}

// Function to display process details
void displayProcesses(Process processes[], int n) {
    printf("\nProcess\tArrival\tBurst Completion TAT\tWaiting\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t  %d \t%d \t%d \t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, 
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime, processes[i].responseTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n = readProcesses(processes, "processes.txt");
    if (n == -1) return 1;
    
    roundRobinScheduling(processes, n);
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

