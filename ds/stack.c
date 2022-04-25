#include<stdio.h>
void main()
{
    int a=0,b=0,n;
    int t=0;
    //printf("Enter the size of stack\n");
    scanf("%d",&n);
    int arr[n];
    while(a!=4)
    {
        scanf("%d",&a);
        if(a==1)
        {
          scanf("%d",&b);
        }
       if(a==1)
       {
           if(t<n)
           {
             arr[t]=b;
             t++;
           }
           else
           {
             printf("overflow\n");
           }
       }
       else if(a==2)
       {
         if(t>0)
         {
           printf("%d\n",arr[t-1]);
           t--;
         }
         else
         {
           printf("underflow\n");
         }
       }
       else if(a==3)
       {
         if(t==0)
         {
           printf("underflow\n");
         }
         else
         {
           for(int i=0;i<t;i++)
            {
               printf("%d ",arr[i]);
            }
            printf("\n");
          }  
       }
    }
   
}
