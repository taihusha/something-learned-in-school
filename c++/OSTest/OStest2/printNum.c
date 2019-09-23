#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
DWORD WINAPI printNum_1_1000(LPVOID lpParam)
{
    int i=1;
    while(i<1001)
    {
        printf("A:%d\n",i);
        i++;
        Sleep(500);
    }
    return 0;
}
DWORD WINAPI printNum_1000_1(LPVOID lpParam)
{
    int i=1000;
    while(i>0)
    {
        printf("B:%d\n",i);
        i--;
        Sleep(500);
    }
    return 0;
}
int main()
{

   /*  HANDLE CreateThread(
  LPSECURITY_ATTRIBUTES   lpThreadAttributes,
  SIZE_T                  dwStackSize,
  LPTHREAD_START_ROUTINE  lpStartAddress,
  __drv_aliasesMem LPVOID lpParameter,
  DWORD                   dwCreationFlags,
  LPDWORD                 lpThreadId
  ); */
/* lpThreadAttrivutes：指向SECURITY_ATTRIBUTES的指针，用于定义新线程的安全属性，一般设置成NULL；
dwStackSize：分配以字节数表示的线程堆栈的大小，默认值是0；
lpStartAddress：指向一个线程函数地址。每个线程都有自己的线程函数，线程函数是线程具体的执行代码；
lpParameter：传递给线程函数的参数；
dwCreationFlags：表示创建线程的运行状态，其中CREATE_SUSPEND表示挂起当前创建的线程，而0表示立即执行当前创建的进程；
lpThreadID：返回新创建的线程的ID编号；
如果函数调用成功，则返回新线程的句柄，调用WaitForSingleObject函数等待所创建线程的运行结束。 */
    HANDLE threadA,threadB;
//    PDWORD threadIDa,threadIDb;
    threadA=CreateThread(NULL,0,printNum_1_1000,NULL,0,NULL);
    threadB=CreateThread(NULL,0,printNum_1000_1,NULL,0,NULL);

    WaitForSingleObject(threadA,INFINITE);
    WaitForSingleObject(threadB,INFINITE);
    CloseHandle(threadA);
    CloseHandle(threadB);
    return 0;
}