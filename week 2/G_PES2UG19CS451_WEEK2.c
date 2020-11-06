#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	//TODO
	Node* new_Node = (Node*)malloc(sizeof(Node));
	Node* temp = list->head;

	new_Node->data = data;
	new_Node->link = NULL;

	if (temp==NULL)
	{
		list->head = new_Node; 
		return;
	}

	while (temp->link!=NULL)
	{
		temp = temp->link;
	}

	temp->link = new_Node;
}

void list_delete_front(List* list) {
	if(list->head == NULL)
	{
		printf("Empty list");
		return;

	}
	Node* temp = list->head;
	list->head = list->head->link;
	free(temp);
}

void list_insert_at (List *list, int data, int position)
{
	//TODO
	int pos = 1;
	Node* temp = list->head;

	Node* new_Node = (Node*)malloc(sizeof(Node));

	new_Node->data = data;
	new_Node->link = NULL;

	if (list->head==NULL)
	{
		temp = new_Node;
		return;
	}

	if (position == 0) {
       new_Node->link = list->head;
	   list->head = new_Node;
       return ;
    }

	while(temp!=NULL)
	{
		if(pos == position)
		{
			new_Node->link = temp->link;
			temp->link = new_Node;
			return;
		}
		temp = temp->link;
		pos = pos + 1;
	}
}

void list_reverse(List* list)
{
 	//TODO
	Node* prev = NULL; 
    Node* current = list->head; 
    Node* next = NULL; 
    while (current != NULL) { 
        next = current->link; 

        current->link = prev; 

        prev = current; 
        current = next; 
    } 
    list->head = prev; 
}


