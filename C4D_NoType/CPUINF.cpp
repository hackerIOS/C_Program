#include <stdio.h>  
#include <Windows.h>  
#include<time.h>  
#include <tchar.h>  
  
#define DIV 1024  
#define WIDTH 7  
#define GB(x) (((x).HighPart << 2) + ((DWORD)(x).LowPart) / 1024.0 / 1024.0 / 1024.0)  
  
#pragma warning(disable: 4996)     
  
#define true 1  
typedef unsigned char U_CHAR;  
  
//获取系统时间  
int getSystemTime(char* buffer){  
  
    char buf[128];  
    time_t rawtime;  
    struct tm * timeinfo;  
    time(&rawtime);  
    timeinfo = localtime(&rawtime);  
    strftime(buf, sizeof(buf), "Now is %Y-%m-%d %H:%M:%S", timeinfo);  
    strcpy(buffer,buf);  
}  
  
//CPU利用率  
FILETIME m_preidleTime;  
FILETIME m_prekernelTime;  
FILETIME m_preuserTime;  
  
__int64 CompareFileTime2(FILETIME time1, FILETIME time2)  
{  
    __int64 a = time1.dwHighDateTime << 32 | time1.dwLowDateTime;  
    __int64 b = time2.dwHighDateTime << 32 | time2.dwLowDateTime;  
  
  
    return   b - a;  
}  
  
void GetCpuUseage()  
{  
    GetSystemTimes(&m_preidleTime, &m_prekernelTime, &m_preuserTime);  
    Sleep(1000);  
}  
  
double CpuUseage()  
{  
    FILETIME idleTime;  
    FILETIME kernelTime;  
    FILETIME userTime;  
    GetSystemTimes(&idleTime, &kernelTime, &userTime);  
  
  
    int idle = CompareFileTime2(m_preidleTime, idleTime);  
    int kernel = CompareFileTime2(m_prekernelTime, kernelTime);  
    int user = CompareFileTime2(m_preuserTime, userTime);  
  
  
    if (kernel + user == 0)  
        return 0.0;  
    //（总的时间-空闲时间）/总的时间=占用cpu的时间就是使用率  
    double cpu = abs((kernel + user - idle) * 100 / (kernel + user));  
  
    m_preidleTime = idleTime;  
    m_prekernelTime = kernelTime;  
    m_preuserTime = userTime;  
    return cpu;  
}  