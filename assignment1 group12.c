#include<stdio.h>
int main(){
    int array[10];                   //1st-declare the array
    //get values to array from user
    printf("enter 10 numbers:\n");
    for(int i=1;i<=10;i++){
        scanf("%d",&array[i]);      //assume the user input value to array elements
    }

   // print odd numbers
    printf("odd numbers are: \n");
    for(int i=1;i<=10;i++){
       if(array[i]%2!=0)
       printf("%d \n",array[i]);
    } 
    // print even numbers
    printf("even numbers are: \n");
    for(int i=1;i<=10;i++){
        if (array[i]%2==0)
        printf("%d \n",array[i]);
        }
// print world
    printf("World");
  
   printf("hello");//
    return 0;
}

