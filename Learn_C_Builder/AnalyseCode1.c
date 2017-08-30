#include <stdio.h>


struct DATA{
	char* TIDENTIFIER;//ID
	int IDLEN=0;//ID Len
	int TTYPE;//0 save    1 no save
	int IDTYPE;//ID type
	//0 Str  1 Num  2 Func  3 ValueType
	//4 itpt  5 unknown
};
int Line=0;
int GetNum;
char* src="main(){\nreturn 0;\n}";

int GetStrLen(char* GSL){
	int RETGSL;
	for (int LoopGSL=0;GSL[LoopGSL]!='\0';){
		LoopGSL++;
		RETGSL=LoopGSL;
	}
	return RETGSL;
}

void AnalyseData(char* AD){
	
}


void next(struct DATA GD){
	
	char SData[GetNum];
	while (1){
	    char TD=*src++;
	    //printf ("%c",TD);
	    
	
	    if (TD>='a' && TD<='z'){
		    //GD.TIDENTIFIER[GD.IDLEN]=TD;
		    
		    SData[GD.IDLEN]=TD;
		    GD.IDLEN++;
		
	    }else if (TD>='A' && TD<='Z'){
	    	SData[GD.IDLEN]=TD;
		    GD.IDLEN++;
	    }else if (TD>='0' && TD<='9'){
	    	SData[GD.IDLEN]=TD;
		    GD.IDLEN++;
	    }else if (TD>=0x5b && TD<=0x60){
	    	if (GD.IDLEN!=0){
	    		//GD.TIDENTIFIER=SData;
	    		GD.IDLEN=0;
	    		//*src--;
	    		break;
	    	}
	    	GD.TIDENTIFIER[0]=TD;
	    	GD.IDTYPE=4;
	    	break;
	    	}else if (TD>=0x7b && TD<=0x7e){
	    		if (GD.IDLEN!=0){
	    		//GD.TIDENTIFIER=SData;
	    		GD.IDLEN=0;
	    		//*src--;
	    		break;
	    	}
	    	GD.TIDENTIFIER[0]=TD;
	    	GD.IDTYPE=4;
	    	break;
	    	}else if (TD>=0x20 && TD<=0x2f){
	    		if (GD.IDLEN!=0){
	    		//GD.TIDENTIFIER=SData;
	    		GD.IDLEN=0;
	    		//
	    		break;
	    	}
	    	GD.TIDENTIFIER[0]=TD;
	    	GD.IDTYPE=4;
	    	break;
	    	}else if (TD>=0x3a && TD<=0x40){
	    		if (GD.IDLEN!=0){
	    		//GD.TIDENTIFIER=SData;
	    		GD.IDLEN=0;
	    		//*src--;
	    		break;
	    	}
	    	GD.TIDENTIFIER[0]=TD;
	    	GD.IDTYPE=4;
	    	break;
	    	}else{
	    		if (GD.IDLEN!=0){
	    			if (GD.IDLEN!=0){
	    		        //GD.TIDENTIFIER=SData;
	    		        GD.IDLEN=0;
	    		        //*src--;
	    		    }
	    		break;
	    	}
	    }
	}
}

int main(){
	printf("%d\n",GetStrLen(src));
	
	GetNum=GetStrLen(src);
	
	struct DATA TDATA[GetNum];
	
	while(Line!=GetNum){
	    next(TDATA[Line]);
	    
	    printf (TDATA[Line].TIDENTIFIER);
	    
	    Line++;
	}
}