#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include  <QLabel>


#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

int main(int argc,char **argv)
{
	QApplication app(argc,argv);
	QLabel *info=new QLabel();
	QLineEdit *LE=new QLineEdit();
	QPushButton *button =new QPushButton();
	info->setText("ss");
	
	LE->clear();
	button->setText("gg");
	
	//button->resize(200,50);
	QHBoxLayout *g=new QHBoxLayout();
	g->addWidget(info);
	g->addWidget(LE);
	QVBoxLayout  *q=new QVBoxLayout();
	q->addWidget(button);
	q->addLayout(g);
	
	QWidget *w=new QWidget();
	
	w->setLayout(q);
	w->setWindowTitle("gg");
	w->show();
	
	
	
	
	
	return app.exec();
	
}