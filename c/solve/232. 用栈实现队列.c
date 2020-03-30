/* 
    使用栈实现队列的下列操作：
        push(x) -- 将一个元素放入队列的尾部。
        pop() -- 从队列首部移除元素。
        peek() -- 返回队列首部的元素。
        empty() -- 返回队列是否为空。
 */
typedef struct {
    int front;//队首元素下标
    int back;//队尾元素下标
    int val[10000];//用于存放队列值的数组结构 
    
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(int) * 10002);
    obj->front=0;
    obj->back=0;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->val[obj->back]=x;
    (obj->back)++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int res=obj->val[obj->front];
    obj->val[obj->front]=0;
    (obj->front)++;
    return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->val[obj->front];
}   

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->front==obj->back);
}

void myQueueFree(MyQueue* obj) {
    obj->front = 0;
    obj->back = 0;
    memset(obj->val, 0, sizeof(int) * 10000);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/