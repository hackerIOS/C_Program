#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
	printf("Current process PIN:");
	printf("%d",getppid());
	char APID[20];
	sprintf(APID,"%d",getppid());
//	itoa(getppid(),APID,10);
	for (int a=0;a!=10000;){
		a++;
	}
	printf("End");
	char su[30]="su -c 'kill -";
	strcat(APID,"'");
	strcat(su,APID);
	printf(su);
	system(su);
	return 0;
}