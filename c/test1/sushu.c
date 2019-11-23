#include<stdio.h>
#include<stdlib.h>
int main() {
    //编写一个程序，输入一个数，判断它是不是素数
    int num;
    bool flag=false;
    printf("Input the num\n");
    scanf("%d",&num);
    for(int i=2;i<num;i++){
        if(num%i!=0){//未出现整除时，循环继续
            continue;
        }
        else if(num%i==0){//出现整除时，说明为合数，跳出循环
            flag=true;
            break;
        }
    }
    if(!flag){
        printf("the num %d is sushu",num);
    }
    else if(flag){
        printf("the num %d is not sushu",num);
    }
    system("pause");
    return 0;
}