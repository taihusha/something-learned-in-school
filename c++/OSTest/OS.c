#include <stdio.h>
#include <windows.h>
int main()
{
     STARTUPINFO si = {sizeof(si)};
    PROCESS_INFORMATION pi;
    si.dwFlags=STARTF_USESHOWWINDOW;
    si.wShowWindow=TRUE;
    char *zw="test.exe";
    char *zw2="binary.exe";
    char *zw3="fileAndThread.exe";
    ::CreateProcess(NULL,zw,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    ::CreateProcess(NULL,zw2,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    ::CreateProcess(NULL,zw3,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    system("pause");
    return 0;
}