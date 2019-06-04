/*******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************
Author : Chirag N Vijay

Topic : Circular Linked Lists

Circular linked lists are singly linked lists in which the last end connects to first node
No beginning and no end.
Iteration in it is complex.



*******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct  node *);
struct node *insert_end(struct  node *);
struct node *delete_beg(struct  node *);
struct node *delete_end(struct  node *);
struct node *delete_after(struct  node *);
struct node *delete_list(struct  node *);
struct node *sort(struct  node *);

int main(){
  printf("this is a tutorial to understand  circular linked list in c\n");
  printf("1:Create  Circular Linked list\n");
  printf("2:Insert at beginning\n");
  printf("3:Insert at end\n");
  printf("4:Delete at beginning\n");
  printf("5:Delete at end\n");
  printf("6:Delete after\n");
  printf("7:Delete list\n");
  printf("8:Sort list\n");
  printf("9:exit\n");
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
    case 4 : delete_beg(start);
             break;
    case 5 : delete_end(start);
             break;
    case 6 : delete_after(start);
             break;
    case 7 : delete_list(start);
              break;
    case 8 : sort(start);
              break;
    case 9 : exit(0);
              break;

  }
}

struct node *create_ll(struct node *start){
  struct node *new_node, *ptr;
  int num;
  printf("enter number\n");
  scanf("%d\n",&num);
  while(num!=-1){
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if(start==NULL){
      new_node->next=new_node;
      start = new_node;
    }
    else{
      ptr = start;
      while(ptr->next!=NULL){
        ptr=ptr->next;
      }
      ptr->next=new_node;
      new_node->next=start;
    }
    printf("enter data\n");
    scanf("%d",&num);
  }
  return start;
}
struct node *insert_beg(struct node *start){
  struct node *new_node;
  int num;
  printf("enter number\n");
  scanf("%d\n",&num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  new_node->next = start;
  start = new_node;
  return start;
}
struct node *insert_end(struct node *start){
  struct node *new_node,*ptr;
  int num;
  printf("enter number\n");
  scanf("%d\n",&num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  ptr = start;
  while(ptr->next!=NULL){
    ptr = ptr->next;
  }
  ptr->next=new_node;
  new_node->next = start;
  return start;
  }

  struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
      ptr=ptr->next;
    }
    ptr->next=start->next;
    free(start);
    start = ptr->next;
    return start;
  }
  struct node *delete_end(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
      preptr=ptr;
      ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
  }

  struct node *delete_after(struct node *start){
    struct node *ptr,*preptr;
    int n1;
    printf("enter value of node which should be deleted");
    scanf("%d",&n1);
    ptr = start;
    preptr = ptr;
    while(preptr->data!=n1){
      preptr = ptr;
      ptr=ptr->next;
    }
    preptr->next = ptr->next;
    if(ptr==start){
      start = preptr->next;
    }
    free(ptr);
    return start;
  }
  struct node *delete_list(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
      start = delete_end(start);
    }
    free(start);
    return start;
  }

  struct node *sort(struct node *start){
    struct node *ptr1,*ptr2;
    ptr1=start;
    while(ptr1->next!=start){
      ptr2=ptr1->next;
      while(ptr2->next!=start){
        if(ptr1->data>ptr2->data){
          temp = ptr1->data;
          ptr1->data=ptr2->data;
          ptr2->data = temp;
        }
        ptr2=ptr2->next;
      }
      ptr1=ptr1->next;
    }
    return start;
  }
