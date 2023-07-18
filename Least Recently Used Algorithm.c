#include<stdio.h>
#include<stdlib.h>

/*int min(framelen,time[framelen])
{
int min,k,pos;
min=time[0],pos=0;
for(k=0;k<framelen;k++)
{
if(time[k]<min)
{
min=time[k];
pos=k;
}
}
}*/
int main()
{
int l,framelen,i,j;
printf("Enter number of pages required : ");
scanf("%d",&l);
int page[l];
printf("Enter pages : ");
for(i=0;i<l;i++)
{
scanf("%d",&page[i]);
}

printf("Enter number of frames required : \n");
scanf("%d",&framelen);

int frames[framelen],flag,flag1,flag2,counter,time[framelen],pagefault;
counter=0;
flag=0;

for(i=0;i<framelen;i++)
{
frames[i]=-1;
}



// case1

for(i=0;i<l;i++)
{
flag1=flag2=0;
for(j=0;j<framelen;j++)
{
if(page[i]==frames[j])
{
counter++;
time[j]=counter;
flag1=flag2=1;
break;
}
}

// case 2

if(flag1==0)
{
for(j=0;j<framelen;++j)
{
if(frames[j]==-1)
{
counter++;
pagefault++;
frames[j]=page[i];
time[j]=counter;
flag2=1;
break;
}
}
}

// case 3

if(flag2==0)
{
int min,k,pos;
min=time[0],pos=0;
for(k=0;k<framelen;k++)
{
if(time[k]<min)
{
min=time[k];
pos=k;
}
}
pagefault++;
counter++;
frames[pos]=page[i];
time[pos]=counter;
}

//Printing

for(int m=0;m<framelen;m++)
{
printf("%d ",frames[m]);
}
printf("\n");


}
printf("Total number of pagefaults : %d ",pagefault);
}
