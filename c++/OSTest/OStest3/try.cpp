
//#include "stdafx.h"

#include <windows.h>  //HADNDLE

#include <process.h>

//#include <time.h>  //time(0)

//#include <stdlib.h>

#include "iostream"

 

using namespace std;

 

const unsigned int N=5;    //哲学家数目

const int THINKING=1;     //标记当前哲学家的状态,1表示思考(饱的)

const int HUNGRY=2;      //2表示得到饥饿,3表示正在吃饭

const int DINING=3;

 

HANDLE hPhilosopher[N];  

HANDLE semaphore[N];

 

HANDLE mutex;   //typedef void* HANDLE, 用于输出

 

DWORD WINAPI philosopherProc(LPVOID lpParameter) //返回DWORD(32位数据)的API函数

//typedef unsigned long DWORD 

//typedef WINAPI __stdcall 函数参数入栈方式从右到左,一般导出函数时用。

//typedef void* LPVOID

{

 

	char stateStr[128];

	int ret;

 

	unsigned int leftFork;  //左右筷子

	unsigned int rightFork;

 

	int myid = int(lpParameter);

 

	WaitForSingleObject(mutex, INFINITE);	//安全输出						

	cout << "philosopher" << myid << " begin....." << endl;

	ReleaseMutex(mutex);

 

	int mystate = THINKING;  //初始状态在思考

	leftFork = (myid)%N;

	rightFork = (myid+1)%N;

 

	while(true)   //注意这里的while(true)，也就是说，它一直在这几种状态之间转换。

	{

		switch(mystate)   //状态的转变

		{

		case THINKING:

			mystate = HUNGRY;	//thinking直接转hungry

			strcpy(stateStr, "HUNGRY");

			break;

		case HUNGRY:

			strcpy(stateStr, "HUNGRY");

			ret = WaitForSingleObject(semaphore[leftFork], //先看左手

							0);//第二个参数，等待时间

			if(ret == WAIT_OBJECT_0)

			{

				ret = WaitForSingleObject(semaphore[rightFork],0);

				if (ret == WAIT_OBJECT_0)

				{

					mystate = DINING;

					strcpy(stateStr, "DINING");

				}

				else

					ReleaseSemaphore(semaphore[leftFork],1,NULL);

			}

			break;

		case DINING:

			ReleaseSemaphore(semaphore[leftFork],1,NULL);

			ReleaseSemaphore(semaphore[rightFork],1,NULL);

			mystate = THINKING;

			strcpy(stateStr, "THINKING");

			break;

		}

	WaitForSingleObject(mutex, INFINITE);//安全输出，保证不被抢占

	cout << "philosopher" << myid << " is: " << stateStr << endl;

	ReleaseMutex(mutex);

	//sleep 100ms

	Sleep(100);

	}

}

 

int main()

{

	//srand(time(0));

 

	mutex = CreateMutex(NULL, false, NULL); //创建一个互斥变量

	for (int i = 0; i < N; i++)

	{

		semaphore[i] = CreateSemaphore(NULL, 1, 1, NULL); //创建一个新的信号量

 

		hPhilosopher[i] = CreateThread(NULL, 0,   //线程安全属性，堆栈大小

			philosopherProc, LPVOID(i),       //线程函数,线程参数(这里，把i转成LPVOID传递)

			CREATE_SUSPENDED, 0);   //线程创建属性（这里是挂起，所以下面有唤起），线程ID

	}

 

	for (int i = 0; i < N; i++)

	{

		ResumeThread(hPhilosopher[i]); //线程恢复函数

	}

	Sleep(800);//给时间线程执行
    getchar();
	return 0;

}
