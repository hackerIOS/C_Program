#ifndef _SDL_PLUS_H
#define _SDL_PLUS_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_thread.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <string.h>

//#define LoopTo

using namespace std;
int SDLP_WS=480;
int SDLP_HS=800;

SDL_Renderer *SDLP_REND=NULL;

SDL_Surface *SDLP_SUR=NULL;
SDL_Window* SDLP_WIN=NULL;
SDL_Thread* SDLP_Thread=NULL;
TTF_Font *SDLP_Font=NULL;
int LoopOutNum=0;
int SDLP_TouchT=0;
int touchx=0,touchy=0;
SDL_Event SDLP_Event;
int SDLP_BackGroundColor=0xffffff;

int y2=0;
int pd=0;

//SDL_Surface **SDLP_MemSur=NULL;

//int SDLP_MemLong=0;

//char** SDLP_IMGPath;

//目录*****************

//各种小部分
//颜色


//系统部分
//音效部分(OpenSles)
//网络部分
//控件部分
//安全部分


//测试部分

//***********************


struct SDLP_ReadColor{
	int Blue=0x0000ff;
	int Red=0xff0000;
	int Green=0x00ff00;
	int White=0xffffff;
	int Black=0x000000;
}SDLP_BaseColor;




//循环头



int SDLP_LoopBack(){
	SDL_RenderPresent(SDLP_REND);
}

int SDLP_LoopStart(){
	/*SDL_Texture *SDLP_TEX=NULL;
	SDL_FreeSurface(SDLP_SUR);
	SDL_Rect rect;
	rect.x=0;
	rect.y=0;
	rect.w=SDLP_WS;
	rect.h=SDLP_HS;
	SDLP_SUR= SDL_CreateRGBSurface(0, SDLP_WS,SDLP_HS, 32, 0,0, 0, 0);	// 先把表面刷白
	SDL_FillRect(SDLP_SUR,&rect, SDLP_BackGroundColor);
	
			SDLP_TEX=SDL_CreateTextureFromSurface(SDLP_REND,SDLP_SUR);
	SDL_RenderCopy(SDLP_REND,SDLP_TEX,NULL,&rect);
	SDL_DestroyTexture(SDLP_TEX);*/
}

//循环尾

int GetTouch(void *SDLP_Threaddata){
	while (1){
		while (SDL_PollEvent(&SDLP_Event))
		{
			touchx=SDLP_Event.tfinger.x*SDLP_WS;
			touchy=SDLP_Event.tfinger.y*SDLP_HS;
			if (SDLP_Event.type==SDL_FINGERUP){
				SDLP_TouchT=1;
			}
			if (SDLP_Event.type==SDL_FINGERDOWN || SDLP_Event.type==SDL_FINGERMOTION){
				SDLP_TouchT=2;
		}
		
	}
}
}



//预加载
int SDLP_Init(int SDLP_BGC){
	//SDLP_MemSur=(SDL_Surface**)malloc(sizeof(SDL_Surface)*1);
	//SDLP_IMGPath=(char**)malloc(1000);
	//SDLP_IMGPath[0]=(char*)malloc(sizeof (*SDLP_IMGPath));
	
	
	TTF_Init();
	SDLP_WIN=SDL_CreateWindow("SDLP_WIN",0,0,480,800,0);
	SDL_GetWindowSize(SDLP_WIN,&SDLP_WS,&SDLP_HS);
	//if (SDLP_BGC!=NULL){
		SDLP_BackGroundColor=SDLP_BGC;
	
	

		//SDLP_Font=TTF_OpenFont(SDLP_FontPath,200);
	
	SDLP_REND=SDL_CreateRenderer(SDLP_WIN,-1,SDL_RENDERER_ACCELERATED);
	//SDL_Init(SDL_INIT_EVERYTHING);
	SDLP_Thread=SDL_CreateThread(GetTouch,NULL,NULL);
}

int SDLP_EXIT(){
	SDL_FreeSurface(SDLP_SUR);
	//SDL_DestroyTexture(Tex);
	SDL_DestroyRenderer(SDLP_REND);
	
	SDL_DestroyWindow(SDLP_WIN);
	
	SDL_Quit();
	
	//return 0;
}

char* TextButton(
SDL_Rect rect,
SDL_Color color,
int fontsize,
int fontxj){
	SDL_FreeSurface(SDLP_SUR);
	
	
}

int SDLP_PictureBox(int x,int y,int w,int h,char* SDLP_PBPath){
	//if (
	SDL_Texture *SDLP_TEX=NULL;
	SDL_FreeSurface(SDLP_SUR);
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	SDLP_SUR=IMG_Load(SDLP_PBPath);

	
	SDLP_TEX=SDL_CreateTextureFromSurface(SDLP_REND,SDLP_SUR);
	SDL_RenderCopy(SDLP_REND,SDLP_TEX,NULL,&rect);
	SDL_DestroyTexture(SDLP_TEX);
	
}




int SDLP_ColorBox(int x,int y,int w,int h,int SDLP_ColorBoxCol){
	int CBR=(SDLP_ColorBoxCol/16)/16;
	
	SDL_Texture *SDLP_TEX=NULL;
	SDL_FreeSurface(SDLP_SUR);
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	SDLP_SUR= SDL_CreateRGBSurface(0, SDLP_WS,SDLP_HS, 32,0,0, 0, 0);	// 先把表面刷白
	SDL_FillRect(SDLP_SUR,NULL, SDLP_ColorBoxCol);

			SDLP_TEX=SDL_CreateTextureFromSurface(SDLP_REND,SDLP_SUR);
	SDL_RenderCopy(SDLP_REND,SDLP_TEX,NULL,&rect);
	SDL_DestroyTexture(SDLP_TEX);
		if (x<=touchx){
				if (y<=touchy){
					if (x+w>=touchx){
						if (y+h>=touchy){
							if (SDLP_TouchT==2){
								return 1;
								
							}
						}
					}
				}
	}
	return 0;
	
}




//普通文本按钮


int SDLP_SampleTextButton(
int x,int y,int w,int h,
char* Text){
	SDL_Texture *SDLP_TEX=NULL;
	
	
	SDL_Color SDLP_COL;
	SDL_Color SDLP_COL1;
	SDLP_COL1={0,0,100};
	SDLP_COL={0,0,200};
	
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	SDL_FreeSurface(SDLP_SUR);

		
			if (x<=touchx){
				if (y<=touchy){
					if (x+w>=touchx){
						if (y+h>=touchy){
				if (SDLP_TouchT==1){
					SDLP_SUR=TTF_RenderUTF8_Blended(SDLP_Font,Text,SDLP_COL);

			SDLP_TEX=SDL_CreateTextureFromSurface(SDLP_REND,SDLP_SUR);
	SDL_RenderCopy(SDLP_REND,SDLP_TEX,NULL,&rect);
	SDLP_TouchT=0;
	SDL_DestroyTexture(SDLP_TEX);
					return 1;
				}
				if (SDLP_TouchT==2){	SDLP_SUR=TTF_RenderUTF8_Blended(SDLP_Font,Text,SDLP_COL1);
					SDLP_TEX=SDL_CreateTextureFromSurface(SDLP_REND,SDLP_SUR);
	SDL_RenderCopy(SDLP_REND,SDLP_TEX,NULL,&rect);
	
	SDL_DestroyTexture(SDLP_TEX);
	return 0;
					
				}
	}
					}
					}
					}
					if (SDLP_TouchT==1){
						SDLP_TouchT=0;
						}
		SDLP_SUR=TTF_RenderUTF8_Blended(SDLP_Font,Text,SDLP_COL);
		SDLP_TEX=SDL_CreateTextureFromSurface(SDLP_REND,SDLP_SUR);
	SDL_RenderCopy(SDLP_REND,SDLP_TEX,NULL,&rect);
	SDL_DestroyTexture(SDLP_TEX);
		return 0;
		
	}
//End*************



//系统字体检测
/*char* SearchSystemFont(){
	
	char *pathdata="/system/fonts/";
	DIR *dir;
	struct dirent *ptr;
	dir=opendir(pathdata);
	int filenum=0;
	while ((ptr=readdir(dir))!=NULL){
		filenum++;
	}
	char* data[filenum];
	int CC=0;
	dir=opendir(pathdata);
	while (CC<filenum && (ptr=readdir(dir))!=NULL){
		data[CC]=ptr->d_name;
				if (strstr(data[CC],"DroidSansFallback")){
			//printf("success");
			char outdata[200]="";
			sprintf(outdata,"%s%s",pathdata,data[CC]);
			
			
			
			return outdata;
		}
		CC++;
	}
	return "/system/fonts/DroidSans.ttf";
}
*/



/*
int main(int argc,char* argv[]){
	
	SDLP_Init("/system/fonts/DroidSansMono.ttf",SDLP_BaseColor.black);
	
	char* Text="TextButton";

	for (;;){
		SDLP_LoopStart();
		/*if (pd==0){
			y2=y2+10;
			if (y2==2000){
				pd=1;
			}
		}else if (pd==1){
			y2=y2-10;
		}
		y2++;
		SDLP_ColorBox(0,0,500,300,SDLP_BaseColor.Red);
		

		
		
		
				SDLP_SampleTextButton(200,400,400,150,Text);
		
	SDLP_PictureBox(0,0,SDLP_WS,SDLP_WS,"/mnt/sdcard/SDLP_PBIMG.jpg");
			if (SDLP_SampleTextButton(0,y2,300,150,"<Back")){
			SDLP_EXIT();
		}
	
		SDLP_LoopBack();
		
	}
	return 0;
}

*/
#endif