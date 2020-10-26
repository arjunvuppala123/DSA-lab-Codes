#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    if(pos > cll->length+1 || pos < 0)
    {
        return;
    }
    Node *new_node = create_node(data);
    if(cll->head == NULL && pos == 0)//first element
    {
        new_node->data = data;
        new_node->next = new_node;
        cll->length = 1;
        cll->head = new_node;
        cll->tail = new_node;
        return;
    }
    if(pos == 0)//0 in index element
    {
        new_node->next = cll->head;
        cll->head = new_node;
        cll->tail->next = new_node;
        cll->length ++;
        return;
    }
    int i = 1;
    Node *temp = cll->head;
    if(pos == cll->length && temp->next == cll->head )
    {
        new_node->next = cll->head;
        temp->next = new_node;
        cll->tail = new_node;
        cll->length++;
        return;
    }
    while(temp->next != cll->head)
    {
        if(pos == i)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            cll->length++;
            
            return;
        }
        i++;
        temp = temp->next;
        if(pos == cll->length && temp == cll->tail)
        {
            new_node->next = cll->head;
            temp->next = new_node;
            cll->tail = new_node;
            cll->length++;
            return;
        }
        if(pos == cll->length-1 && temp->next == cll->tail)
        {
            new_node->next = cll->tail;
            temp->next = new_node;
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
    Node *cur = cll->head;
    if(pos == 0)
    {
        
        if(cll->length == 1)
        {
            cll->head = NULL;
            cll->tail = NULL;
        }
        else
        {
            cll->head = cur->next;
            cll->tail->next = cll->head;
        }
        free(cur);  
        cll->length--;
        return;
    }
    Node *next_node = cur->next;
    int i = 0;
    while(cur->next != cll->tail)
    {
        if(pos == ++i)
        {
            cur->next = next_node->next;
            cll->length--;
            free(next_node);
            return;
        }
        cur = cur->next;
        next_node = next_node->next;
    }
    if(pos == cll->length-1 && next_node == cll->tail)
    {
        cur->next = cll->head;
        cll->tail = cur;
        cll->length--;
        free(next_node);
        return;
    }

}

int josephus(List* cll, int k)
{
    if(cll->length == 0)
    {
        return -1;
    }
    int i = 1;
    Node * cur = cll->head;
    Node * next_node = cur->next;
    while(i != k+1 )
    {
        cur = cur->next;
        next_node = next_node->next;
        i++;
    }
    while(next_node != cur)
    {
        cur->next = next_node->next;
        free(next_node); 
        cll->length --;
        cur = cur->next;
        next_node = cur->next;  
        
    }
    cll->head = next_node;
    cll->tail = next_node;
    return next_node->data;
}


