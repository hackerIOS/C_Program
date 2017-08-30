#include <string>
#include <stdio.h>
using namespace std;
int main(){
	string gap;
	gap="h/'///ajd/\\65";
	int pos=0,opos=0;
	
	while(1){
		opos=pos;
		pos=gap.find("\\");
		if (pos==0 || pos==-1){
			break;
		}else if (pos==opos){
			break;
		}
		gap.replace(pos,1,"/");
		
	}
	char*a=(char*)gap.c_str();
	printf(a);
}