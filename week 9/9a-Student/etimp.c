#include "et.h"

Node * createExpressionTree(char* a,int len)
{
    //TODO
    char ch;
    Node *stack[100];

    int top=-1;
    int i=0;
    
    Node *temp_node;
    
    while(a[i]!='\0')
    {
      ch=a[i];
      temp_node=(Node *)(malloc(sizeof(Node)));    
      temp_node->left=temp_node->right=NULL;
      temp_node->data = ch;  
      if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
      {
        temp_node->right=stack[top];
        top--;
        temp_node->left=stack[top];
        top--;
        if(top<len){
          temp_node->data = a[i];
          stack[++top] = temp_node;
          }
      }    

    else{
        if(top < len){
          top = top + 1;
          stack[top] = temp_node;
        }
    }
      i++;     
    }
    return(stack[top]);
}


void inorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
  if(root != NULL)
  {
    inorder(root->left);
    printf("%c",root->data); 
    inorder(root->right);
  }
}

void preorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
    if(root != NULL)
  {
    printf("%c",root->data);
    preorder(root->left); 
    preorder(root->right);
  }
}

void postorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root != NULL)
    {
    postorder(root->left); 
    postorder(root->right);
    printf("%c",root->data);
  } 
}

void freeTree(Node *root)
{
  if(!root)
    return;

  freeTree(root->left);
  freeTree(root->right); 
  
  free(root);
}

