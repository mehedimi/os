#include <stdio.h>

typedef struct Process{
    int burstTime;
    int priority;
    int processNumber;
} Process;

float countAvgWaitingTime(float avg, int count){
    return avg / count;
}

int main(){
    int processCount = 0, i, j;
    float avgWaititngTime = 0.0, waitingTime = 0.0;

    Process processes[100];
    Process temp;

    printf("Enter process count:");
    scanf("%d", &processCount);
    printf("---- Enter Process Information ---- \n\n");
    for (i = 0; i < processCount; i++){
        printf("Enter process %d burst time: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter process %d priority: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].processNumber = (i + 1);
        printf("\n");
    }

    for (i = 0; i < processCount; i++){
        for (j = 0; j < (processCount - i - 1); j++){
            if (processes[j].priority > processes[j + 1].priority){
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("Process Name Burst Time Waiting Time\n");
    for (i = 0; i < processCount; i++){
        if (i == 0){
            printf("P%d\t\t%d\t%f\n", processes[i].processNumber, processes[i].burstTime, 0.0);
            continue;
        }
        waitingTime += processes[i - 1].burstTime;
        printf("P%d\t\t%d\t%f\n", processes[i].processNumber, processes[i].burstTime, waitingTime);
        avgWaititngTime = (waitingTime + avgWaititngTime);
    }
    printf("\n");
    printf("\nAverage waiting time: %f\n", countAvgWaitingTime(avgWaititngTime, processCount));
    return 0;
}