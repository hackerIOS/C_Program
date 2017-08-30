//droidfallback ttf check
//   /system/fonts/DroidSansFallback.ttf
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc,char*argv[]){
	char *pathdata="/system/fonts/";
	//char outputText;
	DIR *dir;
	struct dirent *ptr;
	dir=opendir(pathdata);
	int filenum=0;
	while ((ptr=readdir(dir))!=NULL){
		filenum++;
	}
	printf ("%i\n",filenum);
	char* data[filenum];
	int CC=0;
	dir=opendir(pathdata);
	while (CC<filenum && (ptr=readdir(dir))!=NULL){
		data[CC]=ptr->d_name;
		printf("%d",CC);
				if (strstr(data[CC],"DroidSansFallback")){
			printf("success");
		}
		printf(data[CC]);
		printf("\n");
		CC++;
	}
	
}