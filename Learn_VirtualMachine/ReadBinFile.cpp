#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc,char* argv[]){
	FILE* BIN_FILE;
	cout<<"Enter the file path"<<endl;
	string BIN_FILE_PATH;
	cin>>BIN_FILE_PATH;
	char charData;
	
	BIN_FILE=fopen(BIN_FILE_PATH.c_str(),"rb+");
	
	for (int TestB=0;feof(BIN_FILE)==0;){
		charData=fgetc(BIN_FILE);
		if (TestB==8){
			cout<<" ";
		}else if (TestB==16){
			cout<<endl;
			TestB=0;
		}
		printf("%02X ",charData);
	/*	for (int Sleep=0;Sleep!=2000;){
			Sleep++;
		}*/
		
		TestB++;
	
	}
	return 0;
}