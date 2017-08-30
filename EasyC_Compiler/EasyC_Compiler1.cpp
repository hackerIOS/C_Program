//EasyC_Compiler

//by hackerIOS

//****Flow********

//LoadCode

//have a int *TYPE
//have a char**FUNCTION
//have a char**IDENTIFIER
//have a char**

//No support ASCII 128-255
//Compiler will auto ignore them


//MainLoop src

//interpunction analysis

//src---->analysis

//Generate Assembly Code

//export Code


//************Assembly*********

//.bss
//init no Num of string Value
//ValueName resq(64bit resd 32bit) how many (1 is 64bit) 
//and then will Create a NULL(no Data) space

//.data
//ValueName dd(dq,dw) Value
//int,char,float

//.text
//.global _start

//_start:
//code

//*******AssemblyCodeHelp******
//.text->.data->.bss->---------free memory----------<-----stack
//#define or include will get  into free memory

//**LEA********
//Intel
//lea rax,[foo]=mov rax,foo    
//at&t 
//lea $foo,%rax=movl foo,%rax
//lea:[foo]is a Value ,send the memory address to rax,lea can CC in Code
//lea rax,[foo+2]  The memory address will translate 2 address,and you can add a rax (lea rax,[foo+rax] The result is foo address x2
//Error:lea rax,[foo+foo]was wrong
//lea rax,[foo/2]was wrong

//****RIP
//RIP is application running current memory address

//****CALL
//call a function
//save RIP+1(8byte (8*8bits=64(system64))(The next command address)to RSP (stack point) (push RIP+8)
//and then jmp to The function

//****RET
//pop backup RIP (leave The stack)
//jmp to backup RIP

//*****FunctionDataProtect
//function:
//push rbp
//mov rbp,rsp
//Code
//mov rsp,rbp
//pop rbp
//RET

//******multiple File Compiler

//main Code call The library file 
//need call function
//and then
// .text
//     extern function
//warming:The library file need the .text segment
//and a public :global function

//******systemcall32(Linux)

//function(ebx,ecx,edx,esi,edi,ebp);eax
//EAX=4 Write(ebx=1=stdout,ecx=string,edx=Long)
//EAX=1 Exit(ebx=0)
//function END using INT 0x80; interrupt zd

//****systemcall 64(Linux)
//function(rdi,rsi,rdx,r10,r8,r9);rax
//rax=1 Write(same with 32);
//rax=60 Exit

//function END using "syscall"





//*****************MainCode*****

//*****Headler
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <iostream>
using namespace std;
//*******Global IDENTIFIER Area



char* src;//SourceCode
int FileLong;//File Long
int LineNum;//Line number
int token;//token ASCII word
int Line=0;//The Line Num

char TIDENTIFIER[10000][10000];//token IDENTIFIER
int TWNUM=0;//IDENTIFIER Num
//

int TTYPE[10000];//token TYPE
//TTYPE=0 is a function
//TTYPE=1 is a Value int

//TTYPE=2 is a ValueData
//TTYPE=3 is a interpunction
//TTYPE=4 is return
//TTYPE=5 is {
//TTYPE=6 is }
//TTYPE=7 is (
//TTYPE 8 )

//TTYPE 9 Temporarily unknown
//TTYPE 10 ;


//char** TVALUE;




//*****Function Area

//*****Assemblyfunction
void func(char* fun){
	printf (fun);
	printf (":\n");
	
	
	
	
	printf("RET\n");
}





//*****run function
void GenerateCode(){
	printf ("\nGenerate Code was starting...\n");
	printf("MainCode:\n");
	
	printf(".bss\n\n");//segment bss
	//if have bss data
	printf(".data\n\n");
	//if have Data
	printf (".text\n");
	printf("global _start\n");
	printf("_start:\n");
	//JMP
	printf("_exit:\n");
	printf("mov eax,1\n");
	printf("mov ebx,0\n");
	printf("int 0x80\n");
	printf("Generate success!\n");
	for (;;){
		//
	}
}



void AnalyseCode(){
	//Analyse Source Code
	for (int LoopAnalyse=0;LoopAnalyse!=Line;){
		if (TIDENTIFIER[LoopAnalyse]=="int")
		{
			TTYPE[LoopAnalyse]=1;
		}else if (TIDENTIFIER[LoopAnalyse]=="return"){
			TTYPE[LoopAnalyse]=4;
		}else if (TIDENTIFIER[LoopAnalyse]=="{"){
			TTYPE[LoopAnalyse]=5;
		}else if (TIDENTIFIER[LoopAnalyse]=="}"){
			TTYPE[LoopAnalyse]=6;
		}else if (TIDENTIFIER[LoopAnalyse]=="("){
			if (TTYPE[LoopAnalyse-1]==9){
				TTYPE[LoopAnalyse-1]=0;
			}
			TTYPE[LoopAnalyse]=7;
		}else if (TIDENTIFIER[LoopAnalyse]==")"){
			TTYPE[LoopAnalyse]=8;
		}else if (TIDENTIFIER[LoopAnalyse]==";"){
			TTYPE[LoopAnalyse]=10;
		}else{
			TTYPE[LoopAnalyse]=9;
		}
		
		LoopAnalyse++;
	}
	GenerateCode();
}


void next(){
	//Get Main Code
	nextback:;//GoBack
	token=*src++;
	if (token==' '){
		if (TWNUM!=0){
			printf("token is:");
			printf (TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		goto nextback;
		
	}else if (token=='\n'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		goto nextback;
	}else if (token>=0x80 && token<=0xff){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		goto nextback;
	}else if (token>='a' && token<='z'){
		TIDENTIFIER[Line][TWNUM]=token;
		TWNUM++;
		goto nextback;
	}else if (token>='A' && token<='Z'){
		TIDENTIFIER[Line][TWNUM]=token;
		TWNUM++;
		goto nextback;
	}else if (token=='('){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
			
	}else if (token==')'){
		TWNUM=0;
		Line++;
	}else if (token=='{'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='}'){
		TWNUM=0;
		Line++;
	}else if (token=='.'){
	    if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token==';'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
			
	}else if (token=='*'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='+'){
	    if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='-'){
	    if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='!'){
	    	if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='='){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='>'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='<'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token==','){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token=='/'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token==':'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		
		TWNUM=0;
		Line++;
	}else if (token==0x09){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		goto nextback;
	}else if (token=='"'){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		TWNUM=0;
		Line++;
	}else if (token==0x02){
		if (TWNUM!=0){
			printf("token is:");
			printf(TIDENTIFIER[Line]);
			printf("\n");
			TWNUM=0;
			Line++;
		}
		goto nextback;
	}
	
	return;
}




void program(){
	next();
	while (token!=0){
		
		printf ("token is: %c\n", token);
	    TIDENTIFIER[Line][0]=(char)token;
	    Line++;
		next();
	}
	//printf (TIDENTIFIER[0]);
	
	printf("input to token success\n");
	printf("MainCode:");
	for (int Loop=0;Loop!=Line;){
		printf (TIDENTIFIER[Loop]);
		
		Loop++;
	}
	printf("\n1.Linux\n2.Windows\n");
	printf("Which system do you want to generate\n");
	/*
	char selectsystem;
	
	scanf("%c",selectsystem);
	if (selectsystem=='1'){
		//Linux
		AnalyseCode();
	}else if (selectsystem=='2'){
		//Windows
		printf("No support Windows");
	}else{
		printf("Wrong input\n");
	}
	*/
	int selectsystem=0;
	cin>>selectsystem;
	if (selectsystem==1){
		//Linux
		AnalyseCode();
	}else if (selectsystem==2){
		//Windows
		printf("No support Windows");
	}else{
		printf("Wrong input\n");
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
	
	char FileData[FileLong];
	
	FileData[FileLong]=0;
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
	printf ("\n");
	
	//***
	//TIDENTIFIER[10000][10000];
	//
}



int main(int argc,char* argv[]){
	LoadCode();
	program();
	while (1){
		//
	}
	return 0;
}