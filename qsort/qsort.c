#include <stdlib.h>
#include <stdio.h>

int DS(const void *a,const void *b){
	return *(char*)b-*(char*)a;
}

int main(){
	char array[10]="12345";
	qsort(array,5,sizeof (char),DS);
	printf(array);
	return 0;
}