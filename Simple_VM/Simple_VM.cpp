
//The Simple Virtual Machine


//Virtual Stack
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int HStack[256];
int SP=-1;//STACK POINTER
int IP=0;//INSTRUCTION POINTER

int Running=1;
string HPUSH="PUSH",
	HPOP="POP",
	HADD="ADD",
	HHLT="HLT",
	HMOV="MOV",
	HSUB="SUB",
	HJMP="JMP",
	HRET="RET",
	HCALL="CALL",
	HAX="AX",
	HBX="BX",
	HCX="CX",
	HDX="DX";



const char *CODE="PUSH 100 PUSH 200 PUSH 20 POP  PUSH 10\nPUSH 11\nADD\nPOP POP POP\n";
//main Code


vector<string>SaveC;//SaveCode
int ReSC=1;//resizeSaveCode


int VM(){
	//cout<<"Analysis Result"<<endl;
	while (Running){
		if (SaveC[IP].c_str()==HHLT){
			Running=0;
			cout<<"Done!"<<"Virtual Machine Stop"<<endl;
			
		}else if (SaveC[IP].c_str()==HPUSH){
			SP++;
			IP++;
			HStack[SP]=atoi(SaveC[IP].c_str());
			//cout<<HStack[SP];
			IP--;
		}else if (SaveC[IP].c_str()==HPOP){
			int OutputPOP=HStack[SP];
			SP--;
			cout<<"POP Data:"<<OutputPOP<<endl;
		}else if (SaveC[IP].c_str()==HADD){
			int SPH=HStack[SP];
			SP--;
			int SPL=HStack[SP];
			int AddNum=SPH+SPL;
			HStack[SP]=AddNum;
		}else{
			cout<<SaveC[IP].c_str();
		}
		IP++;
	}
}


int AnalysisWord(string SaveWord){

	SaveC[ReSC-1]=SaveWord;
	cout<<SaveWord<<endl;
	
	ReSC++;
	SaveC.resize(ReSC);
	
}


int AnalysisCode(){
	int LoopAnalysis=0;
	vector<char>SaveData;
	int relong=1;
	SaveData.resize(relong);
	for (;CODE[LoopAnalysis]!='\0';){
		if (CODE[LoopAnalysis]>='A' && CODE[LoopAnalysis]<='Z'){
			SaveData[relong-1]=CODE[LoopAnalysis];
			relong++;
			SaveData.resize(relong);
		}else if (CODE[LoopAnalysis]==' '){
			if (SaveData.empty()==true){
				LoopAnalysis++;
				break;
			}else{
				
				string CopyData(SaveData.begin(),SaveData.end());
				AnalysisWord(CopyData);
				
				SaveData.clear();
				relong=1;
				SaveData.resize(relong);
			}
			
		}else if (CODE[LoopAnalysis]>='a' && CODE[LoopAnalysis]<='z'){
			SaveData[relong-1]=CODE[LoopAnalysis];
			relong++;
			SaveData.resize(relong);
		}else if (CODE[LoopAnalysis]=='\n'){
			
			if (SaveData.empty()==true){
				LoopAnalysis++;
				break;
			}else{
				
				string CopyData(SaveData.begin(),SaveData.end());
				AnalysisWord(CopyData);
				
				SaveData.clear();
				relong=1;
				SaveData.resize(relong);
			}
				
		}else if (CODE[LoopAnalysis]>='0' && CODE[LoopAnalysis]<='9'){
			SaveData[relong-1]=CODE[LoopAnalysis];
			relong++;
			SaveData.resize(relong);
			
		}
		
		LoopAnalysis++;
		
	}
	
}

int main(int argc,char*argv[]){
	SaveC.resize(ReSC);
	cout<<"Main Code is:\n"<<CODE<<"\nAnalysis Result"<<endl;
	AnalysisCode();
	
	VM();
	
	while(1){
	}
	return 0;
}