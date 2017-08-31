//LaunchPad 模拟
//可编程


//基于SDL2
//5x8


#include "SDL2/SDL.h"
//#include "SDL_Plus.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_thread.h"

#include <stdio.h>



int SDLP_WS=480;
int SDLP_HS=800;

int SDLP_TouchT=0;
int touchx=0,touchy=0;

SDL_Renderer *SDLP_REND=NULL;
//SDL_Surface *SDLP_SUR;
SDL_Window* SDLP_WIN=NULL;
SDL_Thread* SDLP_Thread=NULL;
SDL_Event SDLP_Event;


int GetTouch(void *SDLP_Threaddata){
	while (1){
		//SDLP_TouchT=0;
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




int SDLP_Init(){

	SDLP_WIN=SDL_CreateWindow("SDLP_WIN",0,0,480,800,0);
	SDL_GetWindowSize(SDLP_WIN,&SDLP_WS,&SDLP_HS);
	SDLP_REND=SDL_CreateRenderer(SDLP_WIN,-1,SDL_RENDERER_ACCELERATED);
	SDLP_Thread=SDL_CreateThread(GetTouch,NULL,NULL);
}


struct SDLP_ReadColor{
	int Blue=0x0000ff;
	int Red=0xff0000;
	int Green=0x00ff00;
	int White=0xffffff;
	int Black=0x000000;
}SDLP_BaseColor;




int SDLP_ColorBox(int x,int y,int w,int h,SDL_Surface *Sur,int SDLP_ColorBoxCol){
	//int CBR=(SDLP_ColorBoxCol/16)/16;
	
	SDL_Texture *SDLP_TEX=NULL;
	//SDL_FreeSurface(Sur);
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	//SDLP_SUR= SDL_CreateRGBSurface(0, SDLP_WS,SDLP_HS, 32,0,0, 0, 0);	// 先把表面刷白
	//SDL_FillRect(Sur,NULL, SDLP_ColorBoxCol);
	
			SDLP_TEX=SDL_CreateTextureFromSurface(SDLP_REND,Sur);
	SDL_RenderCopy(SDLP_REND,SDLP_TEX,NULL,&rect);
	SDL_DestroyTexture(SDLP_TEX);
		if (x<=touchx){
				if (y<=touchy){
					if (x+w>=touchx){
						if (y+h>=touchy){
							if (SDLP_TouchT==1){
								return 1;
								
							}
							}
						}
					}
				}
	
	return 0;
}

int main(int argc,char* argv[]){
	SDLP_Init();
	int y=0;
	
	
	SDL_Surface* SDLP_SUR,*SDLP_SUR1;
	SDLP_SUR=SDL_CreateRGBSurface(0, SDLP_WS,SDLP_HS, 32,0,0, 0, 0);
		SDL_FillRect(SDLP_SUR,NULL,SDLP_BaseColor.Black);
	SDLP_SUR1=SDL_CreateRGBSurface(0, SDLP_WS,SDLP_HS, 32,0,0, 0, 0);
		SDL_FillRect(SDLP_SUR1,NULL,SDLP_BaseColor.White);
	
	
	
	Mix_Chunk *Chunk=NULL;
	Mix_Chunk *Chunk1=NULL;
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
	//
	Chunk=Mix_LoadWAV("/mnt/sdcard/SDL_Audio_G1.wav");
	Chunk1=Mix_LoadWAV("/mnt/sdcard/SDL_Audio_G2.wav");
	
	//SDL_RenderPresent(SDLP_REND);
	for (;;){
		//y++;
		SDLP_ColorBox(0,0,SDLP_WS,SDLP_HS,SDLP_SUR,0);
		
		if (SDLP_ColorBox(10,10,SDLP_WS/5-20,SDLP_HS/5-20,SDLP_SUR1,SDLP_BaseColor.White)){
			Mix_PlayChannel(1,Chunk,0);
			SDLP_TouchT=0;
		}
		
		
		//Mix_PlayChannel(-1,Chunk1,0);
		//SDL_Delay(500);
		
		//Mix_PlayChannel(-1,Chunk,0);
		if (SDLP_ColorBox(SDLP_WS/5+20,10,SDLP_WS/5-20,SDLP_HS/5-20,SDLP_SUR1,SDLP_BaseColor.White)){
			Mix_PlayChannel(1,Chunk1,0);
			SDLP_TouchT=0;
		}
		//SDL_Delay(500);
		SDL_RenderPresent(SDLP_REND);
	}
}