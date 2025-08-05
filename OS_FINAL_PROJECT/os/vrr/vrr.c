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
    int priority; // Priority for Virtual Round Robin
} Process;

// Function to read processes from file
int readProcesses(Process processes[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%[^;];%d;%d;%d;%*d\n", processes[count].id, &processes[count].arrivalTime, &processes[count].burstTime, &processes[count].priority) != EOF) {
        processes[count].remainingTime = processes[count].burstTime;
        processes[count].responseTime = -1; // Response time not yet set
        count++;
    }
    fclose(file);
    return count;
}

// Function to simulate Virtual Round Robin Scheduling
void virtualRoundRobinScheduling(Process processes[], int n) {
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
        
        int highestPriority = -1, index = -1;
        for (int i = front; i < rear; i++) {
            if (highestPriority == -1 || processes[queue[i]].priority < highestPriority) {
                highestPriority = processes[queue[i]].priority;
                index = i;
            }
        }
        
        int selectedProcess = queue[index];
        for (int i = index; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        
        if (processes[selectedProcess].responseTime == -1) {
            processes[selectedProcess].responseTime = currentTime - processes[selectedProcess].arrivalTime;
        }
        
        int executeTime = (processes[selectedProcess].remainingTime > QUANTUM) ? QUANTUM : processes[selectedProcess].remainingTime;
        processes[selectedProcess].remainingTime -= executeTime;
        currentTime += executeTime;
        
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && processes[i].arrivalTime <= currentTime) {
                queue[rear++] = i;
                inQueue[i] = 1;
            }
        }
        
        if (processes[selectedProcess].remainingTime > 0) {
            queue[rear++] = selectedProcess;
        } else {
            processes[selectedProcess].completionTime = currentTime;
            processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
            processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;
            completed++;
        }
    }
}

// Function to display process details
void displayProcesses(Process processes[], int n) {
    printf("\nProcess\tArrival Burst Priority Completion TAT Waiting Response\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, 
               processes[i].priority, processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime, processes[i].responseTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n = readProcesses(processes, "processes.txt");
    if (n == -1) return 1;
    
    virtualRoundRobinScheduling(processes, n);
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
