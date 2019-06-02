/******************************************************************************

  Author : Chirag N Vijay
  
  Topic : Arrays
  Points :-  Collection of similar data elements.
             Same datatype
             Stored in consecutive memory locations and referenced by an index
             Index should be of integer type
             Loops are used to access these elements
             Address = Base Address + size_of_one_element_in_memory(index-lower_bound)
             Length_of_array = upper_bound - lower_bound +1
             Declaration :-
                    type array_name[size]={list_of_values}
                    In 1d arrays size may not be initialized

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void sort();
void merge();
void search();

int main(){
  while(1==1){
  printf("this is a tutorial to understand arrays in c\n");
  printf("1:Insertion\n");
  printf("2:Deleting\n");
  printf("3:Sorting\n");
  printf("4:Merging 2 arrays\n");
  printf("5:Searching\n");

  printf("6:exit\n");
  printf("enter choice\n");
  int ch ;
  scanf("%d\n",&ch );
  switch(ch){
    case 1 : insert();
             break;
    case 2 : delete();
             break;
    case 3 : sort();
             break;
    case 4 : merge();
             break;
    case 5 : search();
             break;
    case 6 : exit(0);
	     break;

  }
}
}
void insert(){
  int n,item,d,a[100];
  printf("enter array limit");
  scanf("%d",&n);
  printf("enter array");
  for(int i =0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("enter position and item");
  scanf("%d%d", &d,&item);
  int j=n,i=0;
  printf("before  inserting");
  for(i=0;i<n;i++){
    printf("%d",a[i]);
  }
  n++;
  while(j>=d){
    a[j+1]=a[j];
    j--;
    }
  a[d]=item;
  printf("after  inserting");
  for(i=0;i<n;i++){
    printf("%d",a[i]);
  }
}

void delete(){
  int n,num,d,a[100],i;
  printf("enter array limit");
  scanf("%d",&n);
  printf("enter array");
  for(int i =0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("enter number to be deleted");
  scanf("%d",&num);
  for(i=0;i<n;i++){
    if (a[i]== num){
      d=i;
    }
  }
  for(i=d;i<n-1;i++){
    a[i]=a[i+1];
  }
  n--;
  printf("array after deletion");
  for(i=0;i<n;i++){
    printf("%d",a[i]);
  }
}

void sort(){
  int n,temp,j=0,a[100],i=0;
  printf("enter array limit");
  scanf("%d",&n);
  printf("enter array");
  for(int i =0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for (i = 0; i < n; i++)
   {
    for (j = 0; j < (n - i - 1); j++)
       { if (a[j] > a[j + 1])
           {   temp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = temp;
           }
       }
}
  for(i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
}

void merge(){
  int n,m,temp,j=0,a[100],b[100],c[100],index=0,i=0;
  printf("enter array limit of array 1");
  scanf("%d",&m);
  printf("enter array");
  for(int i =0;i<m;i++){
    scanf("%d",&a[i]);
  }
  printf("enter array limit of array 2");
  scanf("%d",&n);
  printf("enter array");
  for(int i =0;i<n;i++){
    scanf("%d",&b[i]);
  }
  temp = m + n;
  for(i=0;i<m;i++){
    c[index]=a[i];
    index++;
  }
  for(i=0;i<n;i++){
    c[index]=b[i];
    index++;
  }
  printf("merged array is ");
  for(index=0;index<temp;index++){
    printf("%d",c[index]);
  }
}

void search(){
  int n,i,num,d,a[100],count=0;
  printf("enter array limit");
  scanf("%d",&n);
  printf("enter array");
  for(int i =0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("enter number to be searched");
  scanf("%d",&num);
  for(i=0;i<n;i++){
    if (a[i]== num){
      count++;
    }
  }
  if(count>0){
    printf("the number %d has appeared %d times",num,count);
  }
  else{
    printf("not found");
  }
}
