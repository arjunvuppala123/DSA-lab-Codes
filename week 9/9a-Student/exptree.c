#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  char data;
  struct tnode *left;
  struct tnode *right;
};
void inorder(struct tnode*);
void preorder(struct tnode*);
void postorder(struct tnode*);
struct tnode* create_exptree(char*);
int isoper(char);
void push(struct tnode**,int*,struct tnode*);
struct tnode* pop(struct tnode**,int*);
int evaluate(struct tnode*);
void main()
{
  struct tnode *root;
  int ch,num,k;
  char exp[100];
  root=NULL;
  
  printf("Enter the postfix form of the expression...");
  scanf("%s",exp);
  
  root=create_exptree(exp);
  printf("The infix expression = \n");
  inorder(root);
  printf("\nThe prefix expression = \n");
  preorder(root);
  printf("\nThe postfix expression = \n");
  postorder(root);
 printf("\nEvaluating the expression\n");
  int result = evaluate(root);
  printf("\nThe evaluation of the expression = %d\n",result);
  
}

int evaluate(struct tnode *t)
{
	 int x;
	switch (t->data)
	{
	 case '+': return(evaluate(t->left) +  evaluate(t->right));
	case '-':return(evaluate(t->left) - evaluate(t->right));
	case '*': return(evaluate(t->left) *  evaluate(t->right));
	case '/':return(evaluate(t->left) / evaluate(t->right));
		
	default: printf("%c = ",t->data);
	              scanf("%d",&x);
	              return x;
	}
}
		
	
	

 struct tnode *create_exptree(char *exp)
 {
	 char ch;
	 struct tnode *stk[100];//stack
	 int top=-1;
	int  i=0;
	struct tnode *temp;
	 while(exp[i]!='\0')
	 {
		 ch=exp[i];
		 
		 temp=(struct tnode*)malloc(sizeof(struct tnode));
		 temp->data=ch;
		 temp->left=temp->right=NULL;
		 
		 if(isoper(ch))
		 {
			 temp->right=pop(stk,&top);
			 temp->left=pop(stk,&top);
			 push(stk,&top,temp);		 
		 }
		 else
			 push(stk,&top,temp);
		 i++;
	 }
              return(pop(stk,&top));
 }
 
 
 void push(struct tnode **s, int *t, struct tnode *temp)
 {
	 ++*t;
	 s[*t]=temp;
 }
 
 struct tnode *pop(struct tnode **s, int *t)
 {
	 struct tnode *temp;
	 
	 temp=s[*t];
	 --*t;
	 return temp;
 }
	 
	 


int isoper(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':
      case '*':
      case '/':return 1;
      default: return 0;
    }
  }




void preorder(struct tnode *t)
  {
    if(t!=NULL)
    {
     printf("%c ",t->data);
     preorder(t->left);
     preorder(t->right);
   }
 }

  void postorder(struct tnode *t)
  {
    if(t!=NULL)
    {
     
     postorder(t->left);
     postorder(t->right);
     printf("%c ",t->data);
   }
 }

void inorder(struct tnode *t)
  {
    if(t!=NULL)
    {
     inorder(t->left);
     printf("%c ",t->data);
     inorder(t->right);
   }
 }














 




  












             















  























