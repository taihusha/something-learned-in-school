/* 
    稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。 
*/

int findString(char** words, int wordsSize, char* s){
    int i;
    char **word=words;
    char* c;
    int len=strlen(s);
    for(i=0;i<wordsSize;i++){
        c=word[i];
        if(word[i][0]==s[0]){
            if(strlen(c)==len){
                if(memcmp(c,s,len)==0){
                    return i;
                }
            }
        }
        }
    return -1;
}