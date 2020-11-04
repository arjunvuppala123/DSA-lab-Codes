#include<stdio.h>

#include "bst.h"

void tree_initialize(Tree * tree) {
  //TODO  
  tree->root = NULL;
}

void tree_insert(Tree * tree, int data) {
  // TODO : Insert element to create a BST
  Node *tempNode = (Node*) malloc(sizeof(Node));
  Node *current;
  Node *parent;

  tempNode->data = data;
  tempNode->left = NULL;
  tempNode->right = NULL;


   //if tree is empty
  if(tree->root == NULL) {
    tree->root = tempNode;
    return;
  } else {
    current = tree->root;
    parent = NULL;

    while(1) {                
        parent = current;
			
        if(data < parent->data) {
            current = current->left;  
				
            if(current == NULL) {
               parent->left = tempNode;
               return;
            }
         }  //go to right of the tree
         else {
            current = current->right;
            
            //insert to the right
            if(current == NULL) {
               parent->right = tempNode;
               return;
            }
         }
      }            
   }
}

void tree_delete(Tree *tree, int element) {
  // TODO : Delete elements from BST  
  Node *curr, *temp, *prev, *p, *q;
  prev = NULL;
  curr = tree->root;
  while ((curr != NULL) && (curr -> data != element)) {
    prev = curr;
    if (element < curr -> data)
      curr = curr -> left;
    else
      curr = curr -> right;
  }
  if (curr == NULL) {
    return;
  }
  if ((curr -> left == NULL) || (curr -> right == NULL)) {
    if (curr -> left == NULL){
      q = curr -> right;
    }
    else{
      q = curr -> left;
    }

    if (prev == NULL) {

      free(curr);
      return;

    }
    if (curr == prev -> left)
      prev->left = q;
    else
      prev->right = q;
    free(curr);
  } 
  else {

    p = NULL;
    temp = curr->right;
    while (temp->left != NULL) {

      p = temp;
      temp = temp->left;

    }
    curr->data = temp->data;

    if (p != NULL)
      p->left = temp->right;
    else
      curr->right = temp->right;
    free(temp);
  }
}

void tree_inorder(Node * r) {
  //TODO :  use printf to print inorder 
  if (r != NULL) {
    tree_inorder(r->left);
    printf("%d ", r->data);
    tree_inorder(r->right);
  }
}

void tree_preorder(Node * r) {
  //TODO :  use printf to print preorder
  if (r != NULL) {
    printf("%d ", r -> data);
    tree_preorder(r -> left);
    tree_preorder(r -> right);
  }
}

void tree_postorder(Node * r) {
  //TODO :  use printf to print postorder
  if (r != NULL) {
    tree_postorder(r -> left);
    tree_postorder(r -> right);
    printf("%d ", r -> data);
  }
}

void postorder(Tree * t) {
  //TODO
  tree_postorder(t -> root);
}

void preorder(Tree * t) {
  //TODO
  tree_preorder(t -> root);
}

void inorder(Tree * t) {
  //TODO   
  tree_inorder(t->root);
}

void destroy(Node * r) {
  //TODO  
    if (r == NULL) 
      return; 
  
    destroy(r->left); 
    destroy(r->right); 

    free(r); 
}

void tree_destroy(Tree * t) {
  //TODO    
  destroy(t->root);
}