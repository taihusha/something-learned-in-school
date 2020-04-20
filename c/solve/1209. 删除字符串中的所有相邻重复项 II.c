/*
给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。

你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。

在执行完所有删除操作后，返回最终得到的字符串。

本题答案保证唯一。
*/
char * removeDuplicates(char * s, int k){
    //双指针
    int point_s=0,point_f=-1;
    int count;
    while(s[point_s]) {
        count=1;
        while(s[point_s]==s[point_s+1]) {
            count++;
            point_s++;
        }
        for(int i=0;i<count%k;i++){
            point_f++;
            s[point_f] = s[point_s];
        }
        point_f--;
        count=1;
        while(point_f>=0&&s[point_f]==s[point_f+1]) {
            point_f--;
            count++;
        }
        point_f+=count%k;
        point_s++;
    }
    s[point_f+1]='\0';
    return s;
}