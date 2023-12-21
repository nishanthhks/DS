#include<stdio.h>
int binarySearch(int arr[],int target,int arrLen);
int main()
{
    int arr[5] = {5,7,11,21,60};
    int target = 60;
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    printf("%d",binarySearch(arr,target,arrLen));
    return 0;
}
int binarySearch(int arr[],int target,int arrLen)
{
    int start = 0;
    int end = arrLen-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
}
