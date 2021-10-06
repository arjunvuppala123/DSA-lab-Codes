#include "heap.h"

void heapify(heap*);

heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}

void heap_destruct(heap* tmp){
    heap *temp=tmp;
    tmp=NULL;
    free(temp);
}

int heap_get_capacity(heap* tmp){
    return tmp->capacity;
}

int heap_get_size(heap* tmp){
    return tmp->size;
}

int heap_insert(heap* tmp,int data){
    if (tmp->size == tmp->capacity) {
        return 0;
    }
    tmp->size++;
    tmp->elements[tmp->size - 1] = data;
 
    int curr = tmp->size - 1;
    while (curr > 0 && tmp->elements[(curr - 1) / 2] > tmp->elements[curr]) {
        int temp = tmp->elements[(curr - 1) / 2];
        tmp->elements[(curr - 1) / 2] = tmp->elements[curr];
        tmp->elements[curr] = temp;
        curr = ((curr - 1) / 2);
    }
    return 1; 
}

int heap_get_min(heap* tmp){
 	return tmp->elements[0];
}

void heap_remove(heap* tmp){
    if(tmp->size==0)return ;
    tmp->elements[0]=tmp->elements[tmp->size-- - 1];
    heapify(tmp);
}

void heapify(heap *tmp){
    if(tmp->size==0)
	return ;
    int i,j,k,key;
    for(k=1;k<tmp->size;k++){
        i=k;
        key=tmp->elements[i];
        j=(i-1)/2;
        while(i>0 && key<tmp->elements[j]){
            tmp->elements[i]=tmp->elements[j];
            i=j;
            j=(i-1)/2;
        }
        tmp->elements[i]=key;
    }
}
