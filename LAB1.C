#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#define stack_size 10
 
int top=-1,stack[stack_size];
void push();
void pop();
void display();
 
void main()
{
int x; clrscr();
while(1)
	{
		printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&x);

		switch(x)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);

			default: printf("\nenter a valid option");
		}
	}
}

void push()
{
	int itm;

	if(top==stack_size-1)
	{
		printf("\nStack is full");
	}
	else
	{
		printf("\nEnter element to push:");
		scanf("%d",&itm);
		top=top+1;
stack[top]=itm  ;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nDeleted element is %d",stack[top]);
		top=top-1;
	}
}

void display()
{
	int i;

	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nStack is=");
		for(i=top;i>=0;--i)
			printf("%d\n",stack[i]);
	}
}