#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
	link = (node*)malloc(sizeof(node));
	link->id = id;
	link->link = NULL;
	link->time = time;
}
void list_initialize(List *ptr_list)
{
//TODO
	ptr_list = (List*)malloc(sizeof(List));
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
	ptr_list->number_of_nodes = 0;
}
const int node_get_id(node *node_ptr)
{
//TODO	
	return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
//TODO		
	return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO	
	node* temp = create_node(id,time,temp);
	if (ptr_list->tail == NULL) { 
        ptr_list->head = ptr_list->tail = temp; 
		ptr_list->number_of_nodes = ptr_list->number_of_nodes + 1;
        return; 
    } 
  
    ptr_list->tail->link = temp; 
    ptr_list->tail = temp; 
	ptr_list->number_of_nodes = ptr_list->number_of_nodes + 1;
}

void list_delete_front(List *ptr_list)
{
//TODO	
    if (ptr_list->head == NULL) 
        return; 
   
    node* temp = ptr_list->head; 
  
    ptr_list->head = ptr_list->head->link; 
  
    if (ptr_list->head == NULL) 
        ptr_list->tail = NULL; 
  
    free(temp); 
}

void list_destroy(List *ptr_list)
{
//TODO	
    node *P = ptr_list->head;
    node *Q = NULL;

    while(P != NULL)
    {
        Q = P;
	Q= NULL;
        free(Q);
	ptr_list->number_of_nodes = ptr_list->number_of_nodes -1;
        Q = Q->link;
    }
    
    ptr_list->head = NULL;
}

void queue_initialize(Queue *queue_list)
{
//TODO	
	list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO	
	list_insert_rear(ptr->ptr_list,id,time);
}

void queue_dequeue(Queue *ptr)
{
//TODO	
	list_delete_front(ptr->ptr_list);	
}

int queue_is_empty(Queue *ptr)
{
//TODO	
	return ptr->ptr_list->number_of_nodes == 0;	
}

void queue_peek(Queue *ptr)
{
//TODO	
	int id = node_get_id(ptr->ptr_list->head);
	int time = node_get_time(ptr->ptr_list->head);
	printf("%d %d",id,time);	
}

void queue_destroy(Queue *ptr)
{
//TODO		
	list_destroy(ptr->ptr_list);
	ptr=NULL;
	free(ptr);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO		
	node* temp = ptr_queue->ptr_list->head;
	int f = 0,sum = 0;
	while (temp != NULL) {
 		 if (sum + temp->time > t) {
   				 f = 1;
   				 break;
  			}
 		   	sum = sum + temp->time;
			temp = temp->link;
		}

	if (f != 0) 
	{
		printf("%d",temp->id);
		return temp->id;
	}
	else 
		return -1;
}
