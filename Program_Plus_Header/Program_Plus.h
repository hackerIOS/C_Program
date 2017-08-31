//Program Plus
//hackerIOS
#ifndef PROGRAM_PLUS_
#define PROGRAM_PLUS_

#include <iostream>
#include <fstream>
//#include <streambuf>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zlib.h>
using namespace std;

void PP_RandomSeed(){
	srand(time(NULL));
	return;
}

int PP_RandomRange(int firstnum,int endnum){//3-5
	int RandomData;
	endnum=endnum-firstnum+1;
	
	RandomData=rand()%endnum+firstnum;
	
	return RandomData;
}




char* PP_ReadFileC(char* ReadPathC){
	FILE*fp,*fp1;
	int Filelong=0;
	char* FileData;
	FileData=(char*)malloc(sizeof (char)*(Filelong+1));
	if (fp=fopen(ReadPathC,"r")){
		cout<<"success"<<endl;
	}else{
		cout<<"failure"<<endl;
	}
	while (feof(fp)==0){
		
		FileData[Filelong]=fgetc(fp);
		
		Filelong++;
		char* CopyData=FileData;
		FileData=(char*)malloc(sizeof (char)*(Filelong+1));
		FileData=CopyData;
		
		
	}
	char ReturnData[Filelong+1];
	fclose(fp);
	fp1=fopen(ReadPathC,"r");
	int NewLoop=0;
	while (feof(fp1)==0){
		ReturnData[NewLoop]=fgetc(fp1);
		NewLoop++;
	}
	fclose(fp1);
	cout<<FileData;
	return FileData;
}




string PP_ReadFile(string ReadPath){
	ifstream ReadTarget;
	ReadTarget.open(ReadPath);
	//string ReturnData((std::istreambuf_iterator<char>(ReadTarget),std::istreambuf_iterator<char>()));
	string ReturnData;
	ReadTarget.seekg(0,std::ios::end);
	int FileLong=ReadTarget.tellg();
	ReadTarget.seekg(0,std::ios::beg);
	char TempRD[FileLong];
	ReadTarget.read(TempRD,FileLong);
	ReturnData=TempRD;
	/*while (ReadTarget!=NULL){
		string TempRD;
		ReadTarget>>TempRD;
		ReturnData=ReturnData+TempRD;
	}*/
	//ReadTarget>>ReturnData;
	ReadTarget.close();
	char*RecData=(char*)ReturnData.c_str();
	ReturnData=RecData;
	return ReturnData;
}


int PP_OutputFile(string OutputFileOrFilePath,string OutputData){
	ofstream OutputTarget;
	OutputTarget.open(OutputFileOrFilePath);
	OutputTarget<<OutputData;
	OutputTarget.close();
	return 0;
}


char *PP_ReturnPathData(int BackType,char*PathData){
	return PathData;
}


/*
char*PP_Pack(char *PackData){
	unsigned long PackDatalen=sizeof (PackData);
	unsigned long Packlen;
	unsigned char *PackEnd=NULL;
	Packlen=compressBound(PackDatalen);
	
	PackEnd=(unsigned char*)malloc(sizeof(unsigned char )*PackDatalen);
	
	//unsigned char* UnpackEnd=new 
	
	
	compress(PackEnd,&Packlen,(unsigned char*)PackData,Packlen);
	//cout<<UnpackEnd<<endl;
	unsigned char*FreeSpace=PackEnd;
	free(PackEnd);
	return (char*)FreeSpace;
	
}



char*PP_Unpack(char *UnpackData){
	unsigned char *CopyUnpackData=(unsigned char*)UnpackData;
	
	unsigned long UnpackDatalen=sizeof (CopyUnpackData);
	
	
	
	unsigned char*UnpackEnd=(unsigned char*)malloc(sizeof (unsigned char)*UnpackDatalen*20);
	
	unsigned long Unpacklen=sizeof (UnpackEnd)*20;
	uncompress(UnpackEnd,&Unpacklen,CopyUnpackData,UnpackDatalen);
	
	cout<<UnpackEnd<<endl;
	return (char*)UnpackEnd;
}


int main(int argc,char*argv[]){
	PP_RandomSeed();
	int a=PP_RandomRange(10,20);
	cout<<a<<endl;
	char *b=PP_Pack("12356");
	cout<<b<<endl;
	cout<<PP_Unpack(b)<<endl;
	return 0;
}
*/

/*

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
}*/

#endif