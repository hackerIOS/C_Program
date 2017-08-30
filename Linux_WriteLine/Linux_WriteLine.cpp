#include <iostream>
using namespace std;

#define MX 50
#define MY 50
//int MX=50,MY=50;

int Map[MX][MY];

int PrintLine(){
	int i,j;
	for (i=0;i!=50;){
		for (j=0;j!=50;){
			
			if (Map[j][i]==1){
				cout<<"\033[41;1m  ";
			}else if (Map[j][i]==0){
				//printf("\033[40;1m  ");
				cout<<"\033[40;1m  ";
			}
			j++;
		}
	cout<<endl;
	i++;
	
	}
	//cout<<pos1.y<<endl;
}


int CCMap(){
	int x,y;
	for (y=0;y!=50;){
		for (x=0;x!=50;){
			Map[x][y]=0;
			x++;
		}
		y++;
	}
}


int WriteLine(int x1,int y1,int x2,int y2){
	int x,y,l;
	CCMap();
	if (x1>=x2){
		x=x1-x2;
	}else if (x1<x2){
		x=x2-x1;
	}

	
	if (y1>=y2){
		y=y1-y2;
	}else if (y1<y2){
		y=y2-y1;
	}
	
	
	if (x>y){
		l=x/y;
	}else if (x<y){
		l=y/x;
	}else if (x==y){
		
		for (int addnum=0;addnum!=x;){
			Map[x1+addnum][y1+addnum]=1;
			addnum++;
		}
	}
	PrintLine();
	
	//for (;;){
	//}
	//WriteMap
	
}


int main (){
	WriteLine(3,3,20,20);
	for (;;){
		
	}
	return 0;
}