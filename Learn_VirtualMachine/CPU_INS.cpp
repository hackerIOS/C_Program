//CPU instruction
//Support 16 bit system
#include <iostream>
#include <cstdlib>
#include <vector>

#include <cstdio>

using namespace std;
FILE* BIN_FILE;
int Read_Point=0;
//string SRC="";
//vector<char>SRC1;

int CPU_ZF;
int CPU_PF;
int CPU_SF;
int CPU_CF;
int CPU_OF;
int CPU_AF;
//Run result flag reg

int CPU_DF;
int CPU_IF;
int CPU_TF;
//now flag reg


int CPU_AL;
int CPU_AH;
int CPU_AX;

int CPU_BL;
int CPU_BH;
int CPU_BX;

int CPU_CL;
int CPU_CH;
int CPU_CX;

int CPU_DL;
int CPU_DH;
int CPU_DX;


/*int CPU_INS_MOV(int CPU_INS_WMOV,int CPU_INS_MOV_DATA){
	CPU_INS_WMOV=CPU_INS_MOV_DATA;
	Read_Point++;
	Read_Point++;
	return 0;
}
*/


int AnalyseIns(char INS_DATA){
	char TempDS,TempDS1;
	
	switch (INS_DATA){
		case 0xb8://MOV AX,DATA
		cout<<"MOV AX,";
		Read_Point++;
	    Read_Point++;
		TempDS=fgetc(BIN_FILE);
		//cout<<fgetc(BIN_FILE)<<TempDS<<endl;
		TempDS1=fgetc(BIN_FILE);
		printf("%02X",TempDS1);
		printf("%02X",TempDS);
		CPU_AX=256*TempDS1+TempDS;
		cout<<endl;
		printf("%02X",CPU_AX);
		//CPU_INS_MOV(CPU_AX,256*TempDS1+TempDS);
		
		cout<<endl;
		
		break;
		case 0xbb://MOV BX,DATA
		cout<<"MOV BX,";
		
		Read_Point++;
		Read_Point++;
		TempDS=fgetc(BIN_FILE);
		//cout<<fgetc(BIN_FILE)<<TempDS<<endl;
		TempDS1=fgetc(BIN_FILE);
		printf("%02X",TempDS1);
		printf("%02X",TempDS);
		CPU_BX=16*TempDS1+TempDS;
		TempDS=0;
		cout<<endl;
		
		break;
		case 0xb9://MOV CX,DATA
		cout<<"MOV CX,";
		Read_Point++;
		Read_Point++;
		TempDS=fgetc(BIN_FILE);
		//cout<<fgetc(BIN_FILE)<<TempDS<<endl;
		TempDS1=fgetc(BIN_FILE);
		printf("%02X",TempDS1);
		printf("%02X",TempDS);
		CPU_CX=16*TempDS1+TempDS;
		TempDS=0;
		cout<<endl;
		
		break;
		case 0xba://MOV DX,DATA
		cout<<"MOV DX,";
		Read_Point++;
		Read_Point++;
		TempDS=fgetc(BIN_FILE);
		//cout<<fgetc(BIN_FILE)<<TempDS<<endl;
		TempDS1=fgetc(BIN_FILE);
		printf("%02X",TempDS1);
		printf("%02X",TempDS);
		CPU_DX=16*TempDS1+TempDS;
		TempDS=0;
		cout<<endl;
		break;
		
		case 0xb0://MOV AL,DATA
		
		break;
		case 0xb3://MOV BL,DATA
		break;
		case 0xb1://MOV CL,DATA
		break;
		case 0xb2://MOV DL,DATA
		break;
		
		case 0xb4://MOV AH,DATA
		break;
		case 0xb7://MOV BH,DATA
		break;
		case 0xb5://MOV CH,DATA
		break;
		case 0xb6://MOV DH,DATA
		break;
		//Add DATA00000000000000000
		case 0x89://MOV REG TO REG
		break;
		
		
		case 0x8b://ADDRESS TO REG
		break;
		
		
		case 0x01://ADD REG TO REG
		break;
		//INT 000000000000000
		case 0xcd:
		cout<<"INT ";
		Read_Point++;
		printf("%02X",fgetc(BIN_FILE));
		cout<<endl;
		break;
		//RET   000000000000000
		case 0xc3://RET
		
		break;
		//CALL 00000000000000000
		case 0xe8://CALL Size
		
		break;
		
		//short jmp 000000000000
		case 0xeb://JMP
		
		break;
		case 0x90: //XCHG AX,AX  //nop
		cout<<"XCHG AX,AX"<<endl;
		
		break;
		case 0x93:  //XCHG AX,BX
		TempDS=CPU_AX;
		TempDS1=CPU_BX;
		CPU_AX=TempDS1;
		CPU_BX=TempDS;
		break;
		case 0x91:
		TempDS=CPU_AX;
		TempDS1=CPU_CX;
		CPU_AX=TempDS1;
		CPU_CX=TempDS;
		break;
		case 0x92:
		TempDS=CPU_AX;
		TempDS1=CPU_DX;
		CPU_AX=TempDS1;
		CPU_DX=TempDS;
		break;
		case 0x87:
		Read_Point++;
		if (fgetc(BIN_FILE)==0xdb){
			cout<<"XCHG BX,BX"<<endl;
		}else if (fgetc(BIN_FILE)==0xd9){
			TempDS=CPU_BX;
		    TempDS1=CPU_CX;
		    CPU_BX=TempDS1;
		    CPU_CX=TempDS;
		}else if (fgetc(BIN_FILE)==0xda){
			TempDS=CPU_BX;
		    TempDS1=CPU_DX;
		    CPU_BX=TempDS1;
		    CPU_DX=TempDS;
		}else if (fgetc(BIN_FILE)==0xcb){
			TempDS=CPU_BX;
		    TempDS1=CPU_CX;
		    CPU_BX=TempDS1;
		    CPU_CX=TempDS;
		}else if (fgetc(BIN_FILE)==0xc9){
			cout<<"XCHG CX,CX"<<endl;
		}else if (fgetc(BIN_FILE)==0xca){
			TempDS=CPU_DX;
		    TempDS1=CPU_CX;
		    CPU_DX=TempDS1;
		    CPU_CX=TempDS;
		}else if (fgetc(BIN_FILE)==0xd3){
			TempDS=CPU_BX;
		    TempDS1=CPU_DX;
		    CPU_BX=TempDS1;
		    CPU_DX=TempDS;
		}else if (fgetc(BIN_FILE)==0xd1){
			TempDS=CPU_CX;
		    TempDS1=CPU_DX;
		    CPU_CX=TempDS1;
		    CPU_DX=TempDS;
		}else if (fgetc(BIN_FILE)==0xd2){
			cout<<"XCHG DX,DX"<<endl;
		}
		break;
		case 0x29:
		if (fgetc(BIN_FILE)==0xc0){
			//SUB AX,AX
			CPU_AX=CPU_AX-CPU_AX;
		}else if (fgetc(BIN_FILE)==0xd8){
			//SUB AX,BX
			CPU_AX=CPU_AX-CPU_BX;
		}else if (fgetc(BIN_FILE)==0xc8){
			//SUB AX,CX
			CPU_AX=CPU_AX-CPU_CX;
		}else if (fgetc(BIN_FILE)==0xd0){
			//SUB AX,DX
			CPU_AX=CPU_AX-CPU_DX;
		}else if (fgetc(BIN_FILE)==0xc3){
			//SUB BX,AX
			CPU_BX=CPU_BX-CPU_AX;
		}else if (fgetc(BIN_FILE)==0xdb){
			//SUB BX,BX
			CPU_BX=CPU_BX-CPU_BX;
		}else if (fgetc(BIN_FILE)==0xcb){
			//SUB BX,CX
			CPU_BX=CPU_BX-CPU_CX;
		}else if (fgetc(BIN_FILE)==0xd3){
			//SUB BX,DX
			CPU_BX=CPU_BX-CPU_DX;
		}else if (fgetc(BIN_FILE)==0xc1){
			//SUB CX,AX
			CPU_CX=CPU_CX-CPU_AX;
		}else if (fgetc(BIN_FILE)==0xd9){
			//SUB CX,BX
			CPU_CX=CPU_CX-CPU_BX;
		}else if (fgetc(BIN_FILE)==0xc9){
			//SUB CX,CX
			CPU_CX=CPU_CX-CPU_CX;
		}else if (fgetc(BIN_FILE)==0xd1){
			//SUB CX,DX
			CPU_CX=CPU_CX-CPU_DX;
		}else if (fgetc(BIN_FILE)==0xc2){
			//SUB DX,AX
			CPU_DX=CPU_DX-CPU_AX;
		}else if (fgetc(BIN_FILE)==0xda){
			//SUB DX,BX
			CPU_DX=CPU_DX-CPU_BX;
		}else if (fgetc(BIN_FILE)==0xca){
			//SUB DX,CX
			CPU_DX=CPU_DX-CPU_CX;
		}else if (fgetc(BIN_FILE)==0xd2){
			//SUB DX,DX
			CPU_DX=CPU_DX-CPU_DX;
		}else if (fgetc(BIN_FILE)==0x06){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x1e){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x0e){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x16){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}
		break;
		case 0x83:
		if (fgetc(BIN_FILE)==0xe8){
			//SUB AX,Data
			CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0xeb){
			//SUB AX,Data
			CPU_BX=CPU_BX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0xe9){
			//SUB AX,Data
			CPU_CX=CPU_CX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0xea){
			//SUB AX,Data
			CPU_DX=CPU_DX-fgetc(BIN_FILE);
		}
		break;
		case 0x2b:
		//SUB REG-[Data]
		if (fgetc(BIN_FILE)==0x06){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x1e){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x0e){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x16){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}
		break;
		/*case 0x29:
		if (fgetc(BIN_FILE)==0x06){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x1e){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x0e){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0x16){
			//SUB AX,Data
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}
		break;
		*/
		case 0x2d:
		//SUB AX, L F
		break;
		case 0x81:
		if (fgetc(BIN_FILE)==0xeb){
			//SUB BX,Data L F
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0xe9){
			//SUB AX,Data L F
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}else if (fgetc(BIN_FILE)==0xea){
			//SUB AX,Data L F
			//CPU_AX=CPU_AX-fgetc(BIN_FILE);
		}
		break;
		//PUSH*******
		case 0x50:
		//PUSH AX
		break;
		case 0x53:
		//PUSH BX
		break;
		case 0x51:
		//PUSH CX
		break;
		case 0x52:
		//PUSH DX
		break;
		//INC ****
		case 0x40:
		CPU_AX++;
		break;
		case 0x43:
		CPU_BX++;
		break;
		case 0x41:
		CPU_CX++;
		break;
		case 0x42:
		CPU_DX++;
		break;
		case 0xfe:
		if (fgetc(BIN_FILE)==0xc0){
			CPU_AX++;
			//AL
		}else if (fgetc(BIN_FILE)==0xc4){
			CPU_AX=CPU_AX+256;
			//AH
		}else if (fgetc(BIN_FILE)==0xc3){
			CPU_BX++;
			//BL
		}else if (fgetc(BIN_FILE)==0xc7){
			CPU_BX=CPU_BX+256;
			//BH
		}else if (fgetc(BIN_FILE)==0xc1){
			CPU_CX++;
			//CL
		}else if (fgetc(BIN_FILE)==0xc5){
			CPU_CX=CPU_CX+256;
			//CH
		}else if (fgetc(BIN_FILE)==0xc2){
			CPU_DX++;
			//DL
		}else if (fgetc(BIN_FILE)==0xc6){
			CPU_DX=CPU_DX+256;
			//DH
		}
		break;
	}
	
	return 0;
}



int ReadBINFile(){
	
	cout<<"Enter the file path"<<endl;
	string BIN_FILE_PATH;
	cin>>BIN_FILE_PATH;
	char charData;
	BIN_FILE=fopen(BIN_FILE_PATH.c_str(),"rb+");
	
	cout<<"Please Wait....."<<endl;
	/*for (int TestB=0;feof(BIN_FILE)==0;){
		charData=fgetc(BIN_FILE);
		SRC=SRC+charData;
		TestB++;
	}*/
	
	cout<<"Import success"<<endl;
	
	
}


int main(int argc,char*argv[]){
	ReadBINFile();
	for (;feof(BIN_FILE)==0;){
		Read_Point++;
		AnalyseIns(fgetc(BIN_FILE))==0;
	}
	return 0;
}


/*#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc,char* argv[]){
	FILE* BIN_FILE;
	cout<<"Enter the file path"<<endl;
	string BIN_FILE_PATH;
	cin>>BIN_FILE_PATH;
	char charData;
	
	BIN_FILE=fopen(BIN_FILE_PATH.c_str(),"rb+");
	
	for (int TestB=0;feof(BIN_FILE)==0;){
		charData=fgetc(BIN_FILE);
		if (TestB==8){
			cout<<" ";
		}else if (TestB==16){
			cout<<endl;
			TestB=0;
		}
		printf("%i",charData);
		for (int Sleep=0;Sleep!=2000;){
			Sleep++;
		}
		
		TestB++;
	
	}
	return 0;
}*/