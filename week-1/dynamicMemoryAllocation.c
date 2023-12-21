#include<stdio.h>
#include <stdlib.h>
void performing(int *ptr,int *n,int *sum);
int main(){
    int n1,n2,n3;
    int *ptr;
    int sum=0;
    printf("enter the number of elements n1 : ");
    scanf("%d",&n1);
     printf("enter the number of elements n2 : ");
    scanf("%d",&n2);
     printf("enter the number of elements n3 : ");
    scanf("%d",&n3);
    ptr = (int*)malloc(n1*sizeof(int));
  performing(&ptr,&n1,&sum);

  /* if(ptr == NULL){
        printf("memory not allocated.");
        exit(0);
    }
    printf("enter elements: ");
    for( int i=0;i<n1;i++){
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("sum = %d",sum);*/


    ptr = realloc(ptr, n2 * sizeof(int));
    free(ptr);
    ptr = (int*) calloc(n3, sizeof(int));
    free(ptr);
    return 0;
}
void performing(int *ptr,int *n,int *sum){
    //printf("working");
    if(ptr == NULL){
        printf("memory not allocated.");
        exit(0);
    }
    printf("enter elements: ");
    for( int i=0;i<n;i++){
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("sum = %d",sum);
}
