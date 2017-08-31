int main(){  
  
    //获取系统时间  
    char buffer[128];  
    getSystemTime(buffer);  
    puts(buffer);  
  
    //系统运行时间  
    clock_t start, finish;  
    double duration;  
  
    start = clock();  
    while (true)  
    {  
        finish = clock();  
        duration = (double)(finish - start) / CLOCKS_PER_SEC;  
        Sleep(1000);  
        printf("%.0f 秒\n", duration);  
  
    }  
  
    //系统版本名称  
    char osname[20];  
    GetSystemName(osname);  
    printf("%s\n", osname);  
  
    //CPU利用率  
    while (true)  
    {  
        U_CHAR  sysStateCpu[5];  
        double cpu = CpuUseage();  
        sprintf((char*)sysStateCpu, "%.2lf", cpu);  
        printf("CPU使用率：%s%%\n", sysStateCpu);  
        Sleep(1000);  
    }  
  
    //内存使用率  
    char bufPreCPU[5];  
    MEMORYSTATUSEX statex;  
    statex.dwLength = sizeof(statex);  
    GlobalMemoryStatusEx(&statex);  
    sprintf(bufPreCPU, "%ld%%\n", statex.dwMemoryLoad);  
    puts(bufPreCPU);  
  
    //硬盘使用率 调用windows API  
    ULARGE_INTEGER FreeBytesAvailableC, TotalNumberOfBytesC, TotalNumberOfFreeBytesC;  
    ULARGE_INTEGER FreeBytesAvailableD, TotalNumberOfBytesD, TotalNumberOfFreeBytesD;  
    ULARGE_INTEGER FreeBytesAvailableE, TotalNumberOfBytesE, TotalNumberOfFreeBytesE;  
    ULARGE_INTEGER FreeBytesAvailableF, TotalNumberOfBytesF, TotalNumberOfFreeBytesF;  
           
    GetDiskFreeSpaceEx(_T("C:"), &FreeBytesAvailableC, &TotalNumberOfBytesC, &TotalNumberOfFreeBytesC);  
    GetDiskFreeSpaceEx(_T("D:"), &FreeBytesAvailableD, &TotalNumberOfBytesD, &TotalNumberOfFreeBytesD);  
    GetDiskFreeSpaceEx(_T("E:"), &FreeBytesAvailableE, &TotalNumberOfBytesE, &TotalNumberOfFreeBytesE);  
    GetDiskFreeSpaceEx(_T("F:"), &FreeBytesAvailableF, &TotalNumberOfBytesF, &TotalNumberOfFreeBytesF);  
    /*参数 类型及说明 
    lpRootPathName String，不包括卷名的磁盘根路径名 
    lpFreeBytesAvailableToCaller LARGE_INTEGER，指定一个变量，用于容纳调用者可用的字节数量 
    lpTotalNumberOfBytes LARGE_INTEGER，指定一个变量，用于容纳磁盘上的总字节数 
    lpTotalNumberOfFreeBytes LARGE_INTEGER，指定一个变量，用于容纳磁盘上可用的字节数 
    适用平台 
    Windows 95 OSR2，Windows NT 4.0*/  
    float totalHardDisk = GB(TotalNumberOfBytesC) + GB(TotalNumberOfBytesD) + GB(TotalNumberOfBytesE) + GB(TotalNumberOfBytesF);  
    float freeHardDisk = GB(TotalNumberOfFreeBytesC) + GB(TotalNumberOfFreeBytesD) + GB(TotalNumberOfFreeBytesE) + GB(TotalNumberOfFreeBytesF);  
      
    float hardDiskUsage = 1- freeHardDisk / totalHardDisk;  
  
    //CPU风扇转速  
  
    printf("hello world!\n");  
    system("pause");  
  
}  