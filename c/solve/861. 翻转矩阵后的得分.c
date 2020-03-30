/* 
    有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

    移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

    在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

    返回尽可能高的分数。

 */
int matrixScore(int** A, int ASize, int* AColSize){
    int i,j;
    //使第一列为1
    for(i=0;i<ASize;i++){
        j=0;
        if(A[i][j]==0){
            while(j<AColSize[i]){
                A[i][j]^=0x01;
                j++;
            }
            
        }
    }
    //使后续列的1可能多
    int count;//记录当前列的0（1）的数量
    int res=ASize;//记录结果
    for(j=1;j<AColSize[0];j++){
        count=0;
        for(i=0;i<ASize;i++){
            if(A[i][j]==1){
                count++;
            }
        }
        if(ASize-count>count){
            count=ASize-count;
        }
        res=(res<<1)+count;
    }
    return res;
}