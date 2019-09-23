/* 问题描述：一组生产者进程和一组消费者进程共享一个初始为空大小为n的缓冲区，只有缓冲区没满时，
生产者才能给缓冲区投放信息，否则必须等待；只有缓冲区不空时，消费者才能继续取出消息，否则也必须等待。
由于缓冲区是临界资源，他只允许一个进程投放资源或者一个进程取出资源。 */
#include <Windows.h>
#include <stdio.h>
#define N 10
#define TRUE 1
typedef int Semaphore;
Semaphore mutex = 1;           //互斥信号量
Semaphore full = 0, Empty = N; //临界区满槽数目和空槽数目
int in = 0, out = 0;           //缓冲区生产，消费数据指针
HANDLE ProducerThread[2];
int ConsumerThread[3];
int Buffer[N];               //缓冲区

int produce_item1() {           //生产随机数
    return rand()%1000 + 1000;
}
int produce_item2() {           //生产随机数
    return rand()%1000 + 2000;
}

int insert_item(int item) {    //插入临界区
    in %= N;
    printf("produce to buffer: %d\n",in);
    freopen("information.txt","a",stdout);
    printf("produce to buffer: %d\n",in);
    freopen("CON","w",stdout);

    Buffer[in] = item;
    return Buffer[in++];
}

int remove_item() {            //移出临界区
    out %= N;
    printf("                        remove item from buffer,num: %d \n",out);
    freopen("information.txt","a",stdout);
    printf("                        remove item from buffer,num: %d \n",out);
     freopen("CON","w",stdout);
    return Buffer[out++];
}

int consume_item(int item) {
    //consume it
}

DWORD WINAPI producer1(LPVOID lpParam) {

    int item;

    while(TRUE) {

        item = produce_item1();     //生产物品
        Empty--;                   //P(Empty)
        if(Empty < 0)              //没有空槽可以添加数据
            Empty++;               //还原Empty，继续循环等待
        else if(mutex > 0) {       //否则如果mutex = 1,临界区未被访问
            mutex--;               //加锁,p(mutex)
            insert_item(item);     //往临界区填入数据
            full++;                //满槽数加1,v(full)
            mutex++;               //释放锁
        }
        Sleep((rand()%901)+100);
    }
    return 1;
}

DWORD WINAPI producer2(LPVOID lpParam) {

    int item;

    while(TRUE) {

        item = produce_item2();     //生产物品
        Empty--;                   //P(Empty)
        if(Empty < 0)              //没有空槽可以添加数据
            Empty++;               //还原Empty，继续循环等待
        else if(mutex > 0) {       //否则如果mutex = 1,临界区未被访问
            mutex--;               //加锁,p(mutex)
            insert_item(item);     //往临界区填入数据
            full++;                //满槽数加1,v(full)
            mutex++;               //释放锁
        }
        Sleep((rand()%901)+100);
    }
    return 1;
}
DWORD WINAPI consumer(LPVOID lpParam) {

    int item;

    while(TRUE) {

        full--;                   //P(full)
        if(full < 0)              //如果没有满槽，无法消费
            full++;               //还原full，继续等待
        else if(mutex > 0) {      //否则如果mutex = 1,临界区未被访问
            mutex--;              //加锁
            item = remove_item(); //将数据移出临界区
            consume_item(item);   //消费
            Empty++;              //空槽数目加1,v(empty)
            mutex++;              //释放锁
        }

        Sleep(rand()%901+100);
    }
    return 1;
}

int main()
{
//    DWORD Tid;

    
    ProducerThread[0]=CreateThread(NULL,0,producer1,NULL,0,NULL);
    ProducerThread[1]=CreateThread(NULL,0,producer2,NULL,0,NULL);
    for(int i=0;i<3;i++)
    {
        ConsumerThread[i] = i+1;
        CreateThread(NULL,0,consumer,NULL,0,NULL);
    }
    CloseHandle(ProducerThread[0]);
    CloseHandle(ProducerThread[1]);
    

    Sleep(20000);
    return 0;
}