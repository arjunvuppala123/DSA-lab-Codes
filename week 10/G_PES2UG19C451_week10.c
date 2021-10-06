#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    //TODO 
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    //TODO
    Node *ptr = tree->root; 
    Node *par = NULL; 
    while (ptr != NULL) 
    { 
        if (data == (ptr->data)) 
        { 
            return; 
        } 
  
        par = ptr;  
  
        if (data < ptr->data) 
        { 
            if (ptr -> leftThread == 0) 
                ptr = ptr -> left; 
            else
                break; 
        } 
  
        // Moving on right subtree. 
        else
        { 
            if (ptr->rightThread == 0) 
                ptr = ptr -> right; 
            else
                break; 
        } 
    } 
  
    // Create a new node 
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp -> data = data; 
    tmp -> leftThread = 1; 
    tmp -> rightThread = 1; 
  
    if (par == NULL) 
    { 
        tree->root = tmp; 
        tmp -> left = NULL; 
        tmp -> right = NULL; 
    } 
    else if (data < (par -> data)) 
    { 
        tmp -> left = par -> left; 
        tmp -> right = par; 
        par -> leftThread = 0; 
        par -> left = tmp; 
    } 
    else
    { 
        tmp -> left = par; 
        tmp -> right = par -> right; 
        par -> rightThread = 0; 
        par -> right = tmp; 
    } 
}

Node *inorder_predecessor(Node *ptr)
{
   //TODO
   if(ptr == NULL){
       return NULL;
   }
   if (ptr -> leftThread == 0) 
        return ptr->left; 
  
    ptr = ptr -> left; 
    while (ptr -> rightThread == 1) 
        ptr = ptr -> right; 
    return ptr; 
}

Node *inorder_successor(Node *ptr)
{
   //TODO    
   if (ptr -> rightThread == 1) 
        return ptr->right; 
  
    ptr = ptr -> right; 
    while (ptr -> leftThread == 0) 
        ptr = ptr -> left; 
    return ptr; 
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *ptr = tree->root; 
    while (ptr -> leftThread == 0) 
        ptr = ptr -> left; 

    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> data); 
        ptr = inorder_successor(ptr); 
    } 
    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *ptr = tree->root; 
    while (ptr -> rightThread == 0) 
        ptr = ptr -> right; 

    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> data); 
        ptr = inorder_predecessor(ptr); 
    } 
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    //TODO
    if(r==NULL) 
        return;
    free(r);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
