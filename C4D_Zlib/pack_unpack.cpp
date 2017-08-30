#include <iostream>
using namespace std;
#include <zlib.h>
#include <stdio.h>
int main(){
	char Text[]="123qwe";
	unsigned long tlen=sizeof (Text);
	//Add \0
	unsigned char buf[1024]={0};
	unsigned long blen;
	
	unsigned char uncp[1024];
	unsigned long ulen=sizeof (uncp);
	blen=compressBound(tlen);
	// 缓冲区大小,压缩后长度不会超过blen
	//buf=new char[blen];
	//buf=(char*)malloc(sizeof (char )*blen);
	
	compress(buf,&blen,(unsigned char* )Text,tlen);
	cout<<buf;
	uncompress(uncp,&ulen,buf,blen);
	cout<<uncp;
	
	return 0;
}