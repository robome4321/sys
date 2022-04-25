#include<stdio.h>
void mergesort(int a[50],int lb,int ub)
{
    int mid,i;
    if(lb<ub)
    {
       mid=(lb+ub)/2 ;
       mergesort(a,lb,mid);
       mergesort(a,mid+1,ub);
       merge(a,lb,mid,ub);
       for(i=lb;i<=ub;i++)
       {
           printf("%d ",a[i]);
       }
       printf("\n");
    }
}

void merge(int a[50],int lb,int mid,int ub)
{
  int i=lb;
  int j=mid+1;
  int k=lb;
  int b[50];
  while(i<=mid&&j<=ub)
  {
      if(a[i]<=a[j])
      {
         b[k]=a[i];
         i++;
      }
      else
      {
          b[k]=a[j];
          j++;
      }
      k++;
  }
  if(i>mid)
  {
      while(j<=ub)
      {
          b[k]=a[j];
          k++;          
          j++;
      }
  }
  else
  {
      while(i<=mid)
      {
          b[k]=a[i];
          k++;
          i++;
      }
  }
  for(k=lb;k<=ub;k++)
  {
      a[k]=b[k];
  }
}


void main()
{
    int i,n;
    printf("enter the number of elements \n");
    scanf("%d",&n);
    int a[n];
    printf("enter the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    mergesort(a,0,n-1);
}
