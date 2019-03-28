#include <stdio.h>
#include <windows.h>
int main()
{
    HANDLE hFILE=CreateFile("./CommandList.txt", GENERIC_WRITE | GENERIC_READ, 0,NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    //WORD color;
    
  /*   BOOL WriteFile(
        HANDLE hFile,
        LPCVOID lpBuffer,
        DWORD nNumberOfBytesToWrite,
        LPDWORDlpNumberOfBytesWritten,
        LPOVERLAPPEDlpOverlapped
        );
         */
    char timeContent[100] = {0};
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    sprintf(timeContent,"本文件最后一次打开和运行日期是%4d%02d%02d%02dhour%02dmin%02d.%02dsecond \n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds);
    //printf( "%4dyear%02dmonth%02dday  %02dhour%02dmin%02d.%02dsecond   weekday%1d\n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds,sys.wDayOfWeek); 
    DWORD dwwrite=0;
    WriteFile(hFILE,timeContent,strlen(timeContent),&dwwrite,NULL);
    /*
    BOOL ReadFile(
        HANDLE hFile,
        LPVOID lpBuffer,
        DWORD nNumberOfBytesToRead,
        LPDWORD lpNumberOfBytesRead,
        LPOVERLAPPED lpOverlapped
        );
    hFile: 需要读入数据的文件指针 这个指针指向的文件必须是GENERIC_READ访问属性的文件。
    lpBuffer: 接收数据的缓冲区
    nNumberOfBytesToRead: 指定要读取的字节数
    pNumberOfBytesRead: 指向一个DWORD类型变量的指针 用来接收读取的字节 如果下一个参数为NULL 那么一定要传入这个参数
    lpOverlapped: OVERLAPPED结构体指针 如果文件是以FILE_FLAG_OVERLAPPED方式打开的话 那么这个指针就不能为NULL 如果文件打开方式没有指明FILE_FLAG_OVERLAPPED 
    当程序调用成功时 它将实际读出文件的字节数保存到lpNumberOfBytesRead指明的地址空间中
    
*/

    char readbuffer[100]={0};//接受数据的缓冲区
    DWORD dwRead=0;//用来接收读取的字节 
    DWORD fileSize = GetFileSize(hFILE,NULL);//获取读取字节数
    ReadFile(hFILE,readbuffer,fileSize,&dwRead,NULL);
    readbuffer[fileSize]='\0';
    printf("%s",readbuffer);
    CloseHandle(hFILE); 
    char tmpBuffer[1000] = {0};	
    char command[10][100] = {0};       //按行分开的命令
    int commandNum = 0;		       //命令个数
     for(int i=0;i<fileSize;i++)	
    {		
        if('\n' == readbuffer[i])		
        {			
            strncpy(command[commandNum],readbuffer,i);			
            i=i+1;			
            commandNum++;			
            strcpy(tmpBuffer,&readbuffer[i]);			
            strcpy(readbuffer,tmpBuffer);			
            i=0;		
        }
        else if('\0' == readbuffer[i])		
        {			
            strncpy(command[commandNum],readbuffer,i);			
            commandNum++;		
            break;		
        }
        else if('\r' == readbuffer[i])		
        {			
            strncpy(command[commandNum],readbuffer,i);			
            commandNum++;		 		
        }	
    }  
for(int j=0;j<commandNum;j++)
{
    STARTUPINFO si = {sizeof(si)};
    PROCESS_INFORMATION pi;
    si.dwFlags=STARTF_USESHOWWINDOW;
    si.wShowWindow=TRUE;
    
    BOOL bRet=CreateProcess(NULL,command[j],NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    if(bRet){
        CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
    }  
    Sleep(1000);
}
    

system("pause");
    return 0;
} 