//#include <iostream>
#include "SDL_Plus.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <string.h>
//using namespace std;
int main(int argc,char* argv[]){
	SDLP_Init("/system/fonts/DroidSansFallback-flyme.ttf");
	
	char* Text="BROKEN";
	for (;;){
		
		if (SDLP_SampleTextButton(0,0,300,150,Text)){
			SDLP_EXIT();
		}
		SDLP_SampleTextButton(200,400,300,150,Text);
		SDL_RenderPresent(SDLP_REND);
	}
	return 0;
}