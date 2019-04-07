#include<stdio.h>
#include<stdlib.h>
#define M 100
#define BLACK 3
#define GRAY 2
#define WHITE 1
int i,v,s,d,M_edges,e1,e2,adj[M][M],state[M],count=0;
void C_graph();
void I_state();
void BFS();
void enqueue(int s);
void dequeue();
int isempty();
typedef struct NODE
{
    int data;
    struct NODE* next;
}node;
node* front = NULL;
node* rear = NULL;
void C_graph()
{
    printf("Enter the number of vertices(NODE START FROM 1): ");
    scanf("%d",&v);
    M_edges=(v*(v-1))/2;
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
            adj[e2][e1]=1;
        }
    }
}
void I_state()
{
    for(i=1;i<=v;i++)
    {
        state[i] = WHITE;
    }
}
void BFS()
{
    printf("Enter the Start node: ");
    scanf("%d",&s);
    enqueue(s);
    s=GRAY;
    while(count!=0)
    {
        d=front->data;
        dequeue();
        for(i=1;i<=v;i++)
        {
            if((adj[d][i]==1 || adj[i][d]) && state[i]==WHITE)
            {
                printf("travars: ");
                printf("%d ",i);
                enqueue(i);
                state[i]=GRAY;
            }
            printf("\n");
        }
        state[d]=BLACK;
        printf("Visited: ");
        printf("%d\n",d);
    }
}
void enqueue(int s)
{
    if(front==NULL)
    {
        rear=(node*)malloc(sizeof(node));
        rear->data=s;
        rear->next=NULL;
        front=rear;
    }
    else
    {
        rear->next=(node*)malloc(sizeof(node));
        rear->next->data=s;
        rear->next->next=NULL;
        rear=rear->next;
    }
    count++;
}
void dequeue()
{
    int ele;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    if(front->next == NULL)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }
    count--;
}
int isempty()
{
    if(front==NULL)
    {
        printf("Empty\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    C_graph();
    I_state();
    BFS();
}
