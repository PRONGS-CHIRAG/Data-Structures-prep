/********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************

Author : Chirag N Vijay

Topic : Linked Lists
INTRODUCTION
      Linked lists are linear collection of data elements.Data elements are also called nodes.
      Node contain 1 or more data fields and a pointer to the next node.
      Structure:
             struct node{
             int data;
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
struct node *delete_node(struct  node *);
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
  printf("8:Delete node\n");
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
    case 8 : delete_node(start);
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
  struct node *new_node, *ptr;
  int num;
  printf("enter number\n");
  scanf("%d\n",&num);
  while(num!=-1){
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if(start==NULL){
      new_node->next=NULL;
      start = new_node;
    }
    else{
      ptr = start;
      while(ptr->next!=NULL){
        ptr=ptr->next;
      }
      ptr->next=new_node;
      new_node->next=NULL;
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
  new_node->next = NULL;
  return start;
  }
  struct node *insert_before(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num,n1;
    printf("enter number\n");
    scanf("%d\n",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    printf("enter value before which");
    scanf("%d",&n1);
    ptr = start;
    while(ptr->data!=n1){
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
    return start;
  }
  struct node *insert_after(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num,n1;
    printf("enter number\n");
    scanf("%d\n",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    printf("enter value before which");
    scanf("%d",&n1);
    ptr = start;
    preptr = ptr;
    while(preptr->data!=n1){
      preptr = ptr;
      ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
    return start;
  }
  struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
  }
  struct node *delete_end(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
      preptr=ptr;
      ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
  }
  struct node *delete_node(struct node *start){
    struct node *ptr,*preptr;
    int n1;
    printf("enter value of node which should be deleted");
    scanf("%d",&n1);
    ptr = start;
    if(ptr->data==n1){
      start=delete_beg(start);
      return start;
    }
    else{
      while(ptr->data!=n1){
        preptr = ptr;
        ptr=ptr->next;
      }
      preptr->next = ptr->next;
      free(ptr);
      return start;
      }
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
    free(ptr);
    return start;
  }
  struct node *delete_list(struct node *start){
    struct node *ptr;
    if(start!=NULL){
      ptr=start;
      while(ptr!=NULL){
        printf("element going to be deleted is %d\n",ptr->data);
        start=delete_beg(start);
        ptr=start;
      }
    }
    return start;
  }

  struct node *sort(struct node *start){
    struct node *ptr1,*ptr2;
    ptr1=start;
    while(ptr1->next!=NULL){
      ptr2=ptr1->next;
      while(ptr2->next!=NULL){
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
