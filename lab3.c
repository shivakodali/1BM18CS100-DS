#include<stdio.h>
#include<conio.h>
#include<process.h>
#define size 10
void push(char item, char stack[], int *top)
{
	(*top)++;
	stack[*top]=item;
 }
char pop(char stack[],int *top)
{
	char item;
	if(*top==-1)
	printf("Enter a valid expression");
	else
	{
		item=stack[*top];
		(*top)--;
	}
	return item;

}
int is_operator(char a)
{
	if(a=='/'||a=='*'||a=='+'||a=='-')
	return 1;
	else
	return 0;
}
int precedence( char a)
{
	if(a=='/'||a=='*')
	return 2;
	else if(a=='+'||a=='-')
	return 1;
	else
	return 0;
}
void infix_to_postfix( char infix_exp[],char postfix_exp[])
{
	int i,j;
	char stack[20];
	int top=-1;
	char x;
	char item;
	push('(',stack,&top);
	strcat(infix_exp,")");
	i=0;
	j=0;
	item=infix_exp[i];
	while(item!='\0')
	{
		if(item=='(')
		push(item,stack,&top);
		else if(isdigit(item)||isalpha(item))
		{
			postfix_exp[j]=item;
			j++;
		}
		else if(is_operator(item)==1)
		{
			x=pop(stack,&top);
			while(is_operator(x)&& precedence(x)>precedence(item))
			{
				postfix_exp[j]=x;
				j++;
				x=pop(stack,&top);
			}
			push(x,stack,&top);
			push(item,stack,&top);
		}
		else if(item==')')
		{
			x=pop(stack,&top);
			while(x!='(')
			{
				postfix_exp[j]=x;
				j++;
				x=pop(stack,&top);
			}
		}
		else
		{
			printf("INVALID\n");
			exit(0);
		}
		i++;
		item=infix_exp[i];
	}
	postfix_exp[j]='\0';
	puts(postfix_exp);
}
void main()
{
	char infix[size],postfix[size];
	clrscr();
	printf("Enter an infix expression which consists of only single character operands and use only binary operators\n");
	printf("enter the infix expression\n");
	gets(infix);
	printf("Result:\n");
	infix_to_postfix(infix,postfix);
	getch();
}
