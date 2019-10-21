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
 
Node sort(Node first)
{
Node temp1,temp2,head;
head=first;
int swap;
//second=first->next;
if(first==NULL)
printf("EMPTY\n");
else
{
for(temp1=first;temp1!=NULL;temp1=temp1->next)
{
for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
{


swap=temp1->data;
temp1->data=temp2->data;
temp2->data=swap;

}


}
}


return head;
}
Node merging(Node first1,Node first2)
{
Node temp=first1;
while(first1->next!=NULL)
{
first1=first1->next;
}
first1->next=first2;
return temp;
}

Node reverse(Node first)
{
Node prev,curr,temp;
prev=NULL;
curr=first;
while(curr!=NULL)
{
temp=curr->next;
temp->next=curr;
prev=curr;
curr=curr->next;
}
first->next=NULL;
first=prev;
return first;
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
  Node first1=NULL;
  Node first2=NULL;
  int a,value,pos;
  while(1)
{

printf("1.Insert list 1\n");
printf("2.Insert list 2\n");
printf("3.Sorted list 1\n");
printf("4.Sorted list 2\n");
printf("5.Merged lists\n");
printf("6.reverse of list\n");
//printf("4.delete in front\n");
//printf("5.delete in end\n");
//printf("6.delete at any position\n");
//printf("7.display\n");
printf("7.exit\n");
scanf("%d",&a);
    switch(a)
        {
         case 1: printf("Enter the element to be inserted: ");
                 scanf("%d",&value);
                 first1=insert_end(first1,value);
                 break;
         case 2: printf("Enter the element to be inserted: ");
                 scanf("%d",&value);
                 first2=insert_end(first2,value);
                 break;
          case 3: first1=sort(first1);
           display(first1);
           break;
          case 5: first1=merging(first1,first2);
           display(first1);
           break;
         case 4:  first2=sort(first2);
           display(first2);
           break;
           case 6: first1=reverse(first1);
            display(first1);
            break;
       //  case 5: first=delete_end(first);
         // break;
        // case 6: printf("Enter the position to be deleted: ");
              // scanf("%d",&pos);
              //   first=delete_pos(first,pos);
              //   break;  
         
        // case 7: display(first);
        //         break;
         case 7: exit(0);
         default: printf("Invalid choice\n");
       }
    }
  return 0;
}

