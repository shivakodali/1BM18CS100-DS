#include<stdio.h>
#include<conio.h>
int stack[50];
int top =-1;
void push(int x)
{
	stack[++top] = x;
}
int pop()
{
	return stack[top--];
 }
 int main()
 {
	char exp[50];
	char *term;
	int n1,n2,n3,num;
	printf("Enter the postfix expression: ");
	scanf("%s",exp);
	term=exp;
      while(*term != '\0')
	{
	   if(isdigit(*term))
	   {
		num =*term - 48;
		push(num);
	    }
	    else
	    {
	       n1 =pop();
	       n2 =pop();
	       switch(*term)
	       {
			case'+':
			{
			n3=n2+n1;
			break;
			}
			case'-':
			{
			n3=n2-n1;
			break;
			}
			case'*':
			{
			n3=n2*n1;
			break;
			}
			case'/':
			{
			n3=n2/n1;
			break;
			}
			default:
			{
			printf(" Enter a valid operator");
			}
	       }
	       push (n3);
	   }
	   term++;
	}
		printf("The result of the give postfix operation %s =%d\n",exp,pop());
		getch();
		return 0;
 }

