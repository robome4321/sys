#include<stdio.h>
int l=-1,r=-1,n;

void enqueuer(int arr[50],int b,int n)
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
void enqueuel(int arr[50],int b,int n)
{
        if(l==-1&&r==-1)
        {
         r= n-1;
         l= n-1;
         arr[l]=b;
        }
       else if((l+(n-1))%n==r)
        {
         printf("overflow\n");
        }
        else
        {
         l=(l+(n-1))%n;
         arr[l]=b;
        }  
}
void dequeuel(int arr[50])
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
void dequeuer(int arr[50])
{
         if(l==-1&&r==-1)
         {
           printf("underflow\n");
         }
         else if(l==r)
         {
           printf("%d \n",arr[r]);
           l=-1;
           r=-1;
         }
         else
         {
           printf("%d \n",arr[r]);
           r=(r+(n-1))%n;
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
    while(a!=6)
    {
        scanf("%d",&a);
        if(a==1)
        {
          scanf("%d",&b);
          enqueuer(arr,b,n);
        }
        else if(a==2)
        {
          scanf("%d",&b);
          enqueuel(arr,b,n);
        }
       else if(a==3)
       {
         dequeuel(arr);
       }
       else if(a==4)
       {
         dequeuer(arr);
       }
       else if(a==5)
       {
         display(arr);
       }
    }
   
}
