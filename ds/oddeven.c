#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a=2,b,c;
  struct node
  {
    int data;
    struct node* next;
  };
  struct node* ptr;
  struct node* optr;
  struct node* eptr;
  struct node* header = (struct node*)malloc(sizeof(struct node));
  struct node* oddheader = (struct node*)malloc(sizeof(struct node));
  struct node* evenheader = (struct node*)malloc(sizeof(struct node));
  printf("enter 1 number  to insert\n");
  printf("enter 0 to stop insertion\n");
  if(header==NULL)
  {
    printf("no memory available\n");
    return 0;
  }
  else
  {
    ptr=header;
    header->next=NULL;
    
  while(a!=0)
  {
    scanf("%d",&a);
    if (a==1)
    {
      scanf("%d",&b);
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      ptr->next=newnode;
      newnode->data=b;
      newnode->next=NULL;
      ptr=newnode;
    }
  }
  
    optr=oddheader;
    oddheader->next=NULL;
    eptr=evenheader;
    evenheader->next=NULL;
    ptr=header->next;
  
  while(ptr!= NULL)
  {
    struct node* newnode1 = (struct node*)malloc(sizeof(struct node));
    optr->next=newnode1;
    newnode1->data=ptr->data;
    newnode1->next=NULL;
    optr=newnode1;
    ptr=ptr->next;
    struct node* newnode2 = (struct node*)malloc(sizeof(struct node));
    eptr->next=newnode2;
    newnode2->data=ptr->data;
    newnode2->next=NULL;
    eptr=newnode2;
    ptr=ptr->next;
  }
  
  printf("original linked list\n");
      if(header->next==NULL)
      {
        printf("empty\n");
      }
      else
      {
        ptr=header->next;
        while(ptr->next!=NULL)
        {
          printf("%d->",ptr->data);
          ptr=ptr->next;
        }
        printf("%d->NULL\n",ptr->data);
      }
  printf("odd linked list\n");   
   if(oddheader->next==NULL)
      {
        printf("empty\n");
      }
      else
      {
        optr=oddheader->next;
        while(optr->next!=NULL)
        {
          printf("%d->",optr->data);
          optr=optr->next;
        }
        printf("%d->NULL\n",optr->data);
      }

  printf("even linked list\n");   
   if(evenheader->next==NULL)
      {
        printf("empty\n");
      }
      else
      {
        eptr=evenheader->next;
        while(eptr->next!=NULL)
        {
          printf("%d->",eptr->data);
          eptr=eptr->next;
        }
        printf("%d->NULL\n",eptr->data);
      }
  }
  return 0;
}
