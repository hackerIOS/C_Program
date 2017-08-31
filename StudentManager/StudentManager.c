//Student Manager System
//专业造轮子

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//总数据结构体
struct Student{
	char StudentNumber[5];//学号
	char StudentName[100];//姓名
	char StudentAge[5];//年龄
	char StudentSX;//性别
	char StudentBornDay[10];//生日
	char StudentAddress[50];//地址
	char StudentP[50];//电话
	char StudentE[50];//Email
	
};


int StudentNum=0;
//学生个数
char*DataBasePath;
//数据库绝对路径
struct Student* Students;
//声明结构体Students

int FileLong=0;
//对应文件长度

//获取字符串长度
int GetStrLen(char*GetStr){
	int DataLen=0;

	for(;GetStr[DataLen]!='\0';){
		DataLen++;
	}

	return DataLen;
}


//截取字符串
char* StrCutStr(char*TStr,char* FindStr){
	int SrcLen=GetStrLen(TStr);
	int CutLen=GetStrLen(FindStr);
	char* Blank="";
	int MainLooper;
	int CutLooper;
	int SaveCL;
	int SaveML;


	for (MainLooper=0;TStr[MainLooper]!='\0';MainLooper++)
	{
		SaveML=MainLooper;
		if (TStr[MainLooper]==FindStr[0]){
			for (CutLooper=0;TStr[MainLooper]==FindStr[CutLooper];){
				MainLooper++;
				CutLooper++;
				SaveCL=CutLooper;

				if (TStr[MainLooper]==FindStr[CutLen-1] && CutLooper==CutLen-1){
					
					char*CutRS=(char*)malloc(sizeof(char)*MainLooper-CutLen+1);
					int LastLooper;
					for(LastLooper=0;LastLooper<=MainLooper-CutLen;){
						CutRS[LastLooper]=TStr[LastLooper];
						LastLooper++;

					}
					if (LastLooper-1==MainLooper-CutLen){
					    CutRS[LastLooper]='\0';

					    return CutRS;
					}else {
						MainLooper=SaveML;

					}
				}


			}
		}
		CutLooper=0;

	}
	
	return (char*)Blank;
}



//读取文件
char*ReadFileData(char *ReadPathC){
	FILE *FP;
	char*ReturnData;

	FileLong=0;
	if(FP=fopen(ReadPathC,"r")){
		FileLong++;
		ReturnData=(char*)malloc(sizeof(char)*FileLong);

	}else
	{
		printf("读取文件失败检查对应目录文件\n");
		return "";
	}
	while (feof(FP)==0)
	{
		char*TempData;

		ReturnData[FileLong-1]=fgetc(FP);
		TempData=ReturnData;
		
		FileLong++;
		ReturnData=(char*)malloc(sizeof(char)*(FileLong+2));
		ReturnData=TempData;
		//free(TempData);
	}
	ReturnData[FileLong+1]='\0';
	return ReturnData;

}




//写文件
int WriteFile(char* WriteData,char* PathData,char *W_Mode){
	FILE* W_FP;
	W_FP=fopen(PathData,W_Mode);
	fwrite(WriteData,sizeof(char),GetStrLen(WriteData),W_FP);
	fclose(W_FP);
	return 0;
}







//拼接字符串
char*StrATStr(char*LStr,char*RStr){
	char*StrATStrData;
	int StrATStrLen;
	int LStrLooper;
	int RStrLooper;

	StrATStrLen=GetStrLen(LStr)+GetStrLen(RStr);

	StrATStrData=(char*)malloc(sizeof(char)*StrATStrLen+1);

	for(LStrLooper=0;LStrLooper<GetStrLen(LStr);LStrLooper++){
		StrATStrData[LStrLooper]=LStr[LStrLooper];
	}

	for(RStrLooper=0;RStrLooper<GetStrLen(RStr);RStrLooper++){
		StrATStrData[LStrLooper+RStrLooper]=RStr[RStrLooper];
	}
	StrATStrData[LStrLooper+RStrLooper]='\0';

	return StrATStrData;
}


int StrCmp(char* LStr,char*RStr){
	while(*LStr && *RStr && *LStr==*RStr){
		++LStr;
		++RStr;
	}
	return *LStr-*RStr;
}


int ReadStrDataToStruct(char*DataBaseData){
	int DBDLooper=0;
	int DataPart=0;
    int SNLooper=0;

	struct Student*CopyData;
	//for (;DataBaseData[DBDLooper]!='\0';)
	for(;DBDLooper<=FileLong;)
	{
		if(DataPart==0){
			if(StudentNum!=0){
				
				CopyData=(struct Student*)malloc(sizeof (struct Student)*(StudentNum+1));
				CopyData=Students;

				
			}
			//获取学号
			StudentNum++;
			Students=(struct Student*)malloc(sizeof (struct Student)*StudentNum);
			if(StudentNum>1){
			    Students=CopyData;
			}


			for(;DataBaseData[DBDLooper]!=' ';DBDLooper++){
				Students[StudentNum-1].StudentNumber[SNLooper]=DataBaseData[DBDLooper];
				SNLooper++;
			}
			Students[StudentNum-1].StudentNumber[SNLooper]='\0';
			DBDLooper++;
			DataPart++;
			SNLooper=0;

		}else if(DataPart==1)
		{
			//获取姓名

			for(;DataBaseData[DBDLooper]!=' ';DBDLooper++){
				Students[StudentNum-1].StudentName[SNLooper]=DataBaseData[DBDLooper];
				SNLooper++;
			}
			Students[StudentNum-1].StudentName[SNLooper]='\0';
			DBDLooper++;
			DataPart++;
			SNLooper=0;

		}else if(DataPart==2)
		{
			//获取年龄
			

			for(;DataBaseData[DBDLooper]!=' ';DBDLooper++){
				Students[StudentNum-1].StudentAge[SNLooper]=DataBaseData[DBDLooper];
				SNLooper++;
			}
			Students[StudentNum-1].StudentAge[SNLooper]='\0';
			DBDLooper++;
			DataPart++;
			SNLooper=0;
		}else if(DataPart==3)
		{
			//获取性别

			Students[StudentNum-1].StudentSX=DataBaseData[DBDLooper];
			DBDLooper++;
			DBDLooper++;

			DataPart++;
			SNLooper=0;

		}else if(DataPart==4)
		{
			//获取生日

			for(;DataBaseData[DBDLooper]!=' ';DBDLooper++){
				Students[StudentNum-1].StudentBornDay[SNLooper]=DataBaseData[DBDLooper];
				SNLooper++;
			}
			Students[StudentNum-1].StudentBornDay[SNLooper]='\0';
			DBDLooper++;
			DataPart++;
			SNLooper=0;
		}else if(DataPart==5)
		{
			//获取地址
			

			for(;DataBaseData[DBDLooper]!=' ';DBDLooper++){
				Students[StudentNum-1].StudentAddress[SNLooper]=DataBaseData[DBDLooper];
				SNLooper++;
			}
			Students[StudentNum-1].StudentAddress[SNLooper]='\0';
			DBDLooper++;
			DataPart++;
			SNLooper=0;
		}else if(DataPart==6)
		{
			//获取电话
			

			for(;DataBaseData[DBDLooper]!=' ';DBDLooper++){
				Students[StudentNum-1].StudentP[SNLooper]=DataBaseData[DBDLooper];
				SNLooper++;
			}

			Students[StudentNum-1].StudentP[SNLooper]='\0';
			DBDLooper++;
			DataPart++;
			SNLooper=0;
		}else if(DataPart==7)
		{
			//获取EM
			

			for(;DataBaseData[DBDLooper]!='\n' && DataBaseData[DBDLooper]!='\0';DBDLooper++){
				Students[StudentNum-1].StudentE[SNLooper]=DataBaseData[DBDLooper];
				SNLooper++;
			}
			Students[StudentNum-1].StudentE[SNLooper]='\0';
			DBDLooper++;
			DataPart=0;
			SNLooper=0;
		}

	}
	return 0;
}





int LooperSearch(int SelectType){
	int LooperStuInfo=0;
	
	if (SelectType==1)
	{
		char SN_Data[5];
		printf("Enter the student's number\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(StrCmp(Students[LooperStuInfo].StudentNumber,SN_Data)==0){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}else if (SelectType==2)
	{
		char SN_Data[100];
		printf("Enter the student's name\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(StrCmp(Students[LooperStuInfo].StudentName,SN_Data)==0){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}else if (SelectType==3)
	{
		char SN_Data[5];
		printf("Enter the student's age\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(StrCmp(Students[LooperStuInfo].StudentAge,SN_Data)==0){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}else if (SelectType==4)
	{
		char SN_Data[2];
		printf("Enter the student's sex\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(SN_Data[0]==Students[LooperStuInfo].StudentSX){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}else if (SelectType==5)
	{
		char SN_Data[10];
		printf("Enter the student's birthday\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(StrCmp(Students[LooperStuInfo].StudentBornDay,SN_Data)==0){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}else if (SelectType==6)
	{
		char SN_Data[50];
		printf("Enter the student's address\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(StrCmp(Students[LooperStuInfo].StudentAddress,SN_Data)==0){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}else if (SelectType==7)
	{
		char SN_Data[50];
		printf("Enter the student's phone number\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(StrCmp(Students[LooperStuInfo].StudentP,SN_Data)==0){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}else if (SelectType==8)
	{
		char SN_Data[50];
		printf("Enter the student's E-mail\n");

		scanf("%s",&SN_Data);
		for(;LooperStuInfo<StudentNum;LooperStuInfo++){
			//if(Students[LooperStuInfo].StudentNumber[0]==SN_Data[0]){
			if(StrCmp(Students[LooperStuInfo].StudentE,SN_Data)==0){
				printf("%s ",Students[LooperStuInfo].StudentNumber);
				
				printf("%s ",Students[LooperStuInfo].StudentName);
				printf("%s ",Students[LooperStuInfo].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
				if(Students[LooperStuInfo].StudentSX=='B'){
					printf("男 ");

				}else
				{
					printf("女 ");
				}

				printf("%s ",Students[LooperStuInfo].StudentBornDay);
				printf("%s ",Students[LooperStuInfo].StudentAddress);
				printf("%s ",Students[LooperStuInfo].StudentP);
				printf("%s ",Students[LooperStuInfo].StudentE);
				printf("\n");
			}
		}
	}

	return 0;
}


int SearchSystem(){
	int InputSelectKey=0;
	printf("\nChoose a search method that you want\n");
	printf("1.Student Number\n");
	printf("2.Student Name\n");
	printf("3.Student Age\n");
	printf("4.Student Sex\n");
	printf("5.Student Birthday\n");
	printf("6.Student Address\n");
	printf("7.Student Phone Number\n");
	printf("8.Student E-mail\n");

	SelectKey:;
	scanf("%d",&InputSelectKey);
	if (InputSelectKey==1)
	{
		LooperSearch(1);

	}else if (InputSelectKey==2)
	{
		LooperSearch(2);
	}else if (InputSelectKey==3)
	{
		LooperSearch(3);
	}else if (InputSelectKey==4)
	{
		LooperSearch(4);
	}else if (InputSelectKey==5)
	{
		LooperSearch(5);
	}else if (InputSelectKey==6)
	{
		LooperSearch(6);
	}else if (InputSelectKey==7)
	{
		LooperSearch(7);
	}else if (InputSelectKey==8)
	{
		LooperSearch(8);
	}else{
		printf ("Try again please");
		goto SelectKey;
	}
	return 0;
}




int Del_TG(int Del_TG_Num){
	struct Student *CopyData;

	char*ReWrite_Data;
	int ReWrite_S_Len=0;
	int ReWrite_S_L_Len=0;



	int Copy_Looper=0;
	int ReWrite_Looper=0;

	CopyData=(struct Student*)malloc(sizeof(struct Student)*StudentNum-1);
	
	

	for(;Del_TG_Num-1!=StudentNum;Del_TG_Num++){
		Students[Del_TG_Num-1]=Students[Del_TG_Num];
	}


	for(;Copy_Looper!=StudentNum-1;Copy_Looper++){
		CopyData[Copy_Looper]=Students[Copy_Looper];
	}

	StudentNum--;

	Students=(struct Student*)malloc(sizeof(struct Student)*StudentNum);

	Students=CopyData;

	for (;ReWrite_Looper!=StudentNum;ReWrite_Looper){
		int ReSet_Looper=0;

		char*ReWrite_S_Data;
		char*Copy_RW_Data;

		char ReWrite_SX_Data[5];
		ReWrite_SX_Data[0]=Students[ReWrite_Looper].StudentSX;
		ReWrite_SX_Data[1]='\0';
		ReWrite_S_Data=StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr("\n",Students[ReWrite_Looper].StudentNumber)," "),Students[ReWrite_Looper].StudentName)," "),Students[ReWrite_Looper].StudentAge)," "),ReWrite_SX_Data)," "),Students[ReWrite_Looper].StudentBornDay)," "),Students[ReWrite_Looper].StudentAddress)," "),Students[ReWrite_Looper].StudentP)," "),Students[ReWrite_Looper].StudentE);
		
		Copy_RW_Data=(char*)malloc(sizeof(char)*ReWrite_S_Len);
		
		ReWrite_S_L_Len=ReWrite_S_Len;

		ReWrite_S_Len=ReWrite_S_Len+GetStrLen(ReWrite_S_Data);


		if(ReWrite_Looper!=0){
			Copy_RW_Data=ReWrite_Data;
		}

		
		ReWrite_Data=(char*)malloc(sizeof(char)*(ReWrite_S_Len));
		ReWrite_Data=Copy_RW_Data;


		for(ReSet_Looper=0;ReWrite_S_L_Len-1!=ReWrite_S_Len;ReWrite_S_L_Len++,ReSet_Looper++){
			ReWrite_Data[ReWrite_S_L_Len-1]=ReWrite_S_Data[ReSet_Looper];

		}

	}




	WriteFile(ReWrite_Data,DataBasePath,"w");
	

	return 0;
}





int DelStudentINF(){
	int ListAllSDINF_Looper=0;
	int Select_TG;

	for(;ListAllSDINF_Looper<StudentNum;ListAllSDINF_Looper++){

		printf("%d.",ListAllSDINF_Looper+1);

		printf("%s ",Students[ListAllSDINF_Looper].StudentNumber);
				
		printf("%s ",Students[ListAllSDINF_Looper].StudentName);
		printf("%s ",Students[ListAllSDINF_Looper].StudentAge);
				//printf("%s",Students[LooperStuInfo].StudentNumber);
		if(Students[ListAllSDINF_Looper].StudentSX=='B'){
			printf("男 ");

		}else
		{
			printf("女 ");
		}

		printf("%s ",Students[ListAllSDINF_Looper].StudentBornDay);
		printf("%s ",Students[ListAllSDINF_Looper].StudentAddress);
		printf("%s ",Students[ListAllSDINF_Looper].StudentP);
		printf("%s ",Students[ListAllSDINF_Looper].StudentE);
		printf("\n");
	
	}

	printf("Select a target you want to delete\n");




Del_TG_Back:;
	scanf("%d",&Select_TG);
	if (Select_TG<=ListAllSDINF_Looper && Select_TG>0){
		Del_TG(Select_TG);
	}else
	{
		goto Del_TG_Back;
	}





	return 0;
}





int AddStudentINF(){
	char* ATSD_Data;


	struct Student*CopyData;
	int LooperCheckData=0;
	int LooperSetData=0;

	char SN_IP_Data[5];//Student Number Input Data


	char SNa_IP_Data[100];//Student Name
	char SA_IP_Data[5];//Age
	char SS_IP_Data=' ';//Sex
	char SS_IP_Data_Str[5];

	char SBD_IP_Data[10];//Birthday
	char SAD_IP_Data[50];//Addr
	char SP_IP_Data[50];//Phone
	char SE_IP_Data[50];//E_mail


	CopyData=(struct Student*)malloc(sizeof (struct Student)*(StudentNum+1));
	CopyData=Students;
	StudentNum++;
	Students=(struct Student*)malloc(sizeof (struct Student)*StudentNum);
	Students=CopyData;
	printf("Enter the student's number,No more than 6 figures\n");

SN_Back:;

	scanf("%s",&SN_IP_Data);
	for (;LooperCheckData!=StudentNum-1;LooperCheckData++){
		if(StrCmp(Students[LooperCheckData].StudentNumber,SN_IP_Data)==0){
			printf("Same student number,Try again please");
			goto SN_Back;

		}
	}


	
	for (;SN_IP_Data[LooperSetData]!='\0';LooperSetData++){
		Students[StudentNum-1].StudentNumber[LooperSetData]=SN_IP_Data[LooperSetData];
	}
	Students[StudentNum-1].StudentNumber[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;


	printf("Enter the student's name\n");


	scanf("%s",&SNa_IP_Data);


	
	for (;SNa_IP_Data[LooperSetData]!='\0';LooperSetData++){
		Students[StudentNum-1].StudentName[LooperSetData]=SNa_IP_Data[LooperSetData];
	}

	Students[StudentNum-1].StudentName[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;


	printf("Enter the student's age\n");

	scanf("%s",&SA_IP_Data);

	
	for (;SA_IP_Data[LooperSetData]!='\0';LooperSetData++){
		Students[StudentNum-1].StudentAge[LooperSetData]=SA_IP_Data[LooperSetData];
	}
	Students[StudentNum-1].StudentAge[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;


	printf("Enter the student's sex,If it's a male, type B, and if it's female, type G\n");

	scanf("%s",&SS_IP_Data_Str);

	Students[StudentNum-1].StudentSX=SA_IP_Data[LooperSetData];
	
	//Students[StudentNum-1].StudentAge[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;

	printf("Enter the student's birthday\n");

	scanf("%s",&SBD_IP_Data);

	
	for (;SBD_IP_Data[LooperSetData]!='\0';LooperSetData++){
		Students[StudentNum-1].StudentBornDay[LooperSetData]=SBD_IP_Data[LooperSetData];
	}
	Students[StudentNum-1].StudentBornDay[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;

	printf("Enter the student's address\n");

	scanf("%s",&SAD_IP_Data);

	
	for (;SAD_IP_Data[LooperSetData]!='\0';LooperSetData++){
		Students[StudentNum-1].StudentAddress[LooperSetData]=SAD_IP_Data[LooperSetData];
	}
	Students[StudentNum-1].StudentAddress[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;

	printf("Enter the student's phone number\n");

	scanf("%s",&SP_IP_Data);

	
	for (;SP_IP_Data[LooperSetData]!='\0';LooperSetData++){
		Students[StudentNum-1].StudentP[LooperSetData]=SP_IP_Data[LooperSetData];
	}
	Students[StudentNum-1].StudentP[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;

	printf("Enter the student's E-mail\n");


	scanf("%s",&SE_IP_Data);

	
	for (;SE_IP_Data[LooperSetData]!='\0';LooperSetData++){
		Students[StudentNum-1].StudentE[LooperSetData]=SE_IP_Data[LooperSetData];
	}
	Students[StudentNum-1].StudentE[LooperSetData]='\0';
	LooperCheckData=0;
	LooperSetData=0;

	//SS_IP_Data_Str[0]=SS_IP_Data;
	//SS_IP_Data_Str[1]='\0';
	ATSD_Data=(char*)malloc(sizeof(char)*(300));

	ATSD_Data=StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr(StrATStr("\n",SN_IP_Data)," "),SNa_IP_Data)," "),SA_IP_Data)," "),SS_IP_Data_Str)," "),SBD_IP_Data)," "),SAD_IP_Data)," "),SP_IP_Data)," "),SE_IP_Data);


	WriteFile(ATSD_Data,DataBasePath,"a");



	return 0;
}




int ModifySystem(){
	int InputSelectKey=0;
	printf("1.Delete specified student information\n");

	printf("2.Add a student information\n");
	SelectKey:;
	scanf("%d",&InputSelectKey);
	if (InputSelectKey==1){
		DelStudentINF();
	}else if (InputSelectKey==2){
		AddStudentINF();
	}else{
		printf ("Try again please");
		goto SelectKey;
	}


	return 0;
}


int MainScreen(){
	int InputSelectKey=0;

	printf("%s","Welcome To Student Manager System\n");
	printf("%s","\n1.Search Student Information\n");
	printf("%s","2.Modify Student Information\n");
	printf("%s","3.Exit System\n");
	printf("%s","Please Enter a Number:");

	
	SelectKey:;
	scanf("%d",&InputSelectKey);
	if (InputSelectKey==1){
		SearchSystem();
	}else if (InputSelectKey==2){
		ModifySystem();
	}else if (InputSelectKey==3){
		exit(0);
	}else{
		printf ("Try again please");
		goto SelectKey;
	}
	
	
	return 0;
}


int main(int argc,char *argv[]){
	
	char*DataTest;



	DataBasePath=StrATStr(StrCutStr(argv[0],"StudentManager.exe"),"DataBase\\SM_Data.dat");
	//printf(ReadFileData(DataBasePath));
	ReadStrDataToStruct(ReadFileData(DataBasePath));

	//printf("%s ",Students[2].StudentName);
    printf("\n");
	MainScreen();
	
	system("pause");
	return 0;
}