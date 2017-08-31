//读取操作系统的名称  
void GetSystemName(char* osname)  
{  
    char buf[128];  
    SYSTEM_INFO info;        //用SYSTEM_INFO结构判断64位AMD处理器   
    GetSystemInfo(&info);    //调用GetSystemInfo函数填充结构   
    OSVERSIONINFOEX os;  
    os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);  
  
    strcpy(buf, "unknown OperatingSystem.");  
  
    if (GetVersionEx((OSVERSIONINFO *)&os))  
    {  
        //下面根据版本信息判断操作系统名称   
        switch (os.dwMajorVersion)//判断主版本号  
        {  
        case 4:  
            switch (os.dwMinorVersion)//判断次版本号   
            {  
            case 0:  
                if (os.dwPlatformId == VER_PLATFORM_WIN32_NT)  
                    strcpy(buf, "Microsoft Windows NT 4.0"); //1996年7月发布   
                else if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)  
                    strcpy(buf, "Microsoft Windows 95");  
                break;  
            case 10:  
                strcpy(buf, "Microsoft Windows 98");   
                break;  
            case 90:  
                strcpy(buf, "Microsoft Windows Me");   
                break;  
            }  
            break;  
  
        case 5:  
            switch (os.dwMinorVersion)  //再比较dwMinorVersion的值  
            {  
            case 0:  
                strcpy(buf, "Microsoft Windows 2000"); //1999年12月发布  
                break;  
  
            case 1:  
                strcpy(buf, "Microsoft Windows XP"); //2001年8月发布  
                break;  
  
            case 2:  
                if (os.wProductType == VER_NT_WORKSTATION  
                    && info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)  
                {  
                    strcpy(buf, "Microsoft Windows XP Professional x64 Edition");   
                }  
                else if (GetSystemMetrics(SM_SERVERR2) == 0)  
                    strcpy(buf, "Microsoft Windows Server 2003"); //2003年3月发布   
                else if (GetSystemMetrics(SM_SERVERR2) != 0)  
                    strcpy(buf, "Microsoft Windows Server 2003 R2");   
                break;  
            }  
            break;  
  
        case 6:  
            switch (os.dwMinorVersion)  
            {  
            case 0:  
                if (os.wProductType == VER_NT_WORKSTATION)  
                    strcpy(buf, "Microsoft Windows Vista");   
                else  
                    strcpy(buf, "Microsoft Windows Server 2008"); //服务器版本   
                break;  
            case 1:  
                if (os.wProductType == VER_NT_WORKSTATION)  
                    strcpy(buf, "Microsoft Windows 7");   
                else  
                    strcpy(buf, "Microsoft Windows Server 2008 R2");   
                break;  
            }  
            break;  
        }  
    }//if(GetVersionEx((OSVERSIONINFO *)&os))  
  
    strcpy(osname, buf);  
}  