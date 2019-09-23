/*   SECURITY_ATTRIBUTES sa;
    sa.bInheritHandle = TRUE;//表示可被子进程所继承 
    sa.lpSecurityDescriptor = NULL; //安全描述符号一般都设置成NULL，即默认描述符
    sa.nLength = sizeof(SECURITY_ATTRIBUTES); //管道长度
 */
   /* BOOL WINAPI CreatePipe(
      PHANDLE hReadPipe,//读取端句柄
      PHANDLE hWritePipe,//输入端句柄
      LPSECURITY_ATTRIBUTES lpPipeAttributes,//安全属性
      DWORD nSize// 管道的缓冲区容量，NULL表示默认大小
    ); */
   /*  BOOL ReadFile(
      HANDLE hFile,//句柄，可以是标准输入输出流或文件或管道
      LPVOID lpBuffer,  //读取的数据写入缓冲区
      DWORD nNumberOfBytesToRead,//指定读取的字节数
      LPDWORD lpNumberOfBytesRead,//实际读取的字节数
      LPOVERLAPPED lpOverlapped//用于异步操作,一般置为NULL
    ); */
  /*   BOOL WriteFile(
      HANDLE hFile,//句柄，同上
      LPCVOID lpBuffer,//指定待写入的数据
      DWORD nNumberOfBytesToWrite,//写入的数据量
      LPDWORDlp NumberOfBytesWritten,//实际要写的数据量
      LPOVERLAPPED lpOverlapped//一般置为NULL
    ); */
 /*    STARTUPINFO si; 
    si.hStdInput   = hPipeInputRead;   //输入由标准输入 -> 从管道中读取  
    si.hStdOutput  = hPipeOutputWrite; //输出由标准输出 -> 输出到管道  */
#include "windows.h"
#include "stdio.h"

HANDLE hReadPipeCmd = NULL;
HANDLE hWritePipeCmd = NULL;
HANDLE hReadPipeShell = NULL;
HANDLE hWritePipeShell = NULL;//shell
HANDLE hProcessHandle;        //进程句柄

char readBuff[4096]="\x00";
char writeBuff[256]="\x00";
//BOOL initPipeSuccess = FALSE;

void initPipe();
void shell();

int main(int argc, char* argv[])
{   
    while(1)
    {
        scanf("%s",writeBuff);
        strcat(writeBuff,"\r\n");//这个是关键，必须加上回车换行!否则不会回显！
        shell();
        printf("%s",readBuff);//很关键
        memset(readBuff, 0, sizeof(readBuff));
        getchar();
    }
}

void shell()
{
    //if(initPipeSuccess == FALSE)
        initPipe();

    DWORD dwByteWritten;

    WriteFile(hWritePipeShell,writeBuff,strlen(writeBuff),&dwByteWritten,0);//写管道
    printf("写入字节数:%d\n",dwByteWritten);
    memset(writeBuff,0,256);

    //Sleep(1000);

    unsigned long   BytesRead = 0;
    DWORD TotalBytesAvail;

    //检查管道中是否有数据
    while (PeekNamedPipe(hReadPipeCmd,readBuff, sizeof(readBuff), &BytesRead, &TotalBytesAvail, NULL)) 
    {
        if (TotalBytesAvail <= 0)
            Sleep(600);
        else
        {
            //printf("有数据到来!\n");
            memset(readBuff, 0, sizeof(readBuff));
            if(BytesRead==TotalBytesAvail)
            {
                ReadFile(hReadPipeCmd, readBuff, TotalBytesAvail+100, &BytesRead, NULL);
                break;
            }
        }
    }
}
//创建双管道和创建cmd进程
void initPipe()
{
    SECURITY_ATTRIBUTES sa = {0}; 
    STARTUPINFO         si = {0};
    PROCESS_INFORMATION pi = {0};

    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL; 
    sa.bInheritHandle = TRUE;
    //创建管道
    CreatePipe(&hReadPipeCmd,&hWritePipeCmd,&sa,0);
    CreatePipe(&hReadPipeShell,&hWritePipeShell,&sa,0);

    GetStartupInfo(&si);
    si.cb = sizeof(STARTUPINFO);
    si.wShowWindow = SW_HIDE;
    si.dwFlags = STARTF_USESTDHANDLES|STARTF_USESHOWWINDOW;
    si.hStdInput = hReadPipeShell;
    si.hStdOutput = si.hStdError = hWritePipeCmd; 
    //找到cmd的绝对路径
    char strShellPath[256]="\x00";
    GetSystemDirectory(strShellPath, 256);
    strcat(strShellPath,"\\cmd.exe");
    //创建cmd进程
    if (!CreateProcess(strShellPath,NULL, NULL, NULL,TRUE,NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi)) 
    {
        //printf("CreateProcess Error!\n");
        CloseHandle(hWritePipeCmd);
        CloseHandle(hReadPipeShell);
        //initPipeSuccess = FALSE;
        return;
    }
    hProcessHandle = pi.hProcess;
    //initPipeSuccess = TRUE;
}
