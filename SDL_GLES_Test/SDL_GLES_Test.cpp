#include <SDL2/SDL.h>
#include "SDL_opengles.h"
SDL_Window*window=NULL;
SDL_Renderer*renderer=NULL;
//三维点坐标
typedef struct
{
GLfloat x;
GLfloat y;
GLfloat z;	
	} Vertex3D;
//创造一个点
Vertex3D Vertex3DMake(GLfloat x,GLfloat y,GLfloat z)
{
return {x,y,z};	
	}
//计算两点的距离
GLfloat Vertex3DCalculateDistanceBetweenVertices(Vertex3D first,Vertex3D second)
{
GLfloat deltaX=second.x-first.x;
GLfloat deltaY=second.y-first.y;
GLfloat deltaZ=second.z-first.z;
return sqrt(deltaX*deltaX+deltaY*deltaY+deltaZ*deltaZ);
	}
//由三个点组合一个三角形
typedef struct
{
Vertex3D v1;
Vertex3D v2;
Vertex3D v3;
	} Triangle3D;
//创造一个三角形
Triangle3D Triangle3DMake(Vertex3D first,Vertex3D second,Vertex3D third)
{
return {first,second,third};	
	}
int main()
{
SDL_Init (SDL_INIT_EVERYTHING ); 
window=SDL_CreateWindow( "SDL",0,0,960,540,SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE); 
//renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
SDL_GLContext glcontext=SDL_GL_CreateContext(window);//opengl上下文

//SDL_GL_SetAttribute(SDL_GL_RED_SIZE,5);
//SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,5);
//SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,5);
//SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_ES);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);

Vertex3D vertex1=Vertex3DMake(100,0,-100);
Vertex3D vertex2=Vertex3DMake(0,0,-100);
Vertex3D vertex3=Vertex3DMake(0,100,-100);
Triangle3D triangle=Triangle3DMake(vertex3,vertex2,vertex1);
glMatrixMode(GL_PROJECTION);//投影模式
glLoadIdentity();//投影模式加载成单位矩阵
//glOrthof(0.0,720.0,1280.0,0.0,1.0,-1.0);//将投影模式切只有为正投影
//glMatrixMode(GL_MODELVIEW);//初始化模型视图(modelview)矩阵
//glLoadIdentity();

glClearColor(1,1,1,1);//设置surface的清除颜色，也就是渲染到屏幕上的背景色。
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  //清除surface内容，恢复至初始状态。
glEnableClientState(GL_VERTEX_ARRAY);
glColor4f(0.0,0.0,0.0,1.0);
glVertexPointer(3,GL_FLOAT,0,&triangle);
glDrawArrays(GL_TRIANGLES,0,9);
glDisableClientState(GL_VERTEX_ARRAY);

//SDL_RenderPresent(renderer);
SDL_GL_SwapWindow(window);


SDL_Delay(3000);
if (glcontext!=NULL)
SDL_GL_DeleteContext(glcontext);
if (renderer!=NULL)
SDL_DestroyRenderer(renderer);
if (window!=NULL)
SDL_DestroyWindow(window);
SDL_Quit();
}