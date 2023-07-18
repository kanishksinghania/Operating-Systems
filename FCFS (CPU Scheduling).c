#include <stdio.h>

int main()
{
 int p,at[5],bt[5],st[5],ct[5],tat[5],wt[5],i;
 printf("Enter the number of processes:\n");
 scanf("%d",&p);


for(int i=0; i<p; i++)
{
printf("Enter the arrival time of process %d: ",i+1);
scanf("%d", &at[i]);
}



for(int i=0; i<p; i++)
{
printf("Enter the burst time of process %d: ",i+1);
scanf("%d", &bt[i]);
}

for(i=0;i<p;i++)
 {
  if(i==0)
  {
   st[i]=at[i];
  }
  else
  {
   st[i]=st[i-1]+bt[i-1];
  }
  ct[i]=st[i]+bt[i];
  wt[i]=st[i]-at[i];
  tat[i]=ct[i]-at[i];
 }
 printf("PNo\tAT\tBT\tST\tCT\tTAT\tWT\n");
 for(i=0;i<p;i++)
 {
  printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],st[i],ct[i],tat[i],wt[i]);
 }

float s=0.0,m=0.0;
float avgtat,avgwt;
for(int i=0; i<p; i++)
{
s=s+tat[i];
m=m+wt[i];
avgtat=s/p;
avgwt=m/p;
}
printf("\nAverage turnaround time:%f",avgtat);
printf("\nAverage wait time:%f\n",avgwt);

return 0;
}
