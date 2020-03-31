/* 
    在一排树中，第 i 棵树产生 tree[i] 型的水果。
    你可以从你选择的任何树开始，然后重复执行以下步骤：


        把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
        移动到当前树右侧的下一棵树。如果右边没有树，就停下来。


    请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。

    你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
    用这个程序你能收集的水果总量是多少？

 */
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
int totalFruit(int* tree, int treeSize){
    if(!tree||treeSize==0){
        return 0;
    }
    if(treeSize<2){
        return treeSize;
    }
    int i,j,max=0;
    int temp1,temp2,flag=0;
    for(i=0;i<treeSize-1;i++){
        temp1=tree[i];
        if(treeSize-i<max){
            break;
        }
        for(j=i+1;j<treeSize;j++){
            if(tree[j]==temp1){//
                continue;
            }
            else if(flag==0&&tree[j]!=temp1){//第二种树的给出
                temp2=tree[j];
                flag=1;
            }
            if(tree[j]!=temp1&&tree[j]!=temp2){//第三种树
                break;
            }
        }
        max=MAX(max,j-i);
        flag=0;
    }
    return max;
}