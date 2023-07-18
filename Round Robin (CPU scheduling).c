#include <stdio.h>


int main() {
int quantum, counter = 0, burstTime[10], i, n, arrivalTime = 0, turnAroundTime[10], waitTime[10], sum = 0, completionTime[10], oldBurstTime[10];
float avgWT = 0, avgTAT = 0;
printf("Enter no. of processes: ");
scanf("%d", &n);
printf("Enter time quantum: ");
scanf("%d", &quantum);

for(i = 0; i < n; i ++) {
printf("Enter burst time for PS[%d]: ", i+1);
scanf("%d", &burstTime[i]);
}
for(i = 0; i < n; i ++) {
oldBurstTime[i] = burstTime[i];
}
while(1) {
if(burstTime[i] > quantum) {
burstTime[i] -= quantum;
sum += quantum;
}
else if (burstTime[i] <= quantum && burstTime[i] > 0) {
sum += burstTime[i];
burstTime[i] = 0;
completionTime[i] = sum;
turnAroundTime[i] = completionTime[i] - arrivalTime;
++counter;

}
if (i == n) {
i = 0;
} else {
++i;
}
if (counter == n) {
break;
}
}
for(i = 0; i < n; i ++) {
avgTAT += (float)turnAroundTime[i];
}
for(i = 0; i < n; i ++) {
waitTime[i] = turnAroundTime[i] - oldBurstTime[i];
avgWT += (float)waitTime[i];
}
printf("PS\tTAT\tWT\tCT\tBT\n");
printf("-----\n");
for(i = 0; i < n; i ++) {
printf("%d\t%d\t%d\t%d\t%d\n", i, turnAroundTime[i], waitTime[i], completionTime[i], oldBurstTime[i]);
}

avgWT /= 4;
avgTAT /= 4;

printf("\nAvg TAT:%.2f\nAvg WT: %.2f\n", avgTAT, avgWT);

return 0;
}