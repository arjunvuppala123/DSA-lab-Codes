#include "6a.h"
#include<ctype.h>
static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO	
	ptr_List->head = NULL;
    ptr_List->number_of_Nodes = 0;
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO	
	Node* new_Node =create_Node(data,ptr_List->head);

    if(ptr_List->head == NULL)
    {
        ptr_List->head = new_Node;
        ptr_List->number_of_Nodes ++;

        return;
    }

    ptr_List->head = new_Node;
    ptr_List->number_of_Nodes ++;
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
	if(Node_ptr->link == NULL)
    {
        return -1;
    }

    return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
	//TODO
	if(ptr_List->head == NULL)
    {
        return;
    }

    Node* temp_Node = ptr_List->head;

    if(temp_Node->link == NULL)
    {
        ptr_List->number_of_Nodes --;
        ptr_List->head = NULL;
        return;
    }

    ptr_List->number_of_Nodes --;
    ptr_List->head = ptr_List->head->link;

    free(temp_Node);
}

void List_destroy(List* ptr_List) 
{
	//TODO
    Node *P = ptr_List->head;
    Node *Q = NULL;

    while(P != NULL)
    {
        Q = P;
        free(Q);
        Q = Q->link;
    }
    
    ptr_List->head = NULL;

}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
    List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
	if(ptr_stack->ptr_List->number_of_Nodes > 0)
    {
        return 0;
    }
    return 1;
}

const int stack_peek(Stack *ptr_stack)
{
	// TODO
    if(ptr_stack->ptr_List->head == NULL)
    {
        return 0;
    }
    return ptr_stack->ptr_List->head->data;	
}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
	List_destroy(ptr_stack->ptr_List);
}

int postfix_eval(const char* expression) 
{
    // TODO
    int i,result;
    Stack* stack ;
    stack_initialize(stack);
    for (i = 0; expression[i]; ++i) 
    { 
        if (isdigit(expression[i])) 
            stack_push(stack, expression[i] - '0'); 
        else
        { 
            int val1 = stack_peek(stack);
            stack_pop(stack); 
            int val2 = stack_peek(stack); 
            stack_pop(stack); 
            switch (expression[i]) 
            { 
            case '+': stack_push(stack, val2 + val1); 
                      break; 
            case '-': stack_push(stack, val2 - val1); 
                      break; 
            case '*': stack_push(stack, val2 * val1); 
                      break; 
            case '/': stack_push(stack, val2/val1); 
                      break; 
            } 
        } 
    } 
    return stack_peek(stack);
} 
