#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


int token;//ASCII Code
int defaultsize;//default size
char* src;//Source Code

int *text,*old_text,*stack;//stack ,Data,Code(Text)

int *pc,*bp,*sp
,ax=0
,cycle;

// instructions
enum { LEA ,IMM ,JMP ,CALL,JZ  ,JNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PUSH,OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,OPEN,READ,CLOS,PRTF,MALC,MSET,MCMP,EXIT };


char* data;

void next(){
	token=*src++;
	return;
}

void expression(int level){
	
}

void program(){
	next();
	while (token!=0){
		printf ("token is: %c\n", token);
		next();
	}
}

int eval(){
	int op, *tmp;
    while (1) {
        if (op == IMM)       {ax = *pc++;}                                     // load immediate value to ax
        else if (op == LC)   {ax = *(char *)ax;}                               // load character to ax, address in ax
        else if (op == LI)   {ax = *(int *)ax;}                                // load integer to ax, address in ax
        else if (op == SC)   {ax = *(char *)*sp++ = ax;}                       // save character to address, value in ax, address on stack
        else if (op == SI)   {*(int *)*sp++ = ax;}                             // save integer to address, value in ax, address on stack
    }
    
    
}


int main(int argc,char* argv[])
{
	
	FILE *fp,*fp1;
	
	char ch,wjm[1000];
	defaultsize=256*1024;
	
	int FileLong=0;
	printf("Please enter a file path to be compiled (file name cannot contain spaces):\n");
	scanf("%s",wjm);
	if (!(fp=fopen(wjm,"r")))
	{
		printf("%sError!",wjm);
		exit(1);
	}
	while (feof(fp)==0)
	{
		ch=fgetc(fp);
		
		FileLong++;
	}
	fclose(fp);
	fp1=fopen(wjm,"r");
	
	char FileData[FileLong+1];
	FileData[FileLong+1]=0;
	int ReWriteNum=0;
	while (feof(fp1)==0){
		ch=fgetc(fp1);
		FileData[ReWriteNum]=ch;
		ReWriteNum++;
	}
	
	printf ("%s",FileData);
	
	fclose(fp1);
	src=FileData;
	printf("\nsuccess");
	
	//assb
	
	if (!(text = old_text = (int*)malloc(defaultsize))) {
        printf("could not malloc(%d) for text area\n", defaultsize);
        return -1;
    }
    if (!(data = (char*)malloc(defaultsize))) {
        printf("could not malloc(%d) for data area\n", defaultsize);
        return -1;
    }
    if (!(stack = (int*)malloc(defaultsize))) {
        printf("could not malloc(%d) for stack area\n", defaultsize);
        return -1;
    }
	
	memset(text, 0, defaultsize);
    memset(data, 0, defaultsize);
    memset(stack, 0, defaultsize);
    
    bp=sp=(int*)((int)stack+defaultsize);
    
    
    
	program();
	
	return 0;
}