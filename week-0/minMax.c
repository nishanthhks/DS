#include<stdio.h>
int minumum(int arr[],int arrLen);
int maximum(int arr[],int arrLen);
int main()
{
    int arr[5] = {5,7,11,21,60};
    int target = 11;
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    printf("%d\t",minumum(arr,arrLen));
    printf("%d",maximum(arr,arrLen));
    return 0;
}
int minumum(int arr[],int arrLen){
    int min = arr[0];
    for(int i=0 ; i<arrLen ; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}
int maximum(int arr[],int arrLen){
    int max = arr[0];
    for(int i=0 ; i<arrLen ; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}