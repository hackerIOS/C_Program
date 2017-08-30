#include <stdio.h>
#include <stdlib.h>


int main(){
	int i=0;
	char **a;
	a=(char**)malloc(sizeof(char*)*1000);
	for (;i<2;i++){
		a[i]=(char*)malloc(sizeof(*a));
	}
	a[0]="123";
	a[1]="234";
	printf(a);
	free (a);
/*	char *p;
	
	
	p=(char*)malloc(1);
	p[0]='a';
	p=(char*)realloc(p,2);
	//p[1]='1';
	p[1]='b';
	printf(p);
	free(p);*/
	return 0;
}