#include <QApplication>
//#include <QColorDialog>
#include <qpushbutton.h>

int main(int argc, char * argv[])
{
	//setFixedSize(1080,1920);
QApplication app(argc, argv);
QPushButton* qbt=new QPushButton("Quit",0);
QPushButton* qbt1=new QPushButton("Quit",0);
//pushbutton->setText("Quit");
//setBaseSize(600,800);
qbt->setGeometry(0,0,100,50);
qbt1->setGeometry(0,0,10,5);
qbt->show();
qbt1->show();
//QColorDialog dialog;
//dialog.show();
return app.exec();
}