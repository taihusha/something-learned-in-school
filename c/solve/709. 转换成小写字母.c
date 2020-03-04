/*  
    实现函数 ToLowerCase()，该函数接收一个字符串参数 str，

    并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

 */
char * toLowerCase(char * str){
    int i;
    for(i=0;str[i]!='\0';i++){
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
    return str;
}