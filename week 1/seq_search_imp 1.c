//Implementation for session1_seq_search.h
#include<stdio.h>
#include "ss.h"
//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
int seqsearch(int *arr, int n, int key) 
	{
		int pos=0,flag=0;
        for(int i=0; i<n; i++)
		{
			if(arr[i]==key)
			{
				pos = i;
				flag=1;
			}
		}
		if(flag==1)
		{
			return(pos+1);
		}
		else
		{
			printf("element not found");
			return -1;
		}
		
	}
