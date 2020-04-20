/* 
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。

返回你可以印出的非空字母序列的数目。

注意：本题中，每个活字字模只能使用一次。 
*/
int numTilePossibilities(char * tiles){
    int *tile = (int *)calloc(sizeof(int), 26);
    int lens=strlen(tiles);
    int res=0;
    for(int i=0;i<lens;i++) {
        tile[tiles[i]-'A']++;
    }
    traceback(tile,&res);
    free(tile);
    return res;
}
void traceback(int* tile,int* result) {
    for(int i=0;i<26;i++) {
        if(tile[i]<=0) {
            continue;
        }
        tile[i]--;
         (*result)++;
        traceback(tile, result);
        tile[i]++;
    }
}