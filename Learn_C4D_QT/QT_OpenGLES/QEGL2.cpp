#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
//#include <QOpenGLContext>


class EGL:public QOpenGLWidget,protected QOpenGLFunctions
{
	public:
	    QMatrix4x4 Matrix_Model;
	    QMatrix4x4 Matrix_View;
	    QMatrix4x4 Matrix_Projection;//投影
	    QMatrix4x4 Matrix_MVP;//MVP
	    QOpenGLShaderProgram*Shader_Program;
	    GLint Handle_Vec;
	    GLint Handle_Color;
	    GLint Handle_MVP;
	    GLfloat angles;
	    
	    
	    void initializeGL();
	    void resizeGL(int w,int h);
	    void paintGL();
	    void Shader_Code();
	    void DrawEle();
	    void NewDraw();
	    
	    
	private:
	    
	
};

void EGL::initializeGL(){
	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	setFormat(format);
	setMouseTracking(false);
	Matrix_MVP=Matrix_Projection*Matrix_View*Matrix_Model;
	
	initializeOpenGLFunctions();
	Shader_Code();
	
}

void EGL::resizeGL(int w,int h){
	Matrix_Projection.setToIdentity();
	Matrix_Projection.perspective(60.0f,w/float (h),0x01f,1000.0f);
	
}

void EGL::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	Matrix_Model.setToIdentity();
	Matrix_Model.rotate(angles,0.0f,1.0f,0.0f);
	DrawEle();
	
	EGL::update();
}


void EGL::Shader_Code(){
	const GLchar*Shader_VSRC=
	    "attribute vec4 posAttr;\n"
        "uniform mat4 matrix;\n"
        "void main() {\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";
    const GLchar*Shader_CSRC=
        "uniform vec4 color;\n"
        "void main(){\n"
        "   gl_FragColor= color;\n"
        "}\n";
        
    angles=0.0f;
    Shader_Program=new QOpenGLShaderProgram(this);
    QOpenGLShader Shader_Vec(QOpenGLShader::Vertex);
    
    Shader_Vec.compileSourceCode(Shader_VSRC);
    QOpenGLShader Shader_Color(QOpenGLShader::Fragment);
    
    Shader_Color.compileSourceCode(Shader_CSRC);
    
    Shader_Program->addShader(&Shader_Vec);
    
    Shader_Program->addShader(&Shader_Color);
    
    Shader_Program->link();
    
    Handle_Vec=Shader_Program->attributeLocation("posAttr");
    
    Handle_Color=Shader_Program->uniformLocation("color");
    Handle_MVP=Shader_Program->uniformLocation("matrix");
    
    Matrix_View.lookAt(QVector3D(0.0f,0.0f,-3.0f),QVector3D(0.0f,0.0f,1.0f),QVector3D(0.0f,1.0f,0.0f));
    
	
	
	
	
}

void EGL::DrawEle()
{
	Shader_Program->bind();
	QVector4D VColor(1.0f,1.0f,0.0f,1.0f);
	static GLfloat const TAngleV[]={
		1.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,
		-1.0f,0.0f,0.0f
	};
	Matrix_MVP=Matrix_Projection*Matrix_View*Matrix_Model;
	Shader_Program->enableAttributeArray(Handle_Vec);
	
	Shader_Program->setAttributeArray(Handle_Vec,TAngleV,3);
	
	Shader_Program->setUniformValue("color",VColor);
	
	glDrawArrays(GL_TRIANGLES,0,3);
	
	Shader_Program->disableAttributeArray(Handle_Vec);
	Shader_Program->disableAttributeArray(Handle_Color);
	
}


void EGL::NewDraw(){
	const qreal retinaScale = devicePixelRatio();
    // 设置世界坐标系原点在屏幕的中央
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);
    
    glClear(GL_COLOR_BUFFER_BIT);
    Shader_Program->bind();
    QMatrix4x4 matrix;
    
    matrix.setToIdentity();
    // 移动后水平-5000.0f缩放后为世界坐标的-1.0f, 水平5000.0f变为1.0f
    matrix.scale(1/5000.0f, 1.0/2.0f, 0.0f);
    
    // 移动后水平0.0f变为-5000.0f, 水平10000.0f变为5000.0f
    matrix.translate(-5000.0f,1.0f, 0.0f);
    
    Shader_Program->setUniformValue("color", matrix);
    
    GLfloat  vertices[] = {
    	0.0f, -1.0f, 0.0f, 
    	0.0f, 1.0f, 0.0f,
        10000.0f, -1.0f,0.0f
    };
    
                          
    if(nBegin > 5.0f)
    {
        nBegin = -5.0f;
    }
    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };
    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
    Shader_Program->release();
}


int main (int argc,char* argv[]){
	QApplication EGLWidget(argc,argv);
	
	EGL EGLWid;
	EGLWid.resize(1080,1920);
	EGLWid.show();
	return EGLWidget.exec();
}


