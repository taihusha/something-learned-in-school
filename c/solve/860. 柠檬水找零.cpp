/* 
    难度简单98收藏分享切换为英文关注反馈在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

    顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

    每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

    注意，一开始你手头没有任何零钱。

    如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

 */

bool lemonadeChange(int* bills, int billsSize){
    if(bills[0]!=5){
        return false;
    }
    int i,count_5=1,count_10=0;
    //sum=count_5*5+count_10*10
    for(i=1;i<billsSize;i++) {
        if(bills[i]==5){
            count_5++;
            continue;
        }
        else if(bills[i]==10){
            if(count_5>0){
                count_5--;
                count_10++;
                continue;
            }
            else {
                return false;
            }
        }
        //3张5美元或1张10美元一张5美元,优先使用10美元
        else if(bills[i]==20){
            if(count_5>0&&count_10>0){
                count_5--;
                count_10--;
                continue;
            }
            else if(count_5>=3){
                count_5-=3;
                continue;
            }
            else {
                return false;
            }
        }
    }
    return true;
}
//12ms
bool lemonadeChange(int* bills, int billsSize){
    int n5 = 0;
    int n10 = 0;
    int n20 = 0;
    for(int i = 0; i < billsSize; i++) {
        switch(bills[i]) {
            case 5:
                n5++;
                break;
            case 10:
                n10++;
                n5--;
                break;
            case 20:
                n20++;
                if (n10>0) {
                    n10--;
                    n5--;
                } else {
                    n5 -= 3;
                }
                break;
            default:
                return false;
        }
        if((n5 < 0) ||(n10 < 0)) return false;
    }
    return true;
}