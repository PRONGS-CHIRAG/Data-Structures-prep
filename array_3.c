/*********************************************************************************************************************************************************

Author : Chirag N Vijay

2DIMENSIONAL ARRAYS
    Declaration - datatype array_name[row_size][column_size]
    Addresses -
             Column major -> A[i][j]= Base_address + size_of_each_element(Number_of_rows(j-1)+ (i-1))
             Row major    -> A[i][j]= Base_address + size_of_each_element(Number_of_columns(i-1)+(j-1))
    Initialization-
             datatype array_name[row_size][column_size]={values_list}
             column size is compulsory.
    Accessing elements is done via Loops
    Operations-
                Sum
                Transpose
                Difference
                Product


**********************************************************************************************************************************************************/
#include<stdio.h>
void add();
void difference();
void multiply();
void transpose();
int main(){
  printf("this is a tutorial to understand arrays in c\n");
  printf("1:Additiom\n");
  printf("2:Subtraction\n");
  printf("3:multiply\n");
  printf("4:transpose\n");
  printf("5:exit\n");
  printf("enter choice\n");
  int ch ;
  scanf("%d\n",&ch);
  switch(ch){
    case 1 : add();
             break;
    case 2 : difference();
             break;
    case 3 : multiply();
             break;
    case 4 : transpose();
             break;
    case 5 : break;
    }
}
void add(){
  int i,j,m1,n1,m2,n2,a[10][10],b[10][10],c[10][10];
  printf("Enter row size and column size of array 1\n");
  scanf("%d%d",&m1,&n1);
  printf("Enter row size and column size of array 2\n");
  scanf("%d%d",&m2,&n2);
  printf("Enter array1\n");
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      scanf("%d",&a[i][j]);
    }
  }
  printf("Enter array2\n");
  for(i=0;i<m2;i++){
    for(j=0;j<n2;j++){
      scanf("%d",&b[i][j]);
    }
  }
  if(m1==m2 && n1==n2){
    for(i=0;i<m1;i++){
      for(j=0;j<n1;j++){
        c[i][j]=a[i][j]+b[i][j];
      }
    }
  }
  else{
    printf("addition not possible");
    exit(0);
  }
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      printf("%d",c[i][j]);
    }
  }
}
void difference(){
  int i,j,m1,n1,m2,n2,a[10][10],b[10][10],c[10][10];
  printf("Enter row size and column size of array 1\n");
  scanf("%d%d",&m1,&n1);
  printf("Enter row size and column size of array 2\n");
  scanf("%d%d",&m2,&n2);
  printf("Enter array1\n");
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      scanf("%d",&a[i][j]);
    }
  }
  printf("Enter array2\n");
  for(i=0;i<m2;i++){
    for(j=0;j<n2;j++){
      scanf("%d",&b[i][j]);
    }
  }
  if(m1==m2 && n1==n2){
    for(i=0;i<m1;i++){
      for(j=0;j<n1;j++){
        c[i][j]=a[i][j]-b[i][j];
      }
    }
  }
  else{
    printf("subtraction not possible\n");
    exit(0);
  }
  printf("Difference is\n");
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      printf("%d",c[i][j]);
    }
  }
}
void multiply(){
  int i,j,m1,n1,m2,n2,a[10][10],b[10][10],c[10][10];
  printf("Enter row size and column size of array 1\n");
  scanf("%d%d",&m1,&n1);
  printf("Enter row size and column size of array 2\n");
  scanf("%d%d",&m2,&n2);
  printf("Enter array1\n");
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      scanf("%d",&a[i][j]);
    }
  }
  printf("Enter array2\n");
  for(i=0;i<m2;i++){
    for(j=0;j<n2;j++){
      scanf("%d",&b[i][j]);
    }
  }
  if(n1!=m2){
    printf("multiplication not possible\n");
    exit(0);
  }
  for(i=0;i<m1;i++){
    for(j=0;j<n2;j++){
      c[i][j]=0;
      for(k=0;k<n2;k++){
        c[i][j] += a[i][k]*b[k][j];
      }
    }
  }
  printf("The product is\n");
  for(i=0;i<m1;i++){
    for(j=0;j<n2;j++){
      printf("%d",c[i][j]);
    }
  }
}
void transpose(){
  int i,j,m1,n1,a[10][10],b[10][10];
  printf("Enter row size and column size of array 1\n");
  scanf("%d%d",&m1,&n1);
  printf("Enter array1\n");
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      scanf("%d",&a[i][j]);
    }
  }
  printf("transposed array is\n");
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      b[i][j]=a[j][i];
    }
  }
  for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
      printf("%d",b[i][j]);
    }
  }
}
