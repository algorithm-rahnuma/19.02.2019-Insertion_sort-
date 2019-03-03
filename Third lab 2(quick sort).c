#include<stdio.h>
#include<stdlib.h>
#define S 10
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
    int array[S],s;
    printf("\nEnter the size of array: ");
    scanf("%d",&s);
    printf("\nEnter the elements:\n");
    for(i=0;i<s;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nBefore sorting:\n");
    for(i=0;i<s;i++)
    {
        printf("%d ",array[i]);
    }
    quick(array,0,s-1);
    printf("\nAfter sorting:\n");
    for(i=0;i<s;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}
