#include<stdio.h>
int l=-1,r=-1,n;

void enqueue(int arr[n],int b)
{
        if(l==-1&&r==-1)
        {
         r++;
         l++;
         arr[r]=b;
        }
       else if((r+1)%n==l)
        {
         printf("overflow\n");
        }
        else
        {
         r=(r+1)%n;
         arr[r]=b;
        } 
}
void dequeue(int arr[50])
{
         if(l==-1&&r==-1)
         {
           printf("underflow\n");
         }
         else if(l==r)
         {
           printf("%d \n",arr[l]);
           l=-1;
           r=-1;
         }
         else
         {
           printf("%d \n",arr[l]);
           l=(l+1)%n;
         }
}
void display(int arr[50])
{
         int i=l;
         if(l==-1&&r==-1)
         {
           printf("underflow\n");
         }
         else
         {
           while(i!=r)
           {
             printf("%d ",arr[i]);
             i=(i+1)%n;
           }
           printf("%d ",arr[i]);
           printf("\n");
         }
  
}

void main()
{
    int a=0,b=0;
    printf("Enter the size of queue\n");
    scanf("%d",&n);
    int arr[n];
    while(a!=4)
    {
        scanf("%d",&a);
        if(a==1)
        {
          scanf("%d",&b);
          enqueue(arr,b);
        }
       else if(a==2)
       {
         dequeue(arr);
       }
       else if(a==3)
       {
         display(arr);
       }
    }
   
}
