//加密文件2
//暂不支持windows system
#include <stdio.h>
#include "Base64Plus.h"
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <string.h>
using namespace std;
char pddata[10]=".txt";
int main(){
	printf("你的文件夹路径:");
	char path1[200];
	cin>>path1;
	char *pathdata=path1;
	//char *path2=path1;
	char outputText;
	DIR *dir;
	string filedata;
	struct dirent *ptr;
	dir=opendir(pathdata);
	int filenum=0;
	while ((ptr=readdir(dir))!=NULL){
		filenum++;
	}
	printf ("目录文件及文件夹数目:");
	printf ("%i\n",filenum);
	char* data[filenum];
	char *copydata[filenum];
	int CC=0;
	dir=opendir(pathdata);
	while (CC<filenum && (ptr=readdir(dir))!=NULL){
		data[CC]=ptr->d_name;
		CC++;
	}
	CC=0;
	int copysz=0;
	printf("待加密文件:\n");
	while (CC<filenum){
		if (strstr(data[CC],pddata)){
			copydata[copysz]=data[CC];
			printf("%s\n",data[CC]);
			copysz++;
		}
		//printf("%s",data[CC]);
		CC++;
	}
	closedir(dir);
	FILE *fileput;
	FILE *fp;
	for (int i=0;i!=copysz;){
		int datalen=0;
		char pathdata2[100]="";
		strcat(pathdata2,path1);
		strcat(pathdata2,"/");
		strcat(pathdata2,copydata[i]);
	printf("文件路径:");
	printf("%s\n",pathdata2);
	
	fileput=fopen(pathdata2,"rb+");
	while (feof(fileput)==0){
		outputText=fgetc(fileput);
		printf("%c",outputText);
		datalen++;
		}
		fclose(fileput);
		char outputdata[datalen];
		int addcc=0;
fileput=fopen(pathdata2,"rb+");
	while (feof(fileput)==0){
		outputText=fgetc(fileput);
		outputdata[addcc]=outputText;
		addcc++;
		
		}
		//printf("\n%s",outputdata);
		//加密
		//写出
		//上密码
		//char* OT=outputdata;
		//char* OTcopy;
		char* OTcopy=B64Pencode(outputdata);
    	printf("\n%s",OTcopy);
    	
		i++;
		printf("\n");
		
fp=fopen("/sdcard/EnCode/EnCode.txt","w+");
	fputs(OTcopy,fp);
	}
	return 0;
}