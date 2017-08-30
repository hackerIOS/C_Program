#include <vector>
#include <iostream>
using namespace std;
int main(){
	struct a{
		int e=10;
		int c;
		int d;
	};
	typedef vector<a>lx;//Vector Save a,lx Type
	typedef vector<int>ls;
	lx f;//lx Type
//	vector<a>::iterator iter;
//	iter=f.begin();
	a pb;
	f.push_back(pb);
	for (vector<a>::iterator iter=f.begin();iter!=f.end();iter++){
		cout<<"12345";
	}

	cout<<pb.e;
	cout<<f[0].e<<endl;
	
	return 0;
}