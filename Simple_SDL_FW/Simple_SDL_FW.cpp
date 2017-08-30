//A Simple SDL Example

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_thread.h>

SDL_Window*win=NULL;
SDL_Renderer*Rend=NULL;
SDL_Surface*Sur=NULL;

int SCREEN_W,SCREEN_H;

int main (int argc,char*argv[]){
	win=SDL_CreateWindow("SC",0,0,480,800,0);
	Rend=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
	TTF_Init();
	SDL_Thread *IPThread;
	SDL_GetWindowSize(win,&SCREEN_W,&SCREEN_H);
	
	SDL_Delay(1000);
	
	SDL_Quit();
	return 0;
}