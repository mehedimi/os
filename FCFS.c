#include <stdio.h>

struct Process
{
    int burstTime;
};

float countAvgWaitingTime(float avg, int count){
    return avg / count;
}

int main(){
    int processCount = 0, i;
    float avgWaititngTime = 0.0, waitingTime;

    struct Process processes[100];
    
    printf("Enter process count:");
    scanf("%d", &processCount);
    printf("Enter burst time: \n\n");
    for(i = 0; i < processCount; i++){
        printf("Enter process %d burst time: ", i+1);
        scanf("%d", &processes[i].burstTime);
    }
    printf("\nWaiting time:\n");
    for(i = 0; i < processCount; i++){
        if(i == 0){
            printf("Process 1 waiting time: 0\n");
            continue;
        }
        
        waitingTime += processes[i - 1].burstTime;
        printf("Process %d waiting time: %f\n", (i + 1), waitingTime);

        avgWaititngTime = (waitingTime + avgWaititngTime);

    }
    printf("\n");
    printf("\nAverage waiting time: %f\n", countAvgWaitingTime(avgWaititngTime, processCount));
    return 0;
}