#include <iostream>
//Cpp standard input output file
#include <map>
//Cpp STL 
#include <vector>
//Cpp STL

using namespace std;
//GB a std namespace

//Create a new namespace
namespace CreateNamespace{
	int NewFunction(){
		cout<<"This is a namespace"<<endl;
		return 0;
	}
}


class NewClass{
	public:
	int NewClassFunction(){
		cout<<"Function"<<endl;
	}
	private:
	int NewClassData=10;
};

//
class ReLoadClass:public NewClass{//Class
	public:
	int NewClassFunction(){
		
		cout<<"function"<<endl;
	}//Class Reset
};


/*int operator+(int& ReLoad1,int& ReLoad2){
	return ReLoad1-ReLoad2;
}*/


template<class T>
class TemplateDataOutput{
	private:
	T OutputData;
	public:
	int OutputDataFunction(T InputData){
		OutputData=InputData;
		cout<<OutputData<<endl;
	}
};


int main(int argc,char* argv[]){
	CreateNamespace::NewFunction();
	//using namespace
	ReLoadClass *RLC=new ReLoadClass();
	RLC->NewClassFunction();
	//ReLoad result
	TemplateDataOutput<int>NewInput;
	NewInput.OutputDataFunction(1);
	
	
	return 0;
}