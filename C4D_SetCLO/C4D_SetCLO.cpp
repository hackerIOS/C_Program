//cc a
#include <iostream>
//#include <conio.h>
#include <stdio.h>
using namespace std;
int t=0;
int jump=0;
int at=0;
int i=0;
int sl=0;
void sleep(){
	for (;sl!=100000000;){
		sl++;
	}
	sl=0;
	return ;
}
void CC(){
	printf("\x1B[2J\x1B[0;0f");
//	while (kbhit()){
//		jump=1;
//	}
	if (jump==0){
		t++;
		at=t*t/2;
		for (;i!=at;){
			i++;
			cout<<endl;
		}
		i=0;
		cout<<"                 _(:3JZ)_"<<endl;
	//	usleep(1000);
		sleep();
		CC();
	}
}
void Start(){
	CC();
}
int main(){
	Start();
	return 0;
}