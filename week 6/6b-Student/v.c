void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i=0, j=0;
	char item;
	char x;

	push('(');                               
	strcat(source_infix,")");                  

	item=infix_exp[i];        

	while(item != '\0')        
	{
		if(item=='(' || item =='{' || item == '[')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			target_postfix[j] = item;              
			j++;
		}
		else if((!isdigit(item)) && !isalpha(item))        
		{
			x=pop();
			while((symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-') &&
             ((s->arr[s->top] == '^') || 
                    ((s->arr[s->top] == '*' || s->arr[s->top]=='/') && (token == '+' || token == '-' || token =='(' || token == '{' || token=='[' || token == ')' || token == '}' || token == ']'))
                     || ((s->arr[s->top]=='+' || (s->arr[s->top] == '-')))))
			{
				 
                target_postfix[j++]=x;
                target_postfix[j] = x;                 
				j++;
                x = stack_peek(s);
                stack_pop(s);                     
			}
			push(x);

			push(item);                
		}
		else if(item==')' || item == '}' || item == ']')         
		{
			x = stack_peek(s);
            stack_pop(s);                       
			while(x != '(')               
			{
				target_postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			return
		}
		i++;


		item = infix_exp[i]; 
	if(s->top>0)
	{
		return;
	}
	if(s->top>0)
	{
		return;
	}


	target_postfix[j] = '\0'; 

}