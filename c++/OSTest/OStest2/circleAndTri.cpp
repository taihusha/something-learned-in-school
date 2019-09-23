#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
CRITICAL_SECTION cs;//定义临界区全局变量
DWORD WINAPI circle(LPVOID lpParam)
{
    EnterCriticalSection(&cs);
    double y,m;
    int x;
    for(y=10;y>=-10;y--)
    {
        m=2.2*sqrt(100-y*y);

        for(x=1;x<30-m;x++)
        {
            printf(" ");
        }
        printf("*");
        Sleep(100);
        for(;x<30+m;x++)
        {
            printf(" ");
        }
        printf("*\n");
        Sleep(100);
    }
    LeaveCriticalSection(&cs);
    return 0;
}
DWORD WINAPI Rectangle(LPVOID lpParam)
{
    EnterCriticalSection(&cs);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("*");
            Sleep(100);
        }
        printf("\n");
    }
    LeaveCriticalSection(&cs);
    return 0;
}
int main()
{
    InitializeCriticalSection(&cs);
    HANDLE threadC=CreateThread(NULL,0,circle,NULL,0,NULL);
    HANDLE threadT=CreateThread(NULL,0,Rectangle,NULL,0,NULL);
    
    WaitForSingleObject(threadC,INFINITE);
    WaitForSingleObject(threadT,INFINITE);
    CloseHandle(threadC);
    CloseHandle(threadT);
    DeleteCriticalSection(&cs);
    system("pause");
    return 0;
}