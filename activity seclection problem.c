#include<stdio.h>
#define SIZE 6
void activity(int s[],int f[],int S)
{
    int i=1,j;
    printf("A%d: S:%d F:%d\n",i,s[i-1],f[i-1]);
    for(j=1;j<S;j++)
    {
        if(s[j]>=f[i])
        {
            printf("A%d: S:%d F:%d\n",j+1,s[j],f[j]);
            i = j;
        }
    }
}
int main()
{
    int s[SIZE],f[SIZE],i;
    for(i=0;i<SIZE;i++)
    {
        printf("A%d.S= ",i+1);
        scanf("%d",&s[i]);
        printf("A%d.f= ",i+1);
        scanf("%d",&f[i]);
    }
    activity(s,f,SIZE);
    return 0;
}
