//Base64.h 自行改编为
//Base64Plus.h
//感谢老A给予的技术支持
//感谢Base64算法原作者
#ifndef _BASE64PLUS_H
#define _BASE64PLUS_H

#include <stdlib.h>
#include <string.h>

char* B64Pencode(char* str){
	//加密
	
	char* B64P_Table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int len;
	int str_len=strlen(str);
	
	if (str_len % 3==0){
		len=str_len/3*4;
		}else{
			len=(str_len/3+1)*4;
	}
	int i=0,j=0;
	char backdata[len];
	for (;i<len-2;){
			backdata[i]=B64P_Table[str[j]>>2];
		backdata[i+1]=B64P_Table[(str[j+1])&0x03<<4 | (str[j+1]>>4)];
		
		backdata[i+2]=B64P_Table[(str[j+1]&0x0f)<<2 | (str[j+2]>>6)];
		
		backdata[i+3]=B64P_Table[str[j+2]&0x3f];
		i=i+4;
		j=j+3;
	}
	if (str_len % 3==1){
		backdata[i-2]='=';
	    backdata[i-1]='=';
	    }else if (str_len % 3==2){
	    	backdata[i-1]='=';
	    }
	    
	    
	    
	    return backdata;
}

char* B64Pdecode(char* str){
	//解密还没写
	
}

#endif