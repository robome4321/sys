#include<stdio.h>
#include<stdlib.h>
int count=0;

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

unsigned int getLeafCount(struct node* ptr)  
{  
    if(ptr==NULL)
    return count;
    
    getLeafCount(ptr->left);
    getLeafCount(ptr->right); 
    count++;
    return count;
}  
  
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
    
  printf("No of NoDE in  the tree is %d", getLeafCount(root)); 
    
  
  return 0;  
}
