#include <stdio.h>
struct pol
  {  
    int coef;
    int exp;
  }p[20],q[20],r[20];

void display(int n,struct pol x[20])
{
  int s=0;
  while(s<(n-1))
  {
    printf("%d",x[s].coef);
    printf("X");
    printf("^");
    printf("%d",x[s].exp);
    printf("+");
    s++;
  }
  if(x[s].exp==0)
  {
    printf("%d",x[s].coef);
  }
  else
  {
    printf("%d",x[s].coef);
    printf("X");
    printf("^");
    printf("%d",x[s].exp);
  }
  
 printf("\n");
 
}

void main()
{
  int n1,n2,l;
  int i=0,j=0,k=0;
  //printf("enter the number of terms of first polynomial\n");
  scanf("%d",&n1);
 // printf("enter the number of terms of second polynomial\n");
  scanf("%d",&n2);
 // printf("enter first polynomial\n");
  for(l=0;l<n1;l++)
  {
   // printf("enter coefficient of term %d ",l+1);
    scanf("%d",&p[l].coef);
   // printf("enter exponent of term %d ",l+1);
    scanf("%d",&p[l].exp);
  }
  //printf("enter second polynomial\n");
  for(l=0;l<n2;l++)
  {
   // printf("enter coefficient of term %d ",l+1);
    scanf("%d",&q[l].coef);
   // printf("enter exponent of term %d ",l+1);
    scanf("%d",&q[l].exp);
  }
  
  while(i<n1&&j<n2)
  {
  if(p[i].exp==q[j].exp)
  {
    r[k].exp=p[i].exp;
    r[k].coef=p[i].coef+q[j].coef;
    i++;
    j++;
    k++;
  }
  else if(p[i].exp>q[j].exp)
  {
    r[k].exp=p[i].exp;
    r[k].coef=p[i].coef;
    i++;
    k++;
  }
  else if(p[i].exp<q[j].exp)
  {
    r[k].exp=q[j].exp;
    r[k].coef=q[j].coef;
    j++;
    k++;
  }
  }
  if(i<n1)
  {
    while(i<n1)
    {
      r[k].exp=p[i].exp;
      r[k].coef=p[i].coef;
      i++;
      k++;
    }
  }
  else if(j<n2)
  {
    while(j<n2)
    {
      r[k].exp=q[j].exp;
      r[k].coef=q[j].coef;
      j++;
      k++;
    }
  }
  display(n1,p);
  display(n2,q);
  display((k),r);
}
