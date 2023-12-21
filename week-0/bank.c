#include<stdio.h>
#include<stdlib.h>
void Create_Account();
int Withdraw();
int Deposit();
void main(){
    int n=0;
    int bal=100000;
    printf("Enter:-\n1 to Make new account\n2 to Withdraw\n3 to Deposit\n4 to Check balance\n5 to Exit\n");
    while(n!=5){
        scanf("%d",&n);
        switch(n){
            case 1: Create_Account();
                    break;
            case 2: int with=Withdraw();
                    bal=bal-with;
                    printf("amount withdrawn successfully");
                    
                    break;
            case 3: int dep=Deposit();
            bal=bal+dep;
              printf("amount deposited successfully");
                    
                    break;
            case 4: printf("Balance is %d",bal);
                    break;
            case 5: break;
            default: printf("Invalid input");
        }
    }
}
void Create_Account(){
    char n[100];
    int a;
    printf("Enter account name: \n");
    scanf("%s", n);
    printf("Enter age");
    scanf("%d",&a);
    printf("account created successfully");
    exit(0);
}
int Withdraw(){
    int num;
    printf("Enter amount to withdraw: ");
    scanf("%d",&num);
    return num;
}
int Deposit(){
    int num;
    printf("Enter amount to deposit: ");
    scanf("%d",&num);
    return num;
}
