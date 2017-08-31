#include <SDL2/SDL_opengles2.h>
//#include <SDL2/SDL_esUtil.h>
#include <SDL2/SDL.h>

typedef struct 
{
	GLuint programObject;
}UserData;



GLuint LoadShader(const char* shadersrc,GLenum type){
	GLuint shader;
	GLint compiled;
	shader=glCreateShader(type);
	if (shader==0){
		return 0;
	}
	
	glShaderSource(shader,1,&shadersrc,NULL);
	
	glCompileShader(shader);
	glGetShaderiv(shader,GL_COMPILE_STATUS,&compiled);
	
	if (!compiled){
		GLint infolen=0;
		//glGetShaderiv(shader,GL_INFO_LOG_LENGH,&infolen);
		if (infolen>1){
			//char* infolog=(char*)malloc(sizeof (char)*infolen);
			}
		
		
		}
	return shader;
}

int Init(SDL_GLContext *esContext){
	//UserData *userData=(UserData*)esContext->userData;
	
	GLbyte vShaderStr[] =
"attribute vec4 vPosition;void main(){gl_Position = vPosition;}\n\n\n\n\n";
GLbyte fShaderStr[] =
"precision mediump float;void main(){gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); \n" "} \n";
GLuint vertexShader;
GLuint fragmentShader;
GLuint programObject;
GLint linked;


vertexShader =LoadShader(GL_VERTEX_SHADER, vShaderStr);
fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fShaderStr);
// Create the program object 
programObject = glCreateProgram();
if(programObject == 0)
return 0;
glAttachShader(programObject, vertexShader); glAttachShader(programObject, fragmentShader);
// Bind vPosition to attribute 0 
glBindAttribLocation(programObject, 0, "vPosition");
// Link the program 
glLinkProgram(programObject);
// Check the link status
glGetProgramiv(programObject, GL_LINK_STATUS, &linked);
   if(!linked)
   {
/*GLint infoLen = 0;
glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);
      if(infoLen > 1)
      {
char* infoLog = malloc(sizeof(char) * infoLen);
glGetProgramInfoLog(programObject, infoLen, NULL, infoLog); esLogMessage("Error linking program:\n%s\n", infoLog);
free(infoLog); }
glDeleteProgram(programObject);
      return FALSE;
   }*/
// Store the program object 
userData->programObject = programObject;
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   return TRUE;
}
}


int main(int argc,char* argv[]) {
	SDL_GLContext eglContext;
	//SDL_GLDisplayMode eglDisplay;
    GLint a;
    return 0;
}