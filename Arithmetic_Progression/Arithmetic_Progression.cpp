#include <iostream>
#include <string.h>
using namespace std;
int main(){
	back1:;
	float cc;
	char a;
	cout<<"求等差数列的前N项和"<<endl;
	cout<<"已知公差输入1 "<<endl;
	cout<<"已知首项输入2 "<<endl;
	cin>>a;
	if (a=='1'){
		float n,d,an;
		cout<<"输入N值"<<endl;
		cin>>n;
		cout<<"输入公差"<<endl;
		cin>>d;
		cout<<"输入首项"<<endl;
		cin>>an;
		cc=n*n*d-n*d;
		cc=cc/2+n*an;
		cout<<cc<<endl;;
		goto back1;
	}else if (a=='2'){
		float n,a1,an;
		cout<<"输入N值"<<endl;
		cin>>n;
		cout<<"输入末项"<<endl;
		cin>>a1;
		cout<<"输入首项"<<endl;
		cin>>an;
		cc=n*a1+n*an;
		cc=cc/2;
		cout<<cc<<endl;;
		goto back1;
	}else{
		cout<<"输入的值不为1或2"<<endl;
		goto back1;
	}
	
	return 0;
}