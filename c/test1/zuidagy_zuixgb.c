#include<stdio.h>
#include<stdlib.h>
int zuidagongyue(int a,int b){
    int temp=a;
    while(b%a!=0){
        temp=b%a;
        b=a;
        a=temp;
    }
    return temp;
}
int zuixiaogongbs(int a,int b){
    int temp=zuidagongyue(a,b);
    int resa=a/temp;
    int resb=b/temp;
    return (temp*resa*resb);
}
int main(){
    int numA,numB;
    int resXGB,resDGY;
    printf("Input the two num:\n");
    scanf("%d %d",&numA,&numB);
    if(numA>numB){
        numA^=numB;
        numB^=numA;
        numA^=numB;
    }
    resXGB=zuixiaogongbs(numA,numB);
    resDGY=zuidagongyue(numA,numB);
    printf("num %d and num %d de zui da gongyueshu is %d,zui xiao gongbeishu is %d",numA,numB,resDGY,resXGB);
    system("pause");
    return 0;
}
