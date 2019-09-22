#include<stdio.h>
#include<conio.h>
#include<process.h>
#define size 5
void enqueue(int q[],int *r, int *count)
	{
	int item;
	if (*count==size)
	printf(" Queue overflow");
	else
	    {
	    printf("Enter the element to be entered in the queue\n");
	    scanf("%d",&item);
	    *r=(*r+1)%size;
	    q[*r]=item;
	    (*count)++;
	    }
	}
	void dequeue(int q[],int *f, int *count)
	{
	if (*count==0)
        printf("Queue is empty");
    else
    {
        printf("item deleted is:%d\n",q[*f]);
        *f=(*f+1)%size;

        (*count)--;
    }
	}
	void display(int q[], int *count)
	{
	    int i;
	    if (*count==0)
            printf("Queue is empty");
        else
        {
            printf("\nTHE QUEUE:\n");
            for(i=0;i<*count;i++)
            {
                printf("%d\n",q[i]);
            }
        }
	}
            int main()
            {
                int q[size],r=-1,f=0,count=0,a;
                while(1)
                {
                    printf("1: INSERT ELEMENTS\n");
                    printf("2: DELETE ELEMENTS\n");
                    printf("3: DISPLAY ELEMENTE OF THE QUEUE\n");
                    printf("4: EXIT\n");
                    printf("ENTER YOUR CHOICE\n");
                    scanf("%d",&a);
                    switch(a)
                    {
                    case 1:
                        enqueue(q,&a,&count);
                        break;
                    case 2:
                        dequeue(q,&f,&count);
                        break;
                    case 3:
                        display(q,&count);
                        break;
                    case 4:
                        exit(0);
                    default :
                        printf("ENTER A VALID CHOICE\n");
                    }
                }
                    getch();
            }
