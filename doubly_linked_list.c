/********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************

Author : Chirag N Vijay

Topic :  Doubly -linked Linked Lists
INTRODUCTION
      Manipulation and accessing elements are easier whereas more space is
      needed per node and operations are more expensive.
      Prev of first node and next of last node are NULL

      Structure:
             struct node{
             int data;
             struct node *prev;
             struct node *next;
           }
      Doesnt store nodes in consecutive memory locations
      We can add any number of nodes.






*******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct  node *);
struct node *insert_end(struct  node *);
struct node *insert_before(struct  node *);
struct node *insert_after(struct  node *);
struct node *delete_beg(struct  node *);
struct node *delete_end(struct  node *);
struct node *delete_before(struct  node *);
struct node *delete_after(struct  node *);
struct node *delete_list(struct  node *);
struct node *sort(struct  node *);

int main(){
  printf("this is a tutorial to understand linked list in c\n");
  printf("1:Create Linked list\n");
  printf("2:Insert at beginning\n");
  printf("3:Insert at end\n");
  printf("4:Insert before\n");
  printf("5:Insert after\n");
  printf("6:Delete at beginning\n");
  printf("7:Delete at end\n");
  printf("8:Delete before\n");
  printf("9:Delete after\n");
  printf("10:Delete list\n");
  printf("11:Sort list\n");
  printf("12:exit\n");
  printf("enter choice\n");
  int ch ;
  scanf("%d\n",&ch );
  switch (ch) {
    case 1 : create_ll(start);
             break;
    case 2 : insert_beg(start);
             break;
    case 3 : insert_end();
             break;
    case 4 : insert_before(start);
             break;
    case 5 : insert_after(start);
             break;
    case 6 : delete_beg(start);
             break;
    case 7 : delete_end(start);
             break;
    case 8 : delete_before(start);
             break;
    case 9 : delete_after(start);
             break;
    case 10 : delete_list(start);
              break;
    case 11 : sort(start);
              break;
    case 12 : exit(0);
              break;

  }
}
struct node *create_ll(struct node *start){
  struct node *new_node,*ptr;
  int num;
  printf("enter data\n");
  scanf("%d",&num);
  while(num!=-1){
    new_node=(struct node *)malloc(sizeof(node));
    new_node->data = num;
    if(start==NULL){
      new_node->prev=NULL;
      new_node->next=NULL;
      start=new_node;
    }
    else{
      ptr=start;
      while(ptr->next!=NULL){
        ptr=ptr->next;
      }
      ptr->next=new_node;
      new_node->prev=ptr;
      new_node->next=NULL;

    }
    printf("enter data\n");
    scanf("%d",&num);
  }
  return start;
}

struct node *insert_beg(struct node *start){
  int num;
  struct node *ptr,*new_node;
  ptr=start;
  new_node=(struct node *)malloc(sizeof(node));
  printf("enter data\n");
  scanf("%d",&num);
  new_node->data=num;
  new_node->next=ptr;
  ptr->prev=new_node;
  new_node->prev=NULL;
  start = new_node;
  return start;
  }
struct node *insert_end(struct node *start){
  int num;
  struct node *ptr,*new_node;
  ptr=start;
  new_node=(struct node *)malloc(sizeof(node));
  printf("enter data\n");
  scanf("%d",&num);
  new_node->data=num;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->next=new_node;
  new_node->prev=ptr;
  new_node->next=NULL;
  return start;
}
struct node *insert_before(struct node *start){
  int val,num;
  struct node *ptr,*new_node,*preptr;
  ptr=start;
  printf("enter data\n");
  scanf("%d",&num);
  new_node = (struct node *)malloc(sizeof(node));
  new_node->data=num;
  printf("enter value before it should be inserted\n");
  scanf("%d",&val);
  while(ptr->data!=val){
    preptr=ptr;
    ptr=ptr->next
  }
  preptr->next=new_node;
  new_node->prev=preptr;
  new_node->next=ptr;
  ptr->prev=new_node;
  start=preptr;
  return start;
}

struct node *insert_after(struct node *start){
  int val,num;
  struct node *ptr,*new_node;
  ptr=start;
  printf("enter data\n");
  scanf("%d",&num);
  new_node = (struct node *)malloc(sizeof(node));
  new_node->data=num;
  printf("enter value after it should be inserted\n");
  scanf("%d",&val);
  while(ptr->data!=val){
      ptr=ptr->next
  }
  new_node->prev=ptr;
  new_node->next=ptr->next;
  ptr->next->prev=new_node;
  ptr_next=new_node;
  return start;
}
struct node *delete_beg(struct node *start){
  struct node *ptr;
  ptr=start;
  start=start->next;
  start->prev=NULL;
  free(ptr);
  return start;
}
struct node *delete_end(struct node *start){
  struct node *ptr;
  ptr=start;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->prev->next=NULL;
  free(ptr);
  return start;
}
struct node *delete_after(struct node *start){
  struct node *ptr;
  printf("enter number");
  scanf("%d",&val);
  ptr=start;
  while(ptr->data!=val){
    ptr=ptr->next;
  }
  temp=ptr->next;
  ptr->next=temp->next;
  temp->next->prev=ptr;
  free(temp);
  return start;
}
struct node *delete_before(struct node *start){
  struct node *ptr,*temp;
  printf("enter number");
  scanf("%d",&val);
  ptr=start;
  while(ptr->data!=val){
    ptr=ptr->next;
  }
  temp=ptr->prev;
  if(temp=start){
    start=delete_beg(start);

  }
  else{
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
  }
  free(temp);
  return start;
}
struct node *delete_list(struct node *start){
  while(start!=NULL){
    start=delete_beg(start);
  }
  return start;
}
