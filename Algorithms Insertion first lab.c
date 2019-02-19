#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define SIZE 100000
#define SIZE1 5
int main()
{
    FILE *f;
    long int a[SIZE];
    int a1[SIZE1],key,i,j;
    clock_t start,end,start1,end1;
    int total;
    struct timeval tv;
    struct timezone tz;
    struct tm *tm;

    //for 5 inputs
    printf("Enter the %d elements:\n",SIZE1);
    for(i=0;i<SIZE1;i++)
    {
        scanf("%d",&a1[i]);
    }
    gettimeofday(&tv,&tz);
    for(i=1;i<SIZE1;i++)
    {
        key=a1[i];
        for(j=i-1;j>=0 && a1[j]>key;j--)
        {
            a1[j+1]=a1[j];
        }
        a1[j+1]=key;
    }
    tm = localtime(&tv.tv_sec);
    printf("Sorted data: ");
    for(i=0;i<SIZE1;i++)
    {
        printf("%d ",a1[i]);
    }
    printf("\nExecution time for 5 inputs(in millisec): %d millisec\n",tm->tm_sec);

    //for 1M inputs
    printf("For 1M:(please wait) \n");
    f = fopen("input.txt","w");  //writing a text file for inputs
    for(i=0;i<SIZE;i++)
    {
        fprintf(f,"%d ",rand());
    }
    fflush(f);
    fclose(f);
    f = fopen("input.txt","r");   //reading that file
    for(i=0;i<SIZE;i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    start = clock();
    for(i=1;i<SIZE;i++)
    {
        key=a[i];
        for(j=i-1;j>=0 && a[j]>key;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
    end = clock();
    fclose(f);
    f = fopen("output.txt","w");   //writing a file for output
    for(i=0;i<SIZE;i++)
    {
        fprintf(f,"%d ",a[i]);
    }
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\nExecution time for 1M(in millisec): %d millisec\n",total);
    fclose(f);

    printf("Time different: %d millisec\n",total-tm->tm_sec);
    return 0;
}

