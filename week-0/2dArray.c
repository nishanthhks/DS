#include<stdio.h>
void check(int,int);
void main()
{
int m,n;
printf("enter the number of rows and columns of 2D array");
scanf("%d%d",&m,&n);
check(m,n);

}
void check (int a,int b)
{
    int arr[10][10];int key;
    printf("enter the elements in the array");
    for(int i=0;i<a;i++)
    {
    for(int j=0;j<b;j++)
    {
        scanf("%d",&arr[i][j]);
    }}
    printf("enter element to find");
    scanf("%d",&key);
     for(int i=0;i<a;i++)
    {
    for(int j=0;j<b;j++)
    {
        if(arr[i][j]==key)
        {
            printf("element is found at %d  %d",i,j);
            
        }
    }
    }
}
