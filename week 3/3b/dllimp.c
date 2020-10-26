#include"dll.h"
int count_nodes(List* dll)
{
	//TODO
    Node* ptr = dll->head;
    int count = 0;

    while(ptr != NULL)
        {
            count = count + 1;
            ptr = ptr->next;
        }
    return(count);
}
    

void insert_front(List* dll, int data)
{
    //TODO
    Node* new_node = create_node(data);

    new_node->next = dll->head;

    if((dll->head)!=NULL)
    {
        (dll->head)->prev = new_node;
    }

    (dll->head) = new_node;
    dll->number_of_nodes = dll->number_of_nodes + 1;
}


void dllist_delete_beginning(List* list)
{
    //TODO
    Node* ptr;
    if((list->head)==NULL)
    {
        return;
    }

    if((list->head)->next == NULL)
    {
        (list->head) = NULL;
        free((list->head));
        return;
    }
    else
    {
        ptr = list->head;
        (list->head) = (list->head)->next;
        (list->head)->prev = NULL;
        free(ptr);
    }
    
}


void position_delete(List* dll, int pos)
{
    //TODO
    if((dll->head) == NULL)
        return;
    
    Node* temp = dll->head;

    if(pos == 0)
    {
        dllist_delete_beginning(dll);
        return;
    }

    for(int i=0; temp!=NULL && i<pos-1;i++)
    {
        temp = temp->next;
    }

    if(temp==NULL || temp->next == NULL)
    {
        return;
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int search_list(List* dll,int key)
{
    //TODO
    int flag = 0,position = 0;
    if(dll->head == 0)
        return -1;
    else
    {
        Node* temp = dll->head;

        while(temp != NULL)
        {
            if(temp->data == key)
            {
                flag = 1;
                return position;
            }
            position = position + 1;
            temp = temp->next;
        }
    }
    
    if(flag == 0)
        return -1;
}


void reverse_list(List* dll)
{
    //TODO
    Node* temp = NULL;
    Node* curr = (dll->head);

    while(curr!=NULL)
    {
        temp = curr->prev;
        curr->prev= curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp!=NULL)
    {
        (dll->head) = temp->prev;
    }
}


