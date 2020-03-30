/* 
    给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

    若可行，输出任意可行的结果。若不可行，返回空字符串。

 */
#define ARRSIZE 26

typedef struct map{
    char key;
    int val;
} node;

void mapInit(node** p){
    for(int i = 0;i < ARRSIZE;i++){
        node* pNode = (node*)malloc(sizeof(node));
        pNode->key = 'a' + i;
        pNode->val = 0;
        p[i] = pNode;
    }
    return;
}

void mapFree(node** p){
    for(int i = 0;i < ARRSIZE;i++){
        free(p[i]);
    }
    free(p);
    return;
}

int cmp(const void* a, const void* b) {
    return ((node**)b)[0]->val - ((node**)a)[0]->val;
}

char* reorganizeString(char* S) {
    int len = strlen(S), i, j, k = (len + 1) / 2;
    node** p = (node**)malloc(sizeof(node*) * ARRSIZE);
    mapInit(p);
    for (i = 0; S[i] != '\0'; i++) {
        ((p[(S[i] - 'a')])->val)++;
    }
    qsort(p, ARRSIZE, sizeof(node**), cmp);
    if (p[0]->val > k) {
        return "";
    }
    else {
        i = 0;
        j = 0;
        while (i < len) {
            S[i] = p[j]->key;
            --(p[j]->val);
            if (p[j]->val == 0) {
                ++j;
            }
            i += 2;
        }
        i = 1;
        while (i < len) {
            S[i] = p[j]->key;
            --(p[j]->val);
            if (p[j]->val == 0) {
                ++j;
            }
            i += 2;
        }
    }
    mapFree(p);
    return S;
}
