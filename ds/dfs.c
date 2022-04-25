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
int stack[20],top=-1;
void push(int vertex)
{
++top;
stack[top]=vertex;
}
int pop()
{
printf("%d ",stack[top]);
return stack[top--];
}
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
int unvisited_vertices(int vertex)
{
for(int i=0;i<vertices;++i)
{
if(edgeMatrix[vertex][i]==1 && vertList[i]->visited==false)
return i;
}
return -1;}
void DFS(int start)
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
push(start);
while(top>=0)
{
int temp_vertex=pop();
while((unvisitedVertex=unvisited_vertices(temp_vertex))!=-1)
{
vertList[unvisitedVertex]->visited=true;
push(unvisitedVertex);
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
printf("enter the starting vertex for DFS\n");
scanf("%d",&a);
DFS(a);
}
