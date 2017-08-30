//Auto shutdown

#include<stdlib.h>
#include<stdio.h>
int main()
{
	printf("shutdown now...：\n");
	system("su -c 'reboot -p'");
	return 0;
}
