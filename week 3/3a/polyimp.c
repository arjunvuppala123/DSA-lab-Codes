#include "poly.h"
#include<math.h>
void insert_at_end(List *list, int data) 
{
	//TODO
    Node* new_Node = (Node*)malloc(sizeof(Node));
	Node* temp = list->head;
    list->number_of_nodes = list->number_of_nodes + 1;

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

long long int evaluate(List *list, int x)
{
    //TODO
    long long sum = 0;
    Node* curr = list->head;
    int n = list->number_of_nodes;
    for(int i = 0; i<n && curr!=NULL;i++)
    {
        sum = sum + ((curr->data)*pow(x,i));
        curr = curr->link;

    }
    return sum;
}
