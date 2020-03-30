/**
 * 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//另一种：双指针暴力求解
struct ListNode {
      int val;
      struct ListNode *next;
};
struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode* pre=head;
    struct ListNode *p=head->next;
    int hash[20001]={0};
    hash[head->val]=1;
    while(p!=NULL){
        if(hash[p->val]==0){//第一次出现
            hash[p->val]=1;
            pre=p;
            p=p->next;
        }
        else if(hash[p->val]==1){//重复出现
            pre->next=p->next;
            p=pre->next;
        }
    }
    return head;
}