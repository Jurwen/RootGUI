#include "mainPage.h"

//#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    QApplication a(argc, argv);
    mainPage w;
    w.show();
    return a.exec();
}

