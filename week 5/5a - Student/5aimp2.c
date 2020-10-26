#include "5a.h"

static Node* create_Node(int data, Node* link)
 {
    Node* new_node =(Node*) malloc(sizeof(Node));
    if(new_node == NULL)
    {
        return NULL;
    }
    new_node->data = data;
    new_node->link = link;
    return new_node;
}

void list_initialize(List* ptr_list) 
{
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = 0;
}


void list_insert_front(List* ptr_list, int data) 
{
//TODO - push operation.
    Node* new_node =create_Node(data,ptr_list->head);
    if(ptr_list->head == NULL)
    {
        ptr_list->head = new_node;
        ptr_list->number_of_Nodes ++;
        return;
    }
  //  new_node->link = ptr_list->head;
    ptr_list->head = new_node;
    ptr_list->number_of_Nodes ++;
}


const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element
    if(Node_ptr->link == NULL)
    {
        return -1;
    }
    return Node_ptr->data;
}


void list_delete_front(List* ptr_list) 
{
//TODO -pop operation.
    if(ptr_list->head == NULL)
    {
        return;
    }
    Node *temp_node = ptr_list->head;
    if(temp_node->link == NULL)
    {
        ptr_list->number_of_Nodes --;
        ptr_list->head = NULL;
        return;
    }
    ptr_list->number_of_Nodes --;
    ptr_list->head = ptr_list->head->link;
    free(temp_node);
}


void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
    Node *temp_node = ptr_list->head;
    Node *dest = NULL;
    while(temp_node != NULL)
    {
        dest = temp_node;
        free(dest);
        dest = dest->link;
    }
    ptr_list->head = NULL;
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
    list_initialize(ptr_Stack->ptr_list);

}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
    if (ptr_Stack->ptr_list->head == NULL)
    {
        list_insert_front(ptr_Stack->ptr_list,key);
        return;
    }
    if ((Stack_peek(ptr_Stack) == '{' && key == '}') || (Stack_peek(ptr_Stack) == '(' && key == ')') || (Stack_peek(ptr_Stack) == '[' && key == ']'))
    {
        Stack_pop(ptr_Stack);
    }
    else// if(key != 41 || key != 93 ||key != 125 )
    {
        list_insert_front(ptr_Stack->ptr_list,key);
    }
    
}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
     if(ptr_Stack->ptr_list->number_of_Nodes > 0)
    {
        return 0;
    }
    return 1;
}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack
    if(ptr_Stack->ptr_list->head == NULL)
    {
        return 0;
    }
    return ptr_Stack->ptr_list->head->data;
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
    list_destroy(ptr_Stack->ptr_list);
}

int match_parenthesis(const char* string)
{
    int i;
    Stack *stk;
    char ch;
    stk = malloc(sizeof(stk));
    stk->ptr_list = (List *)malloc(sizeof(List));
    Stack_initialize(stk);
    i = 0;
    ch = string[i];
    while(ch != '\0')
    {    
        
        if(ch == '{' || ch == '[' || ch == '(' || ch == ')' || ch == ']' || ch == '}')
        {
            //printf("loop %c\t",ch);
            Stack_push(stk,(int)ch);
            //printf("%d\n",i);
        }
        ch = string[++i];
    }
    if(Stack_is_empty(stk))
    {
        Stack_destroy(stk); 
        return 1;
        
    }
    else
    {
        return 0;
    }
       
    
}	


 

