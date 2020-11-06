//Implementation for session1_seq_search.h
#include "ss.h"

//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.

//Below program returns the true position of the key in the array as per the example illustrated in the specification for  //Data Structures Lab1: Implement Sequential Search (pdf file)

int seqsearch(int *arr, int n, int key) 
	{
		int pos=0,flag=0;
        	for(int i=0; i<n; i++)
		{
			if(arr[i]==key)
			{
				pos = i;
				flag=1;
				break;
			}
			else
			{
				continue;
			}
		}
		if(flag==1)
		{
			return(pos+1); 
		}
		else
		{
			return -1;
		}
		
	}
