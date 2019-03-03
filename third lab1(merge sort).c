#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#define N1 5
int i,k;
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
    printf("\n");
    for(i=left;i<c;i++)
        {
            printf("%d ",array[i]);
        }
    printf("\n");
}
void sort(int first,int last,int Array[])
{
    int mid;
    if(first<last)
    {
        for(i=first;i<=last;i++)
        {
            printf("%d ",Array[i]);
        }
        printf("\n");
        mid=(first+last)/2;
        sort(first,mid,Array);
        sort(mid+1,last,Array);
        merge(first,mid,last,Array);
    }
}
int main()
{
    int array[N1];
    struct timeval tv;
    struct timezone tz;
    struct tm *tm;

    printf("For 5 inputs:\n");
    printf("Enter the elements: ");
    for(i=0;i<N1;i++)
    {
        scanf("%d",&array[i]);
    }
    gettimeofday(&tv,&tz);
    printf("Divide:\n");
    sort(0,N1-1,array);
    printf("\nAfter sorting:\n");
    for(i=0;i<N1;i++)
    {
        printf("%d ",array[i]);
    }
    tm = localtime(&tv.tv_sec);
    printf("\nExecution time for 5 inputs(in millisec): %d millisec\n",tm->tm_sec);
    return 0;
}
