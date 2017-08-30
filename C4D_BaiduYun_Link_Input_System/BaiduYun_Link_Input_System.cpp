//BaiduYun_Link_Input_System
//....
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
//char FG1='<Download>';
void ReadDownload(){
	clrscr();
	printf("Nothing at all");
}
void ReadVideo(){
	clrscr();
	std::cout<<"Nothing at all";
}
void ReadText(){
	clrscr();
	std::cout<<"Nothing at all";
}
void WriteDownload(){
	char* input;
	//std::string input;
	clrscr();
	std::cout<<"Enter download link address"<<std::endl;
//	std::cin>>input;
	scanf("%s",&input);

//    std::cin.get(input,49);
//    std::cin.sync();
	FILE *fp;
	//char *ch=input;
	fp=fopen("/sdcard/return Input.xml","w+");
	
	fputs(input,fp);
	fclose(fp);
}
void WriteVideo(){
	clrscr();
	std::cout<<"Enter video link address"<<std::endl;
}
void WriteText(){
	clrscr();
	std::cout<<"Enter Text link address"<<std::endl;
}
void StartInput(){
	char a;
	std::cin>>a;
    if (a=='0'){
    	ReadDownload();
    }else if (a=='1'){
    	ReadVideo();
    }else if (a=='2'){
    	ReadText();
    }else if (a=='3'){
    	WriteVideo();
    }else if (a=='4'){
    	WriteDownload();
    }else if (a=='5'){
    	WriteText();
    }else{	std::cout<<"The input is not/1/2/3/4/5";
    	StartInput();
    }
    
}

int main(){	
	std::cout<<"Welcome to use BaiduYun Link Input System"<<std::endl;
    std::cout<<std::endl;
	std::cout<<"Input 0,Save download address link for CRYENGINE"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Input 1,Save download address link for CRYENGINE's Video"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Input 2,Save download address link for CRYENGINE's Text"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Input 3,more..."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Input 4,more..."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Input 5,more..."<<std::endl;
	std::cout<<std::endl;
	StartInput();
	return 0;
}
