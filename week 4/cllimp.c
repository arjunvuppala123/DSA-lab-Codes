#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    if(pos > cll->length+1 || pos < 0)
    {
        return;
    }
    Node *new_Node = create_node(data);
    if(cll->head == NULL && pos == 0)//first element
    {
        new_Node->data = data;
        new_Node->next = new_Node;
        cll->length = 1;
        cll->head = new_Node;
        cll->tail = new_Node;
        return;
    }
    if(pos == 0)//0 in index element
    {
        new_Node->next = cll->head;
        cll->head = new_Node;
        cll->tail->next = new_Node;
        cll->length = cll->length + 1;
        return;
    }
    int i = 1;
    Node *temp = cll->head;
    if(pos == cll->length && temp->next == cll->head )
    {
        new_Node->next = cll->head;
        temp->next = new_Node;
        cll->tail = new_Node;
        cll->length = cll->length + 1;
        return;
    }
    while(temp->next != cll->head)
    {
        if(pos == i)
        {
            new_Node->next = temp->next;
            temp->next = new_Node;
            cll->length++;
            return;
        }
        i++;
        temp = temp->next;
        if(pos == cll->length && temp == cll->tail)
        {
            new_Node->next = cll->head;
            temp->next = new_Node;
            cll->tail = new_Node;
            cll->length++;
            return;
        }
        if(pos == cll->length-1 && temp->next == cll->tail)
        {
            new_Node->next = cll->tail;
            temp->next = new_Node;
            cll->length++;
            return;
        }  
    }
}

void position_delete(List* cll, int pos)
{
    if(cll->length <= 0 || pos > cll->length-1)
    {
        return;
    }
    Node *curr = cll->head;
    if(pos == 0)
    {
        
        if(cll->length == 1)
        {
            cll->head = NULL;
            cll->tail = NULL;
        }
        else
        {
            cll->head = curr->next;
            cll->tail->next = cll->head;
        }
        free(curr);  
        cll->length--;
        return;
    }
    Node *next = curr->next;
    int i = 0;
    while(curr->next != cll->tail)
    {
        if(pos == ++i)
        {
            curr->next = next->next;
            cll->length--;
            free(next);
            return;
        }
        curr = curr->next;
        next = next->next;
    }
    if(pos == cll->length-1 && next == cll->tail)
    {
        curr->next = cll->head;
        cll->tail = curr;
        cll->length--;
        free(next);
        return;
    }

}


int josephus(List* cll, int k)
{
//TODO 
    if(cll->length == 0)
    {
        return -1;
    }
    int i = 1;
    Node *curr = cll->head;
    Node *next = curr->next;
    while( i != k+1 )
    {
        curr = curr->next;
        next = next->next;
        i++;
    }
    while(next != curr)
    {
        curr->next = next->next;
        free(next); 
        cll->length--;
        curr = curr->next;
        next = curr->next;  
        
    }
    cll->head = next;
    cll->tail = next;
    return (next->data);
}


