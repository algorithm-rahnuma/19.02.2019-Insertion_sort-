#include<stdio.h>
#define s 100
int main()
{
    int A,i,j,S[s],F[s],key,temp,temp1,sequence[s];
    printf("Enter the number of Activities: ");
    scanf("%d",&A);
    printf("Enter start time and finish time:\n");
    for(i=1;i<=A;i++)
    {
        printf("Activity %d: ",i);
        scanf("%d %d",&S[i],&F[i]);
    }
    for(i=2;i<=A;i++)
    {
        temp=F[i];
        temp1=S[i];
        for(j=i-1;j>0 && F[j]>temp;j--)
        {
            F[j+1]=F[j];
            S[j+1]=S[j];
        }
        F[j+1]=temp;
        S[j+1]=temp1;
        sequence[j+1]=i;
    }
    printf("Selected Activities are:\nActivity %d[Start: %d, Finish: %d]\n",sequence[1],S[1],F[1]);
    for(j=1,i=2;i<=A;i++)
    {
        if(S[i]>=F[j])
        {
            printf("Activity %d[Start: %d, Finish: %d]\n",sequence[i],S[i],F[i]);
            j=i;
        }
    }
    return 0;
}
