//控制台控制旋转

//假定100*100
#include <iostream>
using namespace std;
#include <conio.h>
#include <math.h>

#include <stdio.h>
#define PI 3.14

int map[100][100];

double spos1_x;
double spos1_y;
double spos2_x;
double spos2_y;
double spos3_x;
double spos3_y;
double spos4_x;
double spos4_y;



int pd=0;//0正1反

int dp_w=100;
int dp_h=100;

int initx=50;
int inity=50;
double initrot=1;

//int L=10;

struct{
	double Rot=1;
	
}pos;

//int Cpos;
struct{
	int x=50-20;
	int y=50-20;
}pos1;

struct{
	int x=50+20;
	int y=50-20;
}pos2;

struct{
	int x=50-20;
	int y=50+20;
}pos3;

struct{
	int x=50+20;
	int y=50+20;
}pos4;

int Sleep(){
	int slt=0;
	for (;slt!=10000000;){
		slt++;
	}
}

	



int RotAdd(){
	//pos1.x=pos1.x*cos(1)-pos1.y*sin(1);
    int npos1_x=pos1.x-50;
	int npos1_y=pos1.y-50;
	
	int npos2_x=pos2.x-50;
	int npos2_y=pos2.y-50;

	int npos3_x=pos3.x-50;
	int npos3_y=pos3.y-50;
	
	int npos4_x=pos4.x-50;
	int npos4_y=pos4.y-50;
	
	if (pos1.x==50){
		pd++;
		if (pd==2){
			pd==0;
		}
	}
		
	if (pd==0){
				npos1_x=npos1_x*cos(1*PI/180)-npos1_y*sin(1*PI/180);
	npos1_y=npos1_x*sin(1*PI/180)+npos1_y*cos(1*PI/180);
	
	
	npos2_x=npos2_x*cos(1*PI/180)-npos2_y*sin(1*PI/180);
	npos2_y=npos2_x*sin(1*PI/180)+npos2_y*cos(1*PI/180);
	
	npos3_x=npos3_x*cos(1*PI/180)-npos3_y*sin(1*PI/180);
	npos3_y=npos3_x*sin(1*PI/180)+npos3_y*cos(1*PI/180);
	
	
	npos4_x=npos4_x*cos(1*PI/180)-npos4_y*sin(1*PI/180);
	npos4_y=npos4_x*sin(1*PI/180)+npos4_y*cos(1*PI/180);
	
	
	}else if (pd==1){
		npos1_x=npos1_x*sin(1*PI/180)+npos1_y*cos(1*PI/180);
	npos1_y=npos1_x*cos(1*PI/180)-npos1_y*sin(1*PI/180);
	
	
	npos2_x=npos2_x*sin(1*PI/180)+npos2_y*cos(1*PI/180);
	npos2_y=npos2_x*cos(1*PI/180)-npos2_y*sin(1*PI/180);
	
	npos3_x=npos3_x*sin(1*PI/180)+npos3_y*cos(1*PI/180);
	npos3_y=npos3_x*cos(1*PI/180)-npos3_y*sin(1*PI/180);
	
	
	npos4_x=npos4_x*sin(1*PI/180)+npos4_y*cos(1*PI/180);
	npos4_y=npos4_x*cos(1*PI/180)-npos4_y*sin(1*PI/180);
	
	}
	//cout<<npos1_x+50<<endl;
	//cout<<npos1_y+50<<endl;
	pos1.x=npos1_x+50;
	pos1.y=npos1_y+50;
	pos2.x=npos2_x+50;
	pos2.y=npos2_y+50;
	pos3.x=npos3_x+50;
	pos3.y=npos3_y+50;
	pos4.x=npos4_x+50;
	pos4.y=npos4_y+50;
}


int CCCube(){
	int i,j;
	for (i=0;i!=100;){
		for (j=0;j!=100;){
			
			if (map[j][i]==1){
				cout<<"\033[41;1m  ";
			}else if(map[j][i]==0){
				printf("\033[40;1m  ");
			}
			j++;
		}
	cout<<endl;
	i++;
	
	}
	cout<<pos1.y<<endl;
}


int CC(){
	int i,j;
	for (i=0;i!=100;){
		
		for (j=0;j!=100;){
			if (pos1.x==j && pos1.y==i){
				map[j][i]=1;
			    goto out;
			}else if (pos2.x==j && pos2.y==i){
				map[j][i]=1;
				goto out;
			}else if (pos3.x==j && pos3.y==i){
				map[j][i]=1;
				goto out;
			}else if (pos4.x==j && pos4.y==i){
					map[j][i]=1;
					goto out;
			}
			map[j][i]=0;
			out:;
			j++;
		}
		i++;
	}
	CCCube();
}


int main(){
	
	for (;;){
		CC();
		RotAdd();
		Sleep();
		clrscr();
	}
	return 0;
	
}