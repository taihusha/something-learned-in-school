/* 
    给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
    
    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
*/
#define MIN(a,b) ((a)<(b))?(a):(b)
int countSubstrings(char * s){
//马拉车法
//首先对原始字符串进行修改
    int len=strlen(s);
    char ss[2*len+3];
    ss[0]='@';
    ss[1]='#';
    for(int i=0;i<len;i++) {
        ss[2*(i+1)]=s[i];
        ss[2*i+3]='#';
    }
    ss[2*len+2]='!';
//开始计算以每个字符为中心的最大半径
    int llen=2*len+3;
    int z[llen];
    for(int i=0;i<llen;i++) {
        z[i]=0;
    }
    int center=0,right=0;
    for(int i=1;i<llen-1;i++) {
        if(i<right) {
            z[i]=MIN(right-i,z[2*center-i]);
        }
        while (ss[i + z[i] + 1] == ss[i - z[i] - 1])
                z[i]++;
        if(i+center>right) {
            center=i;
            right=center+z[i];
        }
    }
    int sum=0;
    for(int i=0;i<llen;i++) {
        sum+=(z[i]+1)/2;
    }
    return sum;
}