#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
//#include <qvbox>

 
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);    
    QWidget*    window = new    QWidget;
    QLabel *label = new QLabel("Hello, world!");    
    //label->setGeometry(0,0,100,50);
    label->resize(1080,1920);
    QPushButton* btn1=new QPushButton();
    a.setMainWidget(&Label);
    label->show();
    return app.exec();
}

//#include <qthelloworld.cpp.moc>