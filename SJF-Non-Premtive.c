#include <stdio.h>

typedef struct Process{
    int burstTime;
    int arrivalTime;
    int processNumber;
} Process;

float countAvgWaitingTime(float avg, int count){
    return avg / count;
}

int main(){

    int processCount = 0, i, j;
    float avgWaititngTime = 0.0, waitingTime = 0.0;

    Process temp;

    Process processes[100];
    
    printf("Enter process count:");
    scanf("%d", &processCount);
    printf("\n---- Enter Process Information -----\n\n");

    for(i = 0; i < processCount; i++){
        printf("Enter process %d arrival time: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);

        printf("Enter process %d burst time: ", i+1);
        scanf("%d", &processes[i].burstTime);
        processes[i].processNumber = (i + 1);
        printf("\n");
    }
    //Sorting via Process arrival time using bubble sort
    for(i = 0; i < processCount; i++){
        for(j = 0; j < (processCount - i - 1); j++){
            if(processes[j].arrivalTime > processes[j+1].arrivalTime){
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    int k = 1;
    int burst_time;
    int min;

    for(i = 0; i < processCount; i++){
        burst_time += processes[i].burstTime;
        min = processes[k].burstTime;

        for(j = k; j < processCount; j++){
            if((burst_time >= processes[j].arrivalTime) && (processes[j].burstTime < min)){
                temp = processes[k];
                processes[k] = processes[j];
                processes[j] = temp;
            }
        }
        k++;
    }
    printf("Process Name  Arrival Time  Burst Time Waiting Time\n");
    for(i = 0; i < processCount; i++){
        if(i == 0){
            printf("P%d\t\t%d\t\t%d\t%f\n", processes[i].processNumber, processes[i].arrivalTime, processes[i].burstTime, 0.0);
            continue;
        }
        waitingTime += processes[i - 1].burstTime;
        printf("P%d\t\t%d\t\t%d\t%f\n", processes[i].processNumber, processes[i].arrivalTime, processes[i].burstTime, waitingTime);
        avgWaititngTime += waitingTime;
    }

    printf("\nAverage Wating time: %f\n", countAvgWaitingTime(avgWaititngTime, processCount));

    return 0;
}