#include "6b.h"
stack* stack_initialize(int size)
{
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->arr = (int*)malloc(sizeof(int)*size);
    new_stack->top = -1; // initially stack is empty
    return new_stack;
}

void stack_push(stack *ptr_stack, int key)
{
    /* since the size of the array in the stack is initialized to the size of the input string, all characters of the string
    will get added to the array without encountering full array, and hence that condition is not checked*/

    if(ptr_stack->top == -1)
        ptr_stack->arr[0] = key; // inserted at 0th position
    else
        ptr_stack->arr[ptr_stack->top + 1] = key; //inserted at the end

    ptr_stack->top++;
    return;

}

void stack_pop(stack *ptr_stack)
{
    if(ptr_stack->top == -1) //stack is empty, no change necessary
        return;
    else
    {
        ptr_stack->top--;
        return;
    }
}

int stack_is_empty(stack *ptr_stack)
{
   if(ptr_stack->top == -1)
        return 1;
   else
        return 0;
}

int stack_peek(stack *ptr_stack)
{
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack)
{
    free(ptr_stack->arr);
    free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
    int size = strlen(source_infix);
    char cur, top_ele, correspondingParenthesis;
    int postfix_index = 0;;
    stack* postfix_Stack = stack_initialize(size);

    for(int i=0;i<size;i++)
    {
        cur = source_infix[i];
        if((cur>='a' && cur<='z' )|| (cur>='A' && cur<='Z'))
        {
            target_postfix[postfix_index] = cur;
            postfix_index++;
        }

        else if(cur=='{' || cur=='(' || cur=='[' )
            stack_push(postfix_Stack,cur);

        else if(cur=='}' || cur==')' || cur==']')
        {
            switch(cur)
            {
                case '}':correspondingParenthesis = '{';break;
                case ')':correspondingParenthesis = '(';break;
                case ']':correspondingParenthesis = '[';break;
            }
            while(stack_peek(postfix_Stack)!=correspondingParenthesis)  //pops out all elements until corresponding opening parenthesis is reached
            {

                top_ele = stack_peek(postfix_Stack);
                target_postfix[postfix_index] = top_ele;
                stack_pop(postfix_Stack);
                postfix_index++;
            }
            stack_pop(postfix_Stack); //pops out the corresponding opening paranthesis
        }

        else
        {
            loop:

            if(stack_is_empty(postfix_Stack))
                stack_push(postfix_Stack,cur);

            else
            {
               char top = stack_peek(postfix_Stack);
               if(top == '{' || top == '(' || top == '[')
                   stack_push(postfix_Stack,cur);
               else
               {
                   switch(cur)
                   {
                       case '+':
                       case '-':
                       {
                           target_postfix[postfix_index] = top;
                            stack_pop(postfix_Stack);
                            postfix_index++;

                            goto loop;
                       }

                       case '*':
                       case '/':
                       {
                            if(top == '*' || top=='/')
                            {
                                target_postfix[postfix_index] = top;
                                stack_pop(postfix_Stack);
                                postfix_index++;

                                goto loop;
                            }
                            else
                                stack_push(postfix_Stack,cur);
                       }
                   }
               }
            }
        }
    }
    while(postfix_Stack->top!=-1)
    {
        top_ele = stack_peek(postfix_Stack);
        target_postfix[postfix_index] = top_ele;
        stack_pop(postfix_Stack);
        postfix_index++;
    }

    stack_destroy(postfix_Stack);
    target_postfix[postfix_index] = '\0';
}
