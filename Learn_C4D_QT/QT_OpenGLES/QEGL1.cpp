#include <QApplication>

#include <QOpenGLWidget>

#include <QOpenGLFunctions>

#include <QWindow>
//#include <QOpenGLWidget>
//#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLContext>




class EGLWidget:public QOpenGLWidget,
protected QOpenGLFunctions
{
	Q_OBJECT
	public:
	EGLWidget(QWidget*parent=0);
	~EGLWidget();
	
	void initializeGL();
	void resizeGL(int w,int h);
	void paintGL();
	void shadercode();
	//QMatrix4x4
	void drawelem();
	
	
	QMatrix4x4 mModelMatrix;//模型矩阵   
    QMatrix4x4 mViewMatrix; //视图矩阵  
    QMatrix4x4 mProjectionMatrix; //投影矩阵  
    QMatrix4x4 mMVPMatrix; //MVP矩阵
    float angles;
    QOpenGLShaderProgram*m_shaderprogram;
    int vec_handl;
    int col_handl;
    int mvp_handl;
	
	
	private:
	
};

/*EGLWidget::EGLWidget(QWidget *parent):QOpenGLWidget
{
	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	setFormat(format);
	setMouseTracking(false);
}*/






void EGLWidget::resizeGL(int w,int h){
	mProjectionMatrix.setToIdentity();
	mProjectionMatrix.perspective(60.0f, w / float(h), 0.01f, 1000.0f);//投影矩阵
	
}

void EGLWidget::initializeGL(){
	
	initializeOpenGLFunctions();
	shadercode();
	
	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	setFormat(format);
	setMouseTracking(false);
	mMVPMatrix = mProjectionMatrix * mViewMatrix * mModelMatrix;
}


void EGLWidget::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	mModelMatrix.setToIdentity();
//	mModelMatrix.rotate(angles,0.0f,
	mModelMatrix.rotate(angles, 0.0f, 1.0f, 0.0f);
    drawelem();
    EGLWidget::update();//刷新
}


void EGLWidget::shadercode(){
	const GLchar *vshader_source =
        "attribute vec4 posAttr;\n"
        "uniform mat4 matrix;\n"
        "void main() {\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";
    const GLchar *cshader_source =
        "uniform vec4 color;\n"
        "void main(){\n"
        "   gl_FragColor= color;\n"
        "}\n";
    angles=0.0;
    m_shaderprogram=new QOpenGLShaderProgram(this);
    QOpenGLShader vecShader(QOpenGLShader::Vertex);
    vecShader.compileSourceCode(vshader_source);
    QOpenGLShader colShader(QOpenGLShader::Fragment);
    //vec_handl=m_shaderprogram->addShaderFromSourceCode(QOpenGLShader::Vertex,vshader_source);
    //col_handl=m_shaderprogram->addShaderFromSourceCode(QOpenGLShader::Fragment,cshader_source);
    colShader.compileSourceCode(cshader_source);
    m_shaderprogram->addShader(&vecShader);
    m_shaderprogram->addShader(&colShader);
    m_shaderprogram->link();
    vec_handl=m_shaderprogram->attributeLocation("posAttr");
    col_handl=m_shaderprogram->uniformLocation("color");
    mvp_handl=m_shaderprogram->uniformLocation("matrix");
    mViewMatrix.lookAt(QVector3D(0.0f, 0.0f, -3.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.0f, 1.0f, 0.0f));
}

void EGLWidget::drawelem(){
	static GLfloat const triangleVertices[] = {
        1.0f,  0.0f,  0.0f,
        0.0f, 1.0f, 0.0f,
        -1.0f,  0.0f, 0.0f
    };
    QVector4D colors(1.0f, 1.0f, 0.0f, 1.0f) ;
    mMVPMatrix = mProjectionMatrix  * mViewMatrix * mModelMatrix; 
    m_shaderprogram->enableAttributeArray(vec_handl);
    m_shaderprogram->setAttributeArray(vec_handl,triangleVertices,3);
    m_shaderprogram->setUniformValue(mvp_handl,mMVPMatrix);
    m_shaderprogram->setUniformValue("color",colors);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    m_shaderprogram->bind();
    m_shaderprogram->disableAttributeArray(vec_handl);
    m_shaderprogram->disableAttributeArray(col_handl);
}




int main(int argc,char* argv[]){
	QApplication EGLWidgetApp(argc,argv);
	EGLWidget*EGLApp;
	EGLApp->resize(1080,1920);
	
	EGLApp->show();
	
	return EGLWidgetApp.exec();
}