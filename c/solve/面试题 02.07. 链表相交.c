/* 
    给定两个（单向）链表，判定它们是否相交并返回交点。
    
    请注意相交的定义基于节点的引用，而不是基于节点的值。
    
    换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
 */

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //相等条件：headA->next=headB->next
    struct ListNode* p1=headA;
    struct ListNode* p2=headB;
    
    while(p1!=p2) {
        if(p1) {
            p1=p1->next;
        }
        else {
            p1=headB;
        }
        if(p2) {
            p2=p2->next;
        }
        else {
            p2=headA;
        }
    }
    return p1;
    
}