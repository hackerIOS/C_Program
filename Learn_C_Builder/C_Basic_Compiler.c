//New C_Compiler

//by hackerIOS

//****Flow********

//LoadCode

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



#include <stdio.h>
#include <stdlib.h>

char** TYPE;//0 int  1 char  2 void  3 no

char**AllSaveStr;

int AllSaveStrL=0,AllSaveStrR=0;

int FileLong=0;//SourceCodeSize

char* src;//SourceCode

char* saveword;//saveword
int savewordnum=0;
int getword=0;

int LastToken;//Lasttokenword
//0-NULL,1-word,2-Num,3-interpunction

char Token;//Tokenword

int detected=0;//was check success

int initnum=0;//StartLoopNum

char*  AllWord="abcdefghijklmnopqrstuvwxyz";


int word(){
	
		for (int LoopNum=0;LoopNum!=sizeof (AllWord)+1;){
			if (AllWord[LoopNum]==src[initnum]){
				LastToken=1;
				detected=1;
				printf(&src[initnum]);
				saveword[savewordnum]=AllWord[LoopNum];
				savewordnum++;
				return 0;
			}
			LoopNum++;
		}
	
	if (LastToken==1){
		AllSaveStr[AllSaveStrL]=saveword;
		saveword="";
		AllSaveStrL++;
		savewordnum=0;
	}
	
}

int interpunction(){
	if (src[initnum]==' '){
		detected=1;
		LastToken=3;
		//printf(" ");
	}else if (src[initnum]=='\n'){
		detected=1;
		LastToken=3;
		printf ("\n");
		
	}else if (src[initnum]=='('){
		detected=1;
		LastToken=3;
		printf ("(");
		if (AllSaveStr[AllSaveStrL-1]=="main"){
		//	if (AllSaveStr[
		printf("main");
		}else if (AllSaveStr[AllSaveStrL-2]=="int"){
			printf("int");
		}else if (AllSaveStr[AllSaveStrL-2]=="char"){
			printf("char");
		}else if (AllSaveStr[AllSaveStrL-2]=="void"){
			printf("void");
		}else if (AllSaveStr[AllSaveStrL-1]=="if"){
			printf("if");
		}else if (AllSaveStr[AllSaveStrL-1]=="while"){
			printf("while");
		}else if (AllSaveStr[AllSaveStrL-1]=="for"){
			printf ("for");
		}else if (AllSaveStr[AllSaveStrL-1]!="main"){
			printf ("Error");
		}
		
		
	}else if (src[initnum]==')'){
		detected=1;
		LastToken=3;
		printf(")");
	}else if (src[initnum]=='{'){
		detected=1;
		LastToken=3;
		printf ("{");
	}else if (src[initnum]=='}'){
		detected=1;
		LastToken=3;
		printf("}");
	}
}


int MainLoop(){
	for (initnum=0;initnum!=FileLong+1;){
		detected=0;
		word();
		interpunction();
		
		initnum++;
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
	AllSaveStr[FileLong][FileLong];
	TYPE[FileLong][FileLong];
	printf ("\n");
}


int main(int argc,char* argv[]){
	LoadCode();
	MainLoop();
}