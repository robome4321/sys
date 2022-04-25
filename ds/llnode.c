#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
struct node* insert(struct node* ptr,int key)
{
if(ptr==NULL)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=key;
newnode->right=NULL;
newnode->left=NULL;
ptr=newnode;
}
if(key < ptr->data)
ptr->left=insert(ptr->left,key);
else if(key > ptr->data)
ptr->right=insert(ptr->right,key);
return ptr;
}
void preorder(struct node* ptr)
{
if(ptr==NULL)
return;
printf("%d ",ptr->data);
preorder(ptr->left);
preorder(ptr->right);
}
void inorder(struct node* ptr)
{
if(ptr==NULL)
return;
inorder(ptr->left);
printf("%d ",ptr->data);
inorder(ptr->right);
}
void postorder(struct node* ptr)
{
if(ptr==NULL)
return;
postorder(ptr->left);
postorder(ptr->right);
printf("%d ",ptr->data);
}
struct node* successor_node(struct node* current)
{
current=current->right;
while(current->left != NULL)
current = current->left;
return current;
}
struct node* search(struct node* current,int key)
{
struct node* parent=NULL;
while(current!=NULL && current->data!=key)
{parent=current;
if(key < current->data)
current=current->left;
else
current=current->right;
}
return parent;
}
struct node* delete(struct node* root,int key)
{
struct node* parent=NULL;
struct node* current=root;
int found=0;
while(current!=NULL)
{
if(key==current->data)
{found=1;
break;
}
else if(key<current->data)
{
parent=current;
current=current->left;
}
else
{
parent=current;
current=current->right;
}}
if(found==0)
{
printf("not found %d\n",key);
return root;
}
else
{
if(current->left==NULL && current->right==NULL)
{
if(current==parent->left)
parent->left=NULL;
else
parent->right=NULL;
}
else if(current->left!=NULL && current->right!=NULL)
{
struct node* successor=successor_node(current);
int item=successor->data;
delete(root,item);
current->data=item;
}
else
{
if(current==parent->left)
{
if(current->left==NULL)
parent->left=current->right;
else
parent->left=current->left;
}
if(current==parent->right)
{
if(current->left==NULL)
parent->right=current->right;
else
parent->right=current->left;
}
}}}
int main()
{
int key=1;
struct node *root=NULL;
printf("enter the elements to be inserted\n");
while(key!=0)
{
scanf("%d",&key);
if(root==NULL)
root=insert(root,key);
else if(key!=0)
insert(root,key);
}
void display()
{
preorder(root);
printf("\n");
inorder(root);
printf("\n");
postorder(root);
}
display();
key=1;
printf("\nenter the elements to be deleted\n");
while(key!=0)
{
scanf("%d",&key);
if(key!=0)
delete(root,key);
}
display();
}
