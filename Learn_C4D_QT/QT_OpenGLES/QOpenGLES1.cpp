
#include <QApplication>

#include <QOpenGLWindow>
//#include <qgl.h>
#include <QWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLContext>
//#include <QtOpenGL>
#include <cstdio>
/*#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
*/

QOpenGLFunctions *NewFunc;

typedef struct{
	GLuint programObject;
}UserData;

GLuint LoadShader(const char*shadersrc,GLenum type){
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
		glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&infolen);
		if (infolen>1){
			/*char* infolog=(char*)malloc(sizeof (char)*infolen);
			glGetShaderInfoLog*/
			//Error
		}
		glDeleteShader(shader);
		
		return 0;
	}
	
	return shader;
	
	
}


class NewGLWidget:public QOpenGLWidget,protected QOpenGLFunctions
{
	//Q_OBJECT
	public:
//	NewGLWidget(QWidget* parent=0);
	//~WidgetGL();
	void initializeGL();
	void resizeGL(int width,int height);
	void paintGL();
	void initShaders();
	void initializeVertexBuffer();
	private:
	
};

/*Widget::~WidgetGL(){
	
}*/

void NewGLWidget::initializeVertexBuffer(){
}


void NewGLWidget::initShaders(){
//	setlocale(LC_NUMERIC,"C");
//	setlocale(LC_NUMERIC,"C");
	GLbyte vShaderStr[]=
	"attribute vec4 vPosition; \nvoid main() \n{ \ngl_Position = vPosition; \n} \n"; 
	
	GLbyte fShaderStr[] = "precision mediump float; \nvoid main() \n{ \ngl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); \n} \n"; 
	
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint programObject;
	GLint linked;
	// Load the vertex/fragment shaders
	vertexShader = LoadShader(GL_VERTEX_SHADER, vShaderStr);
	fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fShaderStr);
	// Create the program object
	programObject = glCreateProgram();
	if(programObject == 0)
	return 0;
	glAttachShader(programObject, vertexShader);
	glAttachShader(programObject, fragmentShader);
	// Bind vPosition to attribute 0 
	glBindAttribLocation(programObject, 0, "vPosition");
	// Link the program
	glLinkProgram(programObject);
	 // Check the link status
	 /*glGetProgramiv(programObject, GL_LINK_STATUS, &linked);
	 if(!linked) 
	 {
	 	GLint infoLen = 0;
	 	glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);
	 	if(infoLen > 1)
	 	{
	 		char* infoLog = malloc(sizeof(char) * infoLen);
	 		glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
	 		esLogMessage("Error linking program:\n%s\n", infoLog);
	 		free(infoLog);
	 	}
	 	glDeleteProgram(programObject); 
	 	return FALSE;
	 }
	 // Store the program object
	 */
	 userData->programObject = programObject;
	 glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	 return TRUE;
	
} 




void NewGLWidget::initializeGL(){
	initializeOpenGLFunctions();
	initializeVertexBuffer();
	initShaders();
	
/*	EGLint majorVersion;
    EGLint minorVersion;
    EGLBoolean success = EGL_FALSE;
    EGLDisplay display=eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display != EGL_NO_DISPLAY) {
        success = eglInitialize(display, &majorVersion,&minorVersion);
        }
        if (success != EGL_TRUE)
        {
        	EGLint errno = eglGetError();
        	if (errno != EGL_SUCCESS)
        	{
        		char errmsg[32];
        		sprintf(errmsg,"[EGL]Initializationfailed.Errorcode:0x%04x", errno);
// EGL_BAD_DISPLAYEGLDisplay参数错误
// EGL_NOT_INITIALIZEDEGL不能初始化

        }
    }*/
	
	
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	
	NewFunc=QOpenGLContext::currentContext()->functions();
	
	
	
}


void NewGLWidget::resizeGL(int width,int height){
	glViewport(0,0,width,height);
}


void NewGLWidget::paintGL(){
	
	//ESContext* esContext;
	
	GLfloat vVertices[]={0.0f,0.5f,0.0f,-0.5f,-0.5f,0.0f,0.5f,-0.5f,0.0f};
	
	
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	


	
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,vVertices);
	
//	glEnableVertexAttribArray 
	
	glEnableVertexAttribArray(0);
	
	glDrawArrays(GL_TRIANGLES,0,3);
	
	
	/*glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);*/
	
	
	
	glUseProgram(0);
	//NewFunc->glLoadIdentity();
//	glLoadIdentity();
	//
	/*glLoadIdentity();
	glLoadIdentity();
	
	glTranslatef(-1.5,0.0,6.0);
	
	glBegin(GL_TRIANGLES);//GL_TRIANGLES
	
	glVertex3f(0.0,1.0,0.0);
	
	glVertex3f(1.0,-1.0,0.0);
	
	glVertex3f(3.0,0.0,0.0);
	
	glEnd();*/
}


int main(int argc,char* argv[]){
	QApplication NewOpenGL(argc,argv);
	NewGLWidget NewGL;
	NewGL.resize(1080,1920);
	
	
	NewGL.show();
	return NewOpenGL.exec();
}