#include<stdio.h>

#include<stdlib.h>
#define size 3
void enqueue(int q[],int *r,int *count)
{
	int item;
	if((*count)==size)
	printf("Queue full\n");
	else
	{
		printf("Enter the value to be entered.\n");
		scanf("%d",&item);
			*r=(*r+1) % size;
		q[*r]=item;

		(*count)++;
	}
}
void dequeue(int q[], int *f, int *count)
{
	if(*count==0)
	printf("Queue is empty\n");
	else
	{
		printf("Item deleted is : %d\n",q[*f]);
		*f=(*f+1)%size;
		(*count)--;
	}
}
void display(int q[], int *f,int *count)
{
	int i;
	if((*count)==0)
	printf("Queue is empty\n");
	else
	{
		printf("\nThe Queue is: \n");
		for(i=0;i<*count;i++)
		{
			printf("%d\n",q[i]);
		}
	}
}
int main()
{
	int q[20];
	int r=-1;
	int f=0;
	int count=0;
	int a;
	

	while(1)
	{
		printf("\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			{
				enqueue(q,&r,&count);
				break;
			}
			case 2:
			{
				dequeue(q,&f,&count);
				break;
			}
			case 3:
			{
				display(q,&f,&count);
				break;
			}
			case 4:
			{
				exit(0);
				break;
			}
			default:
			printf("WRONG CHOICE\n");
		}
	}
	return(0);
}

