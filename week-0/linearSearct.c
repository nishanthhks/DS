#include<stdio.h>
int linearSearch(int arr[],int target,int arrLen);
int main()
{
    int arr[5] = {5,7,11,21,60};
    int target = 11;
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    printf("%d",linearSearch(arr,target,arrLen));
    return 0;
}
int linearSearch(int arr[],int target,int arrLen)
{
    for(int i = 0 ; i<arrLen ; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}