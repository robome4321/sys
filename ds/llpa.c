#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a=1,b=1;
  struct node
  {
    int coef;
    int exp;
    struct node* next;
  };
  struct node* pptr;
  struct node* qptr;
  struct node* rptr;
  struct node* pheader = (struct node*)malloc(sizeof(struct node));
  struct node* qheader = (struct node*)malloc(sizeof(struct node));
  struct node* rheader = (struct node*)malloc(sizeof(struct node));
  if(rheader==NULL)
  {
    printf("no memory available\n");
    return 0;
  }
  else
  {
    pptr=pheader;
    pheader->next=NULL;
    qptr=qheader;
    qheader->next=NULL;
    rptr=rheader;
    rheader->next=NULL;
    
    while(a!=0||b!=0)
    {
      scanf("%d",&a);
      scanf("%d",&b);
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      if(pheader->next == NULL)
      {
        pheader->next=newnode;
        newnode->coef=a;
        newnode->exp=b;
        newnode->next=NULL;
        pptr=newnode;
      }
      else
      {
        pptr->next=newnode;
        newnode->coef=a;
        newnode->exp=b;
        newnode->next=NULL;
        pptr=newnode;
      }
    }
    a=1;b=1;
    while(a!=0||b!=0)
    {
      scanf("%d",&a);
      scanf("%d",&b);
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      if(qheader->next == NULL)
      {
        qheader->next=newnode;
        newnode->coef=a;
        newnode->exp=b;
        newnode->next=NULL;
        qptr=newnode;
      }
      else
      {
        qptr->next=newnode;
        newnode->coef=a;
        newnode->exp=b;
        newnode->next=NULL;
        qptr=newnode;
      }
    } 
  }
  
  //addition starts
  pptr=pheader->next;
  qptr=qheader->next;
  while(pptr!=NULL&&qptr!=NULL)
  {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    rptr->next=newnode;
    rptr=newnode;
    if(pptr->exp==qptr->exp)
    {
      rptr->coef=pptr->coef+qptr->coef;
      rptr->exp=pptr->exp;
      pptr=pptr->next;
      qptr=qptr->next;
    }
    else if(pptr->exp>qptr->exp)
    {
      rptr->coef=pptr->coef;
      rptr->exp=pptr->exp;
      pptr=pptr->next;
    }
    else if(pptr->exp<qptr->exp)
    {
      rptr->coef=qptr->coef;
      rptr->exp=qptr->exp;
      qptr=qptr->next;
    }
  }
  if(pptr==NULL)
  {
    while(qptr!=NULL)
    {
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      rptr->next=newnode;
      rptr=newnode;
      rptr->coef=qptr->coef;
      rptr->exp=qptr->exp;
      qptr=qptr->next;
    }
  }
  else if(qptr==NULL)
  {
    while(pptr!=NULL)
    {
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      rptr->next=newnode;
      rptr=newnode;
      rptr->coef=pptr->coef;
      rptr->exp=pptr->exp;
      pptr=pptr->next;
    }
  }
  
  //result display
  pptr=pheader->next;
  while(pptr->next->next!=NULL)
  {
    printf("%dX^%d+",pptr->coef,pptr->exp);
    pptr=pptr->next;
  }
  if(pptr->exp!=0)
  {
    printf("%dX^%d",pptr->coef,pptr->exp);
  }
  else
  {
    printf("%d",pptr->coef);
  }
  printf("\n");
  
  qptr=qheader->next;
  while(qptr->next->next!=NULL)
  {
    printf("%dX^%d+",qptr->coef,qptr->exp);
    qptr=qptr->next;
  }
  if(qptr->exp!=0)
  {
    printf("%dX^%d",qptr->coef,qptr->exp);
  }
  else
  {
    printf("%d",qptr->coef);
  }
  printf("\n");
  
  rptr=rheader->next;
  while(rptr->next->next!=NULL)
  {
    printf("%dX^%d+",rptr->coef,rptr->exp);
    rptr=rptr->next;
  }
  if(rptr->exp!=0)
  {
    printf("%dX^%d",rptr->coef,rptr->exp);
  }
  else
  {
    printf("%d",rptr->coef);
  }
  return 0;
}
