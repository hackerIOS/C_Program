//MotherBoard & Monitor

//MotherBoard.h
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <vector>

using namespace std;
#define SCREEN_4025 0

SDL_Window*win=NULL;
SDL_Renderer*Rend=NULL;
SDL_Surface*Sur=NULL;
TTF_Font*fonts=NULL;

int SCREEN_W,SCREEN_H;


int BIOS_VGA_DISPLAY_W=640;
int BIOS_VGA_DISPLAY_H=480;
int BIOS_VGA_DISPLAY_COLOR=256;

int BIOS_DISPLAY_POINTER_Y=0;
int BIOS_DISPLAY_POINTER_H=16;


struct DISPLAY_DATA1{
	vector<char>DIS_DATA_X;
	vector<char>DIS_DATA_Y;
};
vector<int>BIOS_DISPLAY_DATA;
int BIOS_DISPLAY_NUM=0;



void BIOS_INIT(){
	win=SDL_CreateWindow("VM",0,0,480,800,0);
	Rend=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
	TTF_Init();
	SDL_Texture* BIOS_PIC=NULL;
	Sur=SDL_LoadBMP("/sdcard/VM.bmp");
	
	fonts=TTF_OpenFont("/sdcard/Programming/LearnVirtualMachine/Fonts.ttf",100);
	
	BIOS_PIC=SDL_CreateTextureFromSurface(Rend,Sur);
	
	SDL_FreeSurface(Sur);
	
	SDL_RenderClear(Rend);
	
	
	SDL_GetWindowSize(win,&SCREEN_W,&SCREEN_H);
	SDL_Rect BIOS_PIC_RECT;
	BIOS_PIC_RECT.x=0;
	BIOS_PIC_RECT.y=0;
	BIOS_PIC_RECT.w=SCREEN_W;
	BIOS_PIC_RECT.h=SCREEN_W*9/16;
	SDL_StartTextInput();
	
	//16:9
	SDL_RenderCopy(Rend,BIOS_PIC,NULL,&BIOS_PIC_RECT);
	
	SDL_RenderPresent(Rend);
	SDL_Delay(10000);
	return;
}

void BIOS_MOVE(int x,int y)   //Fantasy
{
	x=x*2;
   printf("%c[%d;%df",0x1B,y,x);
   return;
}


int BIOS_INT(char INT_NUM,int INPUT_CPU_AX,int INPUT_CPU_BX,int INPUT_CPU_CX,int INPUT_CPU_DX){
	int DEAL_CPU_AH=INPUT_CPU_AX/256;
	int DEAL_CPU_AL=INPUT_CPU_AX%256;
	
	int DEAL_CPU_BH=INPUT_CPU_BX/256;
	int DEAL_CPU_BL=INPUT_CPU_BX%256;
	
	int DEAL_CPU_CH=INPUT_CPU_CX/256;
	int DEAL_CPU_CL=INPUT_CPU_CX%256;
	
	int DEAL_CPU_DH=INPUT_CPU_DX/256;
	int DEAL_CPU_DL=INPUT_CPU_DX%256;
	
	
	switch (INT_NUM){
		case 0x10:
		
		if (DEAL_CPU_AH==0x00){
			if (DEAL_CPU_AL==0x00){
				BIOS_VGA_DISPLAY_W=40;
				BIOS_VGA_DISPLAY_H=25;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x01){
				BIOS_VGA_DISPLAY_W=40;
				BIOS_VGA_DISPLAY_H=25;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x02){
				BIOS_VGA_DISPLAY_W=80;
				BIOS_VGA_DISPLAY_H=25;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x03){
				BIOS_VGA_DISPLAY_W=80;
				BIOS_VGA_DISPLAY_H=25;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x04){
				BIOS_VGA_DISPLAY_W=320;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=4;
			}else if (DEAL_CPU_AL==0x05){
				BIOS_VGA_DISPLAY_W=320;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=4;
			}else if (DEAL_CPU_AL==0x06){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=2;
			}else if (DEAL_CPU_AL==0x07){
				BIOS_VGA_DISPLAY_W=80;
				BIOS_VGA_DISPLAY_H=25;
				BIOS_VGA_DISPLAY_COLOR=2;
			}else if (DEAL_CPU_AL==0x08){
				BIOS_VGA_DISPLAY_W=160;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x09){
				BIOS_VGA_DISPLAY_W=320;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x0a){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x0d){
				BIOS_VGA_DISPLAY_W=320;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x0e){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=200;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x0f){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=350;
				BIOS_VGA_DISPLAY_COLOR=2;
			}else if (DEAL_CPU_AL==0x10){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=350;
				BIOS_VGA_DISPLAY_COLOR=4;//16
			}else if (DEAL_CPU_AL==0x11){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=480;
				BIOS_VGA_DISPLAY_COLOR=2;
			}else if (DEAL_CPU_AL==0x12){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=480;
				BIOS_VGA_DISPLAY_COLOR=16;
			}else if (DEAL_CPU_AL==0x13){
				BIOS_VGA_DISPLAY_W=640;
				BIOS_VGA_DISPLAY_H=480;
				BIOS_VGA_DISPLAY_COLOR=256;
			}
			
			
		}else if (DEAL_CPU_AH==0x01){
			BIOS_DISPLAY_POINTER_Y=DEAL_CPU_CH%16;
			BIOS_DISPLAY_POINTER_H=DEAL_CPU_CL%16;
		}else if (DEAL_CPU_AH==0x02){
			
		}else if (DEAL_CPU_AH==0x03){
			
		}else if (DEAL_CPU_AH==0x04){
			
		}else if (DEAL_CPU_AH==0x05){
			
		}else if (DEAL_CPU_AH==0x06){
			
		}else if (DEAL_CPU_AH==0x07){
			
		}else if (DEAL_CPU_AH==0x08){
			
		}else if (DEAL_CPU_AH==0x09){
			
		}else if (DEAL_CPU_AH==0x0a){
			
		}else if (DEAL_CPU_AH==0x0b){
			
		}else if (DEAL_CPU_AH==0x0c){
			
		}else if (DEAL_CPU_AH==0x0d){
			
		}else if (DEAL_CPU_AH==0x0e){
			
		}else if (DEAL_CPU_AH==0x0f){
			
		}else if (DEAL_CPU_AH==0x10){
			
		}else if (DEAL_CPU_AH==0x11){
			
		}else if (DEAL_CPU_AH==0x12){
			
		}else if (DEAL_CPU_AH==0x13){
			
		}else if (DEAL_CPU_AH==0x1a){
			
		}else if (DEAL_CPU_AH==0x1b){
			
		}else if (DEAL_CPU_AH==0x1c){
			
		}
		break;
		case 0x13:
		break;
		case 0x14:
		break;
		case 0x15:
		break;
		case 0x16:
		break;
		case 0x17:
		break;
		case 0x1a:
		break;
		case 0x00:
		break;
		case 0x01:
		break;
		case 0x02:
		break;
		case 0x03:
		break;
		case 0x04:
		break;
		case 0x05:
		break;
		case 0x06:
		break;
		case 0x07:
		break;
		case 0x08:
		break;
		case 0x09:
		break;
		case 0x0b:
		break;
		case 0x0c:
		break;
		case 0x0e:
		break;
		case 0x11:
		break;
		case 0x12:
		break;
		case 0x18:
		break;
		case 0x19:
		break;
		case 0x1b:
		break;
		case 0x1c:
		break;
		case 0x1d:
		break;
		case 0x1e:
		break;
		case 0x1f:
		break;
	}
	return 0;
}


int main(int argc,char* argv[]){
	//DISPLAY_DATA=new int [80][40];
	BIOS_INIT();
	return 0;
}