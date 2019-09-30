 #include<stdlib.h>
#include<stdio.h>

struct node
{
  int data;
  struct node *next;
};
typedef struct node *Node;

Node getnode()
{
  Node x;
  x=(Node) malloc (sizeof(Node));
  if(x!=NULL)
    return x;
  else
    {
      printf("Memory not allocated");
      exit(0);
    }
}

Node insert_front(Node first,int item)
{
  Node temp;
  temp=getnode();
  temp->data=item;
  temp->next=first;
  first=temp;
  return first;
}

Node insert_end(Node first,int item)
{
  Node temp,x;
  x=getnode();
  x->data=item;
  x->next=NULL;
  if(first==NULL)
     return x;
  temp=first;
  while(temp->next!=NULL)
     temp=temp->next;
  temp->next=x;
  return first;
}
Node insert_pos(Node first,int item,int pos)
{
	int count=1;
	Node temp,curr,prev;
	temp=getnode();
	temp->data=item;
	temp->next=NULL;
	if(first==NULL && pos==1)
	 	return temp;
	 if(first==NULL && pos!=1)
	 printf("invalid\n");
	 curr=first;
	 prev=NULL;
	 while(curr->next!=NULL&&count!=pos)
	 {
	 	prev=curr;
	 	curr=curr->next;
	 	count++;
	 }
	 if(count==pos)
	 {
	 	prev->next=temp;
	 	temp->next=curr;
	 	return first;
	 }
	 else
	 printf("Enter a valid position\n");
}

 Node delete_beg(Node first)
 {
 	Node temp;
 	if(first==NULL)
 	printf("List is empty\n");
 	else
 	{
 		temp=first;
 		printf("Item deleted is %d\n",temp->data);
 		temp=temp->next;
 		free(first);
 	}
 	return temp;
 	
 }
 
 Node delete_end(Node first)
 {
 	Node curr,prev;
 	if(first==NULL)
 	printf("List is empty\n");
 	else
 	{
 		curr=first;
 		prev=NULL;
 		while(curr->next!=NULL)
 		{
 			prev=curr;
 			curr=curr->next;
 		}
 		printf("Item deleted is %d\n",curr->data);
 		prev->next=NULL;
 		free(curr);
 	}
 	return first;
 }
 	
Node delete_pos(Node first,int pos)
{
	int count=1;
	Node curr,prev;
	if(first==NULL)
	printf("List is empty\n");
	 else
	 {
	 	curr=first;
	 	prev=NULL;
	 	while(curr->next!=NULL&&count!=pos)
	 	{
	 		prev=curr;
	 		curr=curr->next;
	 		count++;
	 	}
	 	if(count==pos)
	 	{
	 		printf("Item deleted is: %d\n",curr->data);
	 		prev->next=curr->next;
	 		free(curr);
	 		return first;
	 	}
	 	else
	 	printf("NOT A VALID POSITION\n");
	 }
}
void display(Node first)
{
  Node temp;
  if(first==NULL)
    {
      printf("list is empty\n");
    }
  else
    {
      temp=first;
      printf("Element in the list: ");
      while(temp!=NULL)
        {
          printf("%d ",temp->data);
          temp=temp->next;
         }
      printf("\n");
     }
}

int main()
{
  Node first=NULL;
  int a,value,pos;
  while(1)
	{
		printf("1.Insert at the front of list\n");
		printf("2.Insert at end of list\n");
		printf("3.Insert at any given position\n");
		printf("4.Delete from the frontof list\n");
		printf("5.Delete from the endof list\n");
		printf("6.Delete from any given position\n");
		printf("7.Display elements of the list\n");
		printf("8.exit\n");
		scanf("%d",&a);
   		switch(a)
       		{
         case 1: printf("Enter the element to be inserted: ");
                 scanf("%d",&value);
                 first=insert_front(first,value);
                 break;
         case 2: printf("Enter the element to be inserted: ");
                 scanf("%d",&value);
                 first=insert_end(first,value);
                 break;
          case 3: printf("Enter the element to be inserted: ");
          	     scanf("%d",&value);
              	 printf("Enter the position to be inserted at: ");
              	 scanf("%d",&pos);
                 first=insert_pos(first,value,pos);
                 break;        
         case 4: first=delete_beg(first);
         		  break;
         case 5: first=delete_end(first);
         		 break;
         case 6: printf("Enter the position to be deleted from: ");
              	 scanf("%d",&pos);
                 first=delete_pos(first,pos);
                 break;   		
         
         case 7: display(first);
                 break;
         case 8: exit(0);
         default: printf("Invalid choice\n");
       }
    }
  return 0;
}
