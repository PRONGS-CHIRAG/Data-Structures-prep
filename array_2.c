/******************************************************************************

  Author : Chirag N Vijay

PASSING ARRAYS TO FUNCTIONS
         ->Passing Individual elements
                    ->Passing data value
                            func(arr[4])
                    ->Passing Address
                            func(&a) and argument type should be int* in func
         ->Passing Entire Array
                   func(arr)

POINTERS AND ARRAYS
       Arrays are also a form of pointers.
       We can change contents of array by POINTERS
       eg) ptr = &arr[4]
       We can initialize array to pointer but not otherwise.
ARRAY OF pointers
      INT *A
       A[0]=&P
       A[1]=&Q
       etc
2D ARRAYS
       
*******************************************************************************/

//Problem Statement : Interchange smallest and largest numbers in array

int find_greatest_pos(int a[10],int n);
int find_smallest_pos(int a[10],int n);
int interchange(int a[10],int n);
#include<stdio.h>
int main(){
  int i,a[10],n;
  printf("Enter array limit \n" );
  scanf("%d\n",&n);
  printf("enter array \n");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  interchange(a,n)
}
int find_greatest_pos(int a[10],int n){
  int i,large,pos;
  large = a[0];
  for(i=0;i<n;i++){
    if(a[i]>large){
      large = a[i];
      pos=i;
    }
  }
  return pos;
}
int find_smallest_pos(int a[10],int n){
  int i,small,pos;
  small = a[0];
  for(i=0;i<n;i++){
    if(a[i]<small){
      small = a[i];
      pos=i;
    }
  }
  return pos;
}
int interchange(int a[10],int n){
  int i,c,b,temp;
  c=find_greatest_pos(a,n);
  b=find_smallest_pos(a,n);
  temp=a[c];
  a[c]=a[b];
  a[b]=temp;
  for(i=0;i<n;i++){
    printf("%d",a[i]);
  }
  return 1;
}
