//new LaunchPad
//高优化
//高效率

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_thread.h"
#include "SDL2/SDL_image.h"
//***********SDL*************


#include <stdio.h>
//**********标准库***********



SDL_Window *NLP_Win=NULL;
SDL_Renderer* NLP_Ren=NULL;
SDL_Thread* NLP_Thr=NULL;
SDL_Event NLP_Event;

int ScreenX=0;
int ScreenY=0;

int TouchX,TouchY;
int TouchEvent=0;

struct NLP_ReadColor{
	int Blue=0x0000ff;
	int Red=0xff0000;
	int Green=0x00ff00;
	int White=0xffffff;
	int Black=0x000000;
}NLP_BaseColor;

struct BtnSurface{
	SDL_Surface *NLP_SUR=NULL;
	int Color;
	SDL_Rect rect;
	int Num;
}BtnSurface[4][7];


Mix_Chunk *Chunk=NULL;
Mix_Chunk *Chunk1=NULL;

//*********全局定义**********




int NLP_Init(){
		NLP_Win=SDL_CreateWindow("SDLP_WIN",0,0,480,800,0);
	SDL_GetWindowSize(NLP_Win,&ScreenX,&ScreenY);
	NLP_Ren=SDL_CreateRenderer(NLP_Win,-1,SDL_RENDERER_ACCELERATED);
	
	
	
	
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
	
	Chunk=Mix_LoadWAV("/mnt/sdcard/SDL_Audio_G1.wav");
	Chunk1=Mix_LoadWAV("/mnt/sdcard/SDL_Audio_G2.wav");
	
	
}
//**********预加载***********

int LoadInitUI(){
	
	SDL_Surface* SUR=NULL;
	SDL_Texture* Tex=NULL;
	/*SUR=SDL_CreateRGBSurface(0, ScreenX,ScreenY, 32,0,0, 0, 0);
	SDL_FillRect(SUR,NULL,Color);
	*/
	SUR=IMG_Load("/mnt/sdcard/Load3.jpg");
	Tex=SDL_CreateTextureFromSurface(NLP_Ren,SUR);
	SDL_FreeSurface(SUR);
	SDL_RenderCopy(NLP_Ren,Tex,NULL,NULL);
	SDL_DestroyTexture(Tex);
	SDL_RenderPresent(NLP_Ren);
	SDL_Delay(1000);
}


int LoadBtn(){
	int Loop1=0,Loop2=0;
	SDL_Surface* SUR=NULL;
	SDL_Texture* Tex=NULL;
	SUR=SDL_CreateRGBSurface(0, ScreenX,ScreenY, 32,0,0, 0, 0);
	SDL_FillRect(SUR,NULL,NLP_BaseColor.Black);
	Tex=SDL_CreateTextureFromSurface(NLP_Ren,SUR);
	SDL_FreeSurface(SUR);
	SDL_RenderCopy(NLP_Ren,Tex,NULL,NULL);
	
	for (;Loop1!=8;){
		for (;Loop2!=5;){
			SDL_Texture* Tex1=NULL;
			//SDL_Rect rect;
			BtnSurface[Loop2][Loop1].rect.x=Loop2*ScreenX/5+5;
			BtnSurface[Loop2][Loop1].rect.y=Loop1*ScreenY/8+5;
			BtnSurface[Loop2][Loop1].rect.w=ScreenX/5-50;
			BtnSurface[Loop2][Loop1].rect.h=ScreenY/8-50;
			
			
			BtnSurface[Loop2][Loop1].NLP_SUR=SDL_CreateRGBSurface(0, ScreenX,ScreenY, 32,0,0, 0, 0);
			SDL_FillRect(BtnSurface[Loop2][Loop1].NLP_SUR,NULL,NLP_BaseColor.White);
			Tex1=SDL_CreateTextureFromSurface(NLP_Ren,SUR);
			SDL_RenderCopy(NLP_Ren,Tex1,NULL,&BtnSurface[Loop2][Loop1].rect);
			Loop2++;
	
		}
		Loop2=0;
		Loop1++;
	}
	SDL_RenderPresent(NLP_Ren);
	//SDL_Delay(5000);
}

int LoopFun(){
	
	for (;;){
		//111
		int Loop1=0,Loop2=0;
		for (;Loop1!=8;){
			for (;Loop2!=5;){
				if (BtnSurface[Loop2][Loop1].rect.x<=TouchX){
					if (BtnSurface[Loop2][Loop1].rect.y<=TouchY){
						if (BtnSurface[Loop2][Loop1].rect.x+BtnSurface[Loop2][Loop1].rect.w>=TouchX){
							if (BtnSurface[Loop2][Loop1].rect.y+BtnSurface[Loop2][Loop1].rect.h>=TouchY){
								if(TouchEvent==1){
								Mix_PlayChannel(1,Chunk1,0);
								TouchEvent=0;
								}
							}
						}
					}
				}
				
			}
		Loop2=0;
		Loop1++;
		}
	}
}


int GetTouch(void *SDLP_Threaddata){
	while (1){
		
		//SDLP_TouchT=0;
		while (SDL_PollEvent(&NLP_Event))
		{
			TouchX=NLP_Event.tfinger.x*ScreenX;
			TouchY=NLP_Event.tfinger.y*ScreenY;
			if (NLP_Event.type==SDL_FINGERUP){
				TouchEvent=1;
				}
				if (NLP_Event.type==SDL_FINGERDOWN || NLP_Event.type==SDL_FINGERMOTION){
				TouchEvent=2;
				}
			}
			
	}
}
//************触控**************


int main(int argc,char* argv[]){
	NLP_Init();
	LoadInitUI();
	LoadBtn();
	NLP_Thr=SDL_CreateThread(GetTouch,NULL,NULL);
	
	LoopFun();
	
	
}