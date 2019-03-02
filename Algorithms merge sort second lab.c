#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define N1 5
#define N2 100000
void merge(int left,int mid,int right,int array[])
{
    int a,b,c,s1,s2,x,y;
    s1=mid-left+1;
    s2=right-mid;
    int l_tree[s1],r_tree[s2];
    for(x=0;x<s1;x++)
    {
        l_tree[x] = array[left+x];
    }
    for(y=0;y<s2;y++)
    {
        r_tree[y] = array[mid+y+1];
    }
    for(a=0,b=0,c=left;a<s1 && b<s2;c++)
    {
        if(l_tree[a]<r_tree[b])
        {
            array[c]=l_tree[a];
            a++;
        }
        else
        {
            array[c]=r_tree[b];
            b++;
        }
    }
    while(a<s1)
    {
            array[c]=l_tree[a];
            a++;
            c++;
    }
    while(b<s2)
    {
            array[c]=r_tree[b];
            b++;
            c++;
    }
}
void sort(int first,int last,int Array[])
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        sort(first,mid,Array);
        sort(mid+1,last,Array);
        merge(first,mid,last,Array);
    }
}
int main()
{
    int i,n;
    int array[N1],Array[N2];
    FILE *f,*f1,*f2;
    clock_t start,end,start1,end1;
    int total;
    struct timeval tv;
    struct timezone tz;
    struct tm *tm;

    printf("For 5 inputs:\n");
    printf("Enter the elements: ");
    for(i=0;i<N1;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nBefore sorting:\n");
    for(i=0;i<N1;i++)
    {
        printf("%d ",array[i]);
    }
    gettimeofday(&tv,&tz);
    sort(0,N1-1,array);
    printf("\nAfter sorting:\n");
    for(i=0;i<N1;i++)
    {
        printf("%d ",array[i]);
    }
    tm = localtime(&tv.tv_sec);
    printf("\nExecution time for 5 inputs(in millisec): %d millisec\n",tm->tm_sec);
    printf("\nFor 1M input:\n");
    f=fopen("inmerge.txt","w");
    for(i=0;i<N2;i++)
    {
        fprintf(f,"%d ",rand());
    }
    fflush(f);
    fclose(f);
    f1=fopen("inmerge.txt","r");
    for(i=0;i<N2;i++)
    {
        fscanf(f1,"%d",&Array[i]);
    }
    fclose(f1);
    f2=fopen("outmerge.txt","w");
    fprintf(f2,"\nAfter sorting:\n");
    start = clock();
    sort(0,N2-1,Array);
    end = clock();
    for(i=0;i<N2;i++)
    {
        fprintf(f,"%d ",Array[i]);
    }
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\nExecution time for 1M(in millisec): %d millisec\n",total);
    fclose(f2);
    printf("Time different: %d millisec\n",abs(total-tm->tm_sec));
    return 0;
}
