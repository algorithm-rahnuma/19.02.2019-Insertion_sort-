#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define S1 100000
#define S2 5
int i;
int part(int a[],int start,int end)
{
    int pind,temp,p;
    p=a[end];
    for(i=start,pind=start;i<end;i++)
    {
        if(a[i]<=p)
        {
            temp = a[pind];
            a[pind] = a[i];
            a[i] = temp;
            pind++;
        }
    }
    temp=a[pind];
    a[pind]=a[i];
    a[i]=temp;
    return pind;

}
void quick(int a[],int start,int end)
{
    int pind;
    if(start<end)
    {
        pind=part(a,start,end);
        quick(a,start,pind-1);
        quick(a,pind+1,end);
    }
}

int main()
{
    int array[S1],array1[S2];
    FILE *f,*f1;
    clock_t start,end;
    int total;
    struct timeval tv;
    struct timezone tz;
    struct tm *tm;

    printf("\nFor 5 inputs:\n");
    printf("\nEnter the elements:\n");
    for(i=0;i<S2;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nBefore sorting:\n");
    for(i=0;i<S2;i++)
    {
        printf("%d ",array[i]);
    }
    gettimeofday(&tv,&tz);
    quick(array,0,S2-1);
    tm = localtime(&tv.tv_sec);
    printf("\nAfter sorting:\n");
    for(i=0;i<S2;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\nExecution time for 5 inputs(in millisec): %d millisec\n",tm->tm_sec);
    f=fopen("input.txt","w");
    for(i=0;i<S1;i++)
    {
        fprintf(f,"%d ",rand());
    }
    fflush(f);
    fclose(f);
    f1=fopen("input.txt","r");
    for(i=0;i<S1;i++)
    {
        fscanf(f1,"%d",&array1[i]);
    }
    fclose(f1);
    start = clock();
    quick(array1,0,S1-1);
    end = clock();
    f=fopen("output.txt","w");
    for(i=0;i<S1;i++)
    {
        fprintf(f,"%d ",array1[i]);
    }
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\nExecution time for 1M(in millisec): %d millisec\n",total);
    printf("Time different: %d millisec\n",total-tm->tm_sec);
    return 0;
}
