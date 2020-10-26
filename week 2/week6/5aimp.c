#include "5a.h"

static Node* create_Node(int data, Node* link)
 {
// TODO - create and allocate dynamic space
    printf("OK1");
    link = (Node*)malloc(sizeof(Node));
    printf("\nOK2");
    link->data = data;
    printf("\nOK3");
    link->link = NULL;
    printf("\nOK4");
    return link;
 }

void list_initialize(List* ptr_list) 
{
//TODO - initialize structure members to default values
    ptr_list = (List*)malloc(sizeof(List));
    printf("\nOK5");
    ptr_list->head = NULL;
    printf("\nOK6");
    ptr_list->number_of_Nodes = 0;
    printf("\nOK7");
}

void list_insert_front(List* ptr_list, int data) 
{
//TODO - perform linked list implementation of push operation.
    printf("\nOK8");
    Node *new_node ;
    printf("\nOK8");
    create_Node(data,new_node);
    printf("\nOK8");
    	if (new_node == NULL) { 
		printf("Stack overflow n"); 
        return;
	} 
    new_node->link = ptr_list->head;
    printf("\nOK9");
    ptr_list->head = new_node;
    printf("\nOK10");
    ptr_list->number_of_Nodes = ptr_list->number_of_Nodes + 1;
    printf("%d %d",ptr_list->number_of_Nodes,ptr_list->head->data);
    printf("\nOK11");
}


const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element
    int i ;
    Node* temp = Node_ptr;
    while(temp->link!=NULL)
    {
        temp = temp->link;
    }
    return(temp->data);
}


void list_delete_front(List* ptr_list) 
{
//TODO - perform linked list implementation of pop operation.
    if(ptr_list->head==NULL)
    {
        return ;
    }

    Node* temp = ptr_list->head;
    ptr_list->head = ptr_list->head->link;
    free(temp);
}


void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
    Node *p = ptr_list->head;
	Node *q = NULL;
	for(int i=0;i<ptr_list->number_of_Nodes;i++)
    	{
		q = p;
		p = p->link;
		free(q);
	}
	
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
    ptr_Stack = (Stack*)malloc(sizeof(Stack));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
    list_insert_front(ptr_Stack->ptr_list,key);
    printf("lol1");

}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
    if(ptr_Stack->ptr_list == NULL)
        return 1;
    
    else 
        return 0;
}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack      
    Node *temp = ptr_Stack->ptr_list->head;
    int top = Node_get_data(temp);
    return top;
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
    list_destroy(ptr_Stack->ptr_list);
}

int isMatchingPair(char char1, char char2)
{
    if( (char1=='{') && (char2=='}') )
    {
        return 1;
    }
    else if((char1=='(') && (char2==')'))
    {
        return 1;
    }
    else if((char1=='[') && (char2==']'))
    {
        return 1;
    }
    else
		return 0;
}

int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
    int i = 0;
    Stack *stack; 
    Stack_initialize(stack);
    while(string[i])
    {  
        if(string[i] == '{' || string[i] == '(' || string[i] == '[')
        {
            Stack_push(stack, string[i]); 
        }
        if (string[i] == '}' || string[i] == ')' || string[i] == ']') { 

			if (stack == NULL) 
				return 0; 

			else 
            {
                Stack_pop(stack);
                if (!isMatchingPair(Stack_peek(stack), string[i])) 
				return 0; 
            }
		} 
		i++; 
	}
    if (stack == NULL) 
		return 1; 
	else
		return 0; 
    Stack_destroy(stack);
}
	


 

