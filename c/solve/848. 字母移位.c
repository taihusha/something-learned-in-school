/* 
有一个由小写字母组成的字符串 S，和一个整数数组 shifts。

我们将字母表中的下一个字母称为原字母的 移位（由于字母表是环绕的， 'z' 将会变成 'a'）。

例如·，shift('a') = 'b'， shift('t') = 'u',， 以及 shift('z') = 'a'。

对于每个 shifts[i] = x ， 我们会将 S 中的前 i+1 个字母移位 x 次。

返回将所有这些移位都应用到 S 后最终得到的字符串。

 */
char shift(char c,long num);
char * shiftingLetters(char * S, int* shifts, int shiftsSize){
    long sum=0;
    //前i个字母移动shifts[i]次,所以逆序处理，处理数依次叠加
    for(int i=shiftsSize-1;i>=0;i--) {
        sum+=shifts[i];
        S[i]=shift(S[i],sum);
    }
    return S;
}
char shift(char c,long num) {
    long _num=num%26;
    if(c+_num>'z') {
        return 'a'-1+c+_num-'z';
    }
    return c+_num;
}