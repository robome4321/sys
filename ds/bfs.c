#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct graph
{
int data;
bool visited;
};
struct graph* vertList[20];
int edgeMatrix[10][10];
int vertIndex=0,vertices,edges;
int queue[20],front=-1,rear=-1;
void addVertex(int vertex)
{
struct graph* vertice=(struct graph*)malloc(sizeof(struct graph));
vertice->data=vertex;
vertice->visited=false;
vertList[vertIndex++]=vertice;
}
void addEdge(int a,int b)
{
edgeMatrix[a][b]=1;
edgeMatrix[b][a]=1;
}
void enqueue(int vertex)
{
++rear;
if(front==-1)
front=0;
queue[rear]=vertex;
}
int dequeue()
{
printf("%d ",queue[front]);
return queue[front++];
}
int unvisited_vertices(int vertex) //since in this question vertex and vertIndex are same
{
for(int i=0;i<vertices;++i)
{
if(edgeMatrix[vertex][i]==1 && vertList[i]->visited==false)
return i;}
return -1;
}
void BFS(int start)
{
int unvisitedVertex;
for(int i=0;i<vertices;++i) //checking for starting vertex
{if(vertList[i]->data==start)
{
vertList[i]->visited=true;
break;
}
if(i==vertices-1)
{printf("entered vertex not found");
return;
}}
enqueue(start);
while(front<=rear)
{
int temp_vertex=dequeue();
while((unvisitedVertex=unvisited_vertices(temp_vertex))!=-1)
{
vertList[unvisitedVertex]->visited=true;
enqueue(unvisitedVertex);
}}}
int main()
{
printf("enter the number of vertices\n");
scanf("%d",&vertices);
printf("enter the number of edges\n");
scanf("%d",&edges);
for(int i=0;i<vertices;++i)
for(int j=0;j<vertices;++j)
edgeMatrix[i][j]=0;
for(int i=0;i<vertices;++i)
addVertex(i);
int a,b;
for(int i=0;i<edges;++i)
{
printf("enter the two connecting edges\n");
scanf("%d%d",&a,&b);
addEdge(a,b);
}
printf("enter the starting vertex for BFS\n");
scanf("%d",&a);
BFS(a);
}
