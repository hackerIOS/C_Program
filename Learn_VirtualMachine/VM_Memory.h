//Memory

#include <iostream>
#include <cstdio>
using namespace std;

char* VM_MEMORY=NULL;


int CreateMemorySpace(int CreateMemorySize){//MB
	if ((VM_MEMORY=new char (sizeof (char)*1024*1024*CreateMemorySize))==NULL){
		return 1;
	}
	return 0;
}


int main(){
	CreateMemorySpace(1);
	
	printf("success");
	
	delete VM_MEMORY;
	return 0;
}