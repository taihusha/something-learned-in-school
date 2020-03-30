/* 
    设计链表的实现。您可以选择使用单链表或双链表。

    单链表中的节点应该具有两个属性：val 和 next。
    
    val 是当前节点的值，next 是指向下一个节点的指针/引用。
    
    如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。
    
    假设链表中的所有节点都是 0-index 的。

    在链表类中实现这些功能：
        get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
        addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
        addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
        addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
        deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 */
#include <memory.h> 
typedef struct node Node;
typedef struct node {
    int   val;
    Node* prev;
    Node* next;
} ;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    memset(node, 0, sizeof(Node));
    node->val = val;
    return node;
}

typedef struct {
    Node* head;
    Node* tail;
    int   count;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    memset(list,0,sizeof(MyLinkedList));
    return list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index<0||obj->count<=index){
        return -1;
    }
    Node* node=obj->head;
    if(index<(obj->count-index)) {
        while(index>0) {
            node=node->next;
            index--;
        }
    } 
    else {
        node=obj->tail;
        int n=obj->count-index-1;
        while(n>0) {
            node=node->prev;
            n--;
        }
    }
    return node->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node=newNode(val);
    node->next=obj->head;
    if(obj->head) {
        obj->head->prev=node;
    }
    obj->head=node;
    if(obj->tail==nullptr) {
        obj->tail=node;
    }
    obj->count++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node=newNode(val);
    node->prev=obj->tail;
    if(obj->tail) {
        obj->tail->next=node;
    }
    obj->tail=node;
    if(obj->head==nullptr) {
        obj->head=node;
    }
    obj->count++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->count) {
        return;
    } else if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
    } else if (index == obj->count) {
        myLinkedListAddAtTail(obj, val);
    } else {
        Node* node = obj->head;
        if (index < (obj->count - index)) {
            while (index > 0) {
                node = node->next;
                index--;
            }
        } else {
            node = obj->tail;
            int n = obj->count - index - 1;
            while (n > 0) {
                node = node->prev;
                n--;
            }
        }
        Node* nd = newNode(val);
        nd->prev = node->prev;
        node->prev->next = nd;
        nd->next = node;
        node->prev = nd;
        obj->count++;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->count) {
        return;
    }
    if (index == 0) {
        Node* node = obj->head;
        obj->head = node->next;
        if (obj->head)
            obj->head->prev = nullptr;
        free(node);
        obj->count--;
        return;
    } else if (index == obj->count - 1) {
        Node* node = obj->tail;
        obj->tail = node->prev;
        if (obj->tail)
            obj->tail->next = nullptr;
        free(node);
        obj->count--;
        return;
    }
    Node* node = obj->head;
    if (index < (obj->count - index)) {
        while (index > 0) {
            node = node->next;
            index--;
        }
    } else {
        node = obj->tail;
        int n = obj->count - index - 1;
        while (n > 0) {
            node = node->prev;
            n--;
        }
    }
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
    obj->count--;
    free(node);
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* node=obj->head;
    while(node){
        Node* tmp=node->next;
        free(node);
        node=tmp;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/