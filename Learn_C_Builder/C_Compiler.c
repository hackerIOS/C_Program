//The Easy basic C Compiler

//by hackerIOS
#include <stdio.h>
#include <stdlib.h>

char* src,*ew,*itpts;
char* asbc=(char*)malloc(strlen(".text\n    "));
int token;
int FileLong=0;

int funcstart=0;//1Start

int *tokenascii;

char* saveword;

struct ews1{
	int ewn=0;
}ews;

int LastCode=0;//0=no,1=word,2=Num,3=interpunction,4=\n

int analysisword(){
	if (saveword=="main"){
		asbc=(char*)malloc(strlen(".text\n    .global _start\n"+1));
		asbc=".text\n    .global _start\n";
		printf(asbc);
		
	}else{
		printf("Error!The compiler does not know the identity of the ");
		printf(saveword);
	}
}
void itpt(){
	itpts="{}";
	for (int itptp=0;itptp!=3;){
		if (token==(int)itpts[itptp]){
			if (itpts[itptp]=='{'){
				
			}else if (itpts[itptp]=='}'){
				
			}
		}
	}
}


void eword(){
	ew="abcdefghijklmnopqrstuvwxyz";//26word
	
	for (int ewp=0;ewp!=26;){
	    	if (token==(int)ew[ewp]){
	    		
	    		if (LastCode!=1){
	    			ews.ewn=0;
	    		}
	    		ews.ewn++;
	    		saveword[ews.ewn-1]=(char)token;
	    		
	    		
	    		
	    		
	    		LastCode=1;
	    		return;
	    	}
	    	ewp++;
	    }
	    if (LastCode==1){
	    	analysisword();
	    }
	    
	    itpt();
	    
	    
}

void next(){
	token=*src++;
	
	return;
}

void program(){
	next();
	while (token!=0){
		
		printf ("token is: %c\n", token);
	    eword();
		next();
	}
}

int LoadCode(){
	FILE *FilePath0,*FilePath1;
	char ch,wjm[1000];
	
	
	printf("Please enter a file path to be compiled (file name cannot contain spaces):\n");
	
	scanf("%s",wjm);
	if (!(FilePath0=fopen(wjm,"r")))
	{
		printf("%sError!",wjm);
		exit(0);
	}
	while (feof(FilePath0)==0)
	{
		ch=fgetc(FilePath0);
		
		FileLong++;
	}
	fclose(FilePath0);
	FilePath1=fopen(wjm,"r");
	
	char FileData[FileLong+1];
	
	saveword[FileLong];
	
	FileData[FileLong+1]=0;
	int ReWriteNum=0;
	while (feof(FilePath1)==0){
		ch=fgetc(FilePath1);
		FileData[ReWriteNum]=ch;
		ReWriteNum++;
	}
	
	printf ("%s",FileData);
	
	fclose(FilePath1);
	src=FileData;
	printf("\nsuccess\n");
	
}


int generate(){
	printf ("\n****************\n");
	printf (".text\n");
	
}

int main(int argc,char*argv[]){
	LoadCode();
	eword();
	
	program();
}