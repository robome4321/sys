#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* root=NULL;

void insert(struct node* r,int i)
{
  if(root==NULL)
  {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    root=newnode;
    root->data=i;
    root->left=NULL;
    root->right=NULL;
  }
  else
  {
    if(r==NULL)
    {
      struct node* newnode=(struct node*)malloc(sizeof(struct node));
      r=newnode;
      r->data=i;
      r->left=NULL;
      r->right=NULL;
    }
    else
    {
      if(i<=r->data)  
      {
        insert(r->left,i);
      }
      else
      {
        insert(r->left,i); 
      }
    }
  }  
    
}

void Postorder(struct node* node) 
{ 
     if (node == NULL) 
   {
    return; 
   } 
     Postorder(node->left); 
     Postorder(node->right); 
     printf("%d ", node->data); 
} 
  

void Inorder(struct node* node) 
{ 
     if (node == NULL)
   {
    return; 
   }
     Inorder(node->left); 
     printf("%d ", node->data);   
     Inorder(node->right); 
} 
  
void Preorder(struct node* node) 
{ 
     if (node == NULL) 
   {
    return; 
   }
     printf("%d ", node->data);   
     Preorder(node->left); 
     Preorder(node->right);
}

void main()
{
  int a;
  while(a!=0)
  {
    printf("enter integer");
    scanf("%d",&a);
    if(root==NULL)
    {
      insert(root,a);
    }
    else
    {
      insert(root,a);
    }
    
  }
  Postorder(root);
  Postorder(root);
  Inorder(root);
}
