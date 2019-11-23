/* 假设工资税金按以下方法计算：
   0 < x ＜ 1000元，不收取税金；
1000 ≤ x ＜ 2000，收取5%的税金；
2000 ≤ x ＜ 3000，收取10%的税金；
3000 ≤ x ＜ 4000，收取15%的税金；
4000 ≤ x ＜ 5000，收取20%的税金；
x＞5000，收取25%的税金。
编写一个程序,输入工资金额，输出应收取税金额度，要求分别用if语句和switch语句来实现。 */
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int pay,flag;
    double taxes_if,taxes_switch;
    scanf("%d",&pay);
    if(pay<1000){
        taxes_if=0;
        flag=0;
    }
    else if(pay>=1000&&pay<2000){
        taxes_if=pay*0.05;
        flag=1;
    }
    else if (pay>=2000&&pay<3000){
        taxes_if=pay*0.1;
        flag=2;
    }
    else if (pay>=3000&&pay<4000){
        taxes_if=pay*0.15;
        flag=3;
    }
    else if (pay>=4000&&pay<5000){
        taxes_if=pay*0.2;
        flag=4;
    }
    else if (pay>5000){
        taxes_if=pay*0.25;
        flag=5;
    }
    printf("the taxes is %.2f\n",taxes_if);
    switch (flag)
    {
    case 0:
        taxes_switch=0;
        break;
    case 1:
        taxes_switch=pay*0.05;
        break;
    case 2:
        taxes_switch=pay*0.1;
        break;
    case 3:
        taxes_switch=pay*0.15;
        break;
    case 4:
        taxes_switch=pay*0.2;
        break;
    case 5:
        taxes_switch=pay*0.25;
        break;
    default:
        break;
    } 
    printf("the taxes is %.2f\n",taxes_switch);
    system("pause");
    return 0;
}