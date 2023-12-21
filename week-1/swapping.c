#include<stdio.h>
void swap(int *a,int *b);
int main (){
    int a = 1;
    int b = 2;
    printf("a = %d\tb = %d",a,b);
    swap(&a,&b);
    printf("\na = %d\tb = %d",a,b);
    return 0;
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}