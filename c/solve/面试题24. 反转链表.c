/* 
    定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。 
*/

// Definition for singly-linked list.
  struct ListNode {
      int val;
     struct ListNode *next;
 };


struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    struct ListNode* p=head->next;
    struct ListNode* pre=head;
    struct ListNode* temp;
    head->next=NULL;
    while(p!=NULL){
        temp=p->next;//获得p的后置结点
        p->next=pre;//逆转使p的后置结点变为前置
        pre=p;//将pre变为p
        p=temp;//将p变为p的后置结点
    }
    return pre;
}