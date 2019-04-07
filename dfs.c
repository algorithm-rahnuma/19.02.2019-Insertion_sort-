#include<stdio.h>
#include<stdlib.h>
#define M 100
#define BLACK 3
#define GRAY 2
#define WHITE 1
int v,M_edges,e1,e2,adj[M][M],i,G[M],last=-1,s[M],state[M],count=0,r,G[M];
void creat();
void I_graph();
void DFS();
void push_back(int r);
void pop_back();
void creat()
{
    printf("Enter the number of vertices(NODE START FROM 1): ");
    scanf("%d",&v);
    for(i=1;i<=v;i++)
    {
        G[i]=1;
    }
    M_edges=v*(v-1);
    printf("Enter -1 -1 after enter all edges\n");
    for(i=1;i<=M_edges;i++)
    {
        printf("Enter the edges(enter two nodes):");
        scanf("%d %d",&e1,&e2);
        if(e1==-1 && e2==-1)
        {
            break;
        }
        if(e1<0 || e1>v || e2<0 || e2>v)
        {
            printf("Wrong enter!!! Enter again: ");
            i--;
        }
        else
        {
            adj[e1][e2]=1;
        }
    }
}
void I_graph()
{
    for(i=1;i<=v;i++)
    {
        state[i]=WHITE;
    }
}
void DFS(int r)
{
    push_back(r);
    state[r]=GRAY;
    while(count!=0)
    {
        r=s[last];
        for(i=1;i<=v;i++)
        {
            if(adj[r][i]==1 && state[i]==WHITE)
            {
                push_back(i);
                state[i]=GRAY;
                r=i;
            }
        }
        printf("%d ",r);
        G[r]=0;
        state[r]=BLACK;
        pop_back();
    }
    for(i=1;i<=v;i++)
    {
        if(G[i]>0)
        {
            DFS(i);
        }
    }

}
void push_back(int r)
{
    last++;
    s[last]=r;
    count++;
}
void pop_back()
{
    if(count==0)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        last--;
        count--;
    }
}
int main()
{
    creat();
    I_graph();
    printf("Enter the start node: ");
    scanf("%d",&r);
    DFS(r);
}
