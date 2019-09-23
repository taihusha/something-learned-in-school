#include<iostream>
#include<windows.h>
#define N 5
int chopstick[N]={1,1,1,1,1};
HANDLE philosophers[N];
HANDLE mutex;   //typedef void* HANDLE, 用于输出
typedef struct _thread_philosopher_num
{
    int num;
}philosopher_num;
int signal=4;
void eat(int i){
    WaitForSingleObject(mutex, INFINITE);//安全输出，保证不被抢占
    printf("%d philosopher is eating\n",i);
    ReleaseMutex(mutex);
    Sleep(1000);
}
void thinking(int i){
    WaitForSingleObject(mutex, INFINITE);//安全输出，保证不被抢占
    printf("%d philosopher is thinking\n",i);
    ReleaseMutex(mutex);
    Sleep(1000);
}
void take_fork(int i,int num){
    int flag=1;
    while(1){
        if(chopstick[i]>0){
            chopstick[i]--;
            WaitForSingleObject(mutex, INFINITE);//安全输出，保证不被抢占
            printf("%d philosopher is picking the %d chopstick\n",num,i);
            ReleaseMutex(mutex);
            break;
        }
        else if(flag==1&&chopstick==0){
            flag--;
            WaitForSingleObject(mutex, INFINITE);//安全输出，保证不被抢占
            printf("waiting for the %d chopstick\n",i);
            ReleaseMutex(mutex);
        }
    }    
}
void put_fork(int i,int num){
    if(chopstick[i]==0){
            chopstick[i]++;
            WaitForSingleObject(mutex, INFINITE);//安全输出，保证不被抢占
            printf("%d philosopher is put down the %d chopstick\n",num,i);
            ReleaseMutex(mutex);
        }
}
void p(int signal){
    while(1){
        if(signal>0){
            signal--;
            break;
        }
        else{
            WaitForSingleObject(mutex, INFINITE);//安全输出，保证不被抢占
            printf("waiting for the chopstick");
            ReleaseMutex(mutex);
        }
    }
    
}
void v(int signal){
    signal++;
}
DWORD WINAPI philosopher(LPVOID lpParam) //死锁解法
{
    philosopher_num* pThreadNum=(philosopher_num*)lpParam;
    #define t pThreadNum->num
    while(true){
        thinking(t);
        p(signal);
        take_fork(t,t);//先拿左边筷子
        take_fork((t+1)%N,t);//再拿右边筷子
        eat(t);
        put_fork(t,t);//先放左边筷子
        put_fork((t+1)%N,t);//再放右边筷子
        v(signal);

    }
}
/* void philosopher();//非死锁解法
{

} */
int main()
{
    philosopher_num Pnum[N];
    mutex = CreateMutex(NULL, false, NULL); //创建一个互斥变量
    for(int i=0;i<N;i++){
        Pnum[i].num=i;
        philosophers[i]=CreateThread(NULL,0,philosopher,&Pnum[i],0,NULL);
    }
    WaitForMultipleObjects(N,philosophers,false,INFINITE);
    for(int i=0;i<N;i++){
        CloseHandle(philosophers[i]);
    }
    return 0;
}