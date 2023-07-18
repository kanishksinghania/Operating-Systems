#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
void odd(int n)
{
    for(int i=0;i<n;i++)
    {
        if(i%2!=0)
        {
            printf("The odd number is %d\n",i);
        }
    }
}
void even(int n)
{
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            printf("The even number is %d\n",i);
        }
    }
}
int main()
{
    int n,pid;
    printf("Enter upper range(n):");
    scanf("%d",&n);
    pid=fork();
    switch(pid)
    {
        case -1:
            printf("Error!");
            exit(-1);
        case 0:
            printf("Child process!!\n");
            even(n);
            exit(0);
        default:
            wait(NULL);
            printf("Parent process!!\n");
            odd(n);
            exit(0);
    }
    return 0;
}


