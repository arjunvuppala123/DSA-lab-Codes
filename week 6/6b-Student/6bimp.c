#include "6b.h"

stack* stack_initialize(int size)
{
//TODO
    stack* Stack = (stack*)malloc(sizeof(stack)); 

    if (!Stack)  
        return NULL; 

    Stack->top = -1; 

    Stack->arr = (int*) malloc(size* sizeof(int)); 
    
    return Stack; 
}

void stack_push(stack *ptr_stack, int key) 
{
//TODO

    if(ptr_stack->top == -1)
    {
        
        ptr_stack->arr[0] = key;

    }

    else{
        ptr_stack->arr[ptr_stack->top+1] = key;
    }

    ptr_stack->top++;
    return;
}

void stack_pop(stack *ptr_stack)
{
//TODO

    if(ptr_stack->top == -1)
       
        return;

    else{

        ptr_stack->top--;

    }
}

int stack_is_empty(stack *ptr_stack)
{
//TODO

    if(ptr_stack->top == -1)
    {

        return 1;

    }
    else
    {
        
        return 0;

    }
}

int stack_peek(stack *ptr_stack) 
{
//TODO

    return ptr_stack->arr[ptr_stack->top];

}

void stack_destroy(stack *ptr_stack) 
{
//TODO

    free(ptr_stack->arr);
    free(ptr_stack);

}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO

    int len = strlen(source_infix);

    char curr, top, cP;
    int pi = 0;;

    stack* s = stack_initialize(len);

    for(int i=0;i<len;i++)
    {
        curr = source_infix[i];
        if((curr>='a' && curr<='z' )|| (curr>='A' && curr<='Z'))
        {

            target_postfix[pi] = curr;
            pi++;

        }

        else if(curr=='{' || curr=='(' || curr=='[' )
            stack_push(s,curr);

        else if(curr=='}' || curr==')' || curr==']')
        {
            switch(curr)
            {

                case '}':
                        cP = '{';
                        break;
                case ')':
                        cP = '(';
                        break;
                case ']':
                        cP = '[';
                        break;

            }
            
            while(stack_peek(s)!=cP)  

            {

                top = stack_peek(s);
                target_postfix[pi] = top;
                stack_pop(s);
                pi++;
            }

            stack_pop(s); //pops out the corresponding opening paranthesis
        }

        else
        {
            loop:

            if(stack_is_empty(s))
                stack_push(s,curr);

            else
            {
               char top = stack_peek(s);
               if(top == '{' || top == '(' || top == '[')
                   stack_push(s,curr);
               else
               {
                   switch(curr)
                   {
                       case '+':
                       case '-':
                       {
                           target_postfix[pi] = top;
                            stack_pop(s);
                            pi++;

                            goto loop;
                       }

                       case '*':
                       case '/':
                       {
                            if(top == '*' || top=='/')
                            {
                                target_postfix[pi] = top;
                                stack_pop(s);
                                pi++;

                                goto loop;
                            }
                            else
                                stack_push(s,curr);
                       }
                   }
               }
            }
        }
    }
    while(s->top!=-1)
    {
        top = stack_peek(s);
        target_postfix[pi] = top;
        stack_pop(s);
        pi++;
    }

    stack_destroy(s);
    target_postfix[pi] = '\0';
}




