#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t mutex,wrt;
pthread_t tid;
int kanishk=99;
pthread_t writers[5],readers[5];
int readercount=0;
void*reader(void*casey)
{
    sem_wait(&mutex);
    readercount++;
    if(readercount==1)
    sem_wait(&wrt);
    sem_post(&mutex);
    printf("\n%d reader is reading kanishk=%d",readercount,kanishk);
    
    sem_wait(&mutex);
    readercount--;
    if(readercount==0)
    sem_post(&wrt);
    sem_post(&mutex);
    
    printf("\n%d Reader is done",readercount+1);
}
void*writer(void*casey)
{
    printf("\nWriter is trying to enter");
    sem_wait(&wrt);
    printf("\nWriter has entered CS");
    kanishk++;
    printf("\nWriter CHANGED THE VALUE OF KANISHK TO %d",kanishk);
    sem_post(&wrt);
    printf("\nWriter is out of CS");
}
int main()
{
    int n2,i;
    printf("Enter the number of readers");
    scanf("%d",&n2);
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    for(i=0;i<n2;i++)
    {
        pthread_create(&writers[i],NULL,reader,NULL);
        pthread_create(&readers[i],NULL,writer,NULL);
    }
    {
        pthread_join(writers[i],NULL);
        pthread_join(readers[i],NULL);
        
    }
}