#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int fx=0;//Direction
int wzx=1;
int wzy=3;

void sleepfc(){
	int cc=0;
	for(;cc!=10000;){
		cc++;
	}
}


int main(){
	for (;;){
		if (wzx==1 && wzy==3){
			cout<<endl;
			cout<<endl;
			cout<<".";
			wzx++;
			wzy=0;
		}
		sleepfc();
		//clrscr();
		system("cls");
	}
	return 0;
}

