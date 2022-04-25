#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a=0,b,c;
  struct node
  {
    int data;
    struct node* next;
  };
  struct node* ptr;
  struct node* previous;
  struct node* header = (struct node*)malloc(sizeof(struct node));
  if(header==NULL)
  {
    printf("no memory available\n");
    return 0;
  }
  else
  {
    ptr=header;
    header->next=NULL;
    
  while(a!=8)
  {
    scanf("%d",&a);
    if(a==1)
    {
      scanf("%d",&b);
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      if(header->next == NULL)
      {
        header->next=newnode;
        newnode->data=b;
        newnode->next=NULL;
      }
      else
      {
        newnode->next=header->next;
        newnode->data=b;
        header->next=newnode;
      }
    }
    else if (a==2)
    {
      scanf("%d",&b);
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      ptr->next=newnode;
      newnode->data=b;
      newnode->next=NULL;
    }
    else if(a==3)
    {
      scanf("%d",&b);
      scanf("%d",&c);
      if(header->next == NULL)
      {
        printf("list is empty\n");
      }
      else
      {
        ptr=header->next;
        while(ptr->next!=NULL&&ptr->data!=c)
        {
          ptr=ptr->next;
        }
        if(ptr->data==c)
        {
           struct node* newnode = (struct node*)malloc(sizeof(struct node));
           newnode->data=b;
           previous=ptr;
           ptr=ptr->next;
           previous->next=newnode;
           newnode->next=ptr;
        }
        else
        {
          printf("not found\n");
        }
      }
    }
    else if(a==4)
    {
      if(header->next==NULL)
      {
        printf("empty\n");
      }
      else
      {
        ptr=header->next;
        header->next=ptr->next;
        free(ptr);
      }  
    }
    else if (a==5)
    {
      if(header->next==NULL)
      {
        printf("empty\n");
      }
      else
      {
        ptr=header->next;
        while(ptr->next!=NULL)
        {
          previous=ptr;
          ptr=ptr->next;
        }
        previous->next=NULL;
        free(ptr);
      }
    }
    else if(a==6)
    {
      scanf("%d",&c);
      if(header->next==NULL)
      {
        printf("empty\n");
      }
      else
      {
        ptr=header->next;
        while(ptr->next!=NULL&&ptr->data!=c)
        {
          previous=ptr;
          ptr=ptr->next;
        }
        if(ptr->data==c)
        {
          previous->next=ptr->next;
          free(ptr);
        }
        else
        {
          printf("not found\n");
        }
      }
    }
    else if(a==7)
    {
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
    }
  }
  }
  return 0;
}
