#include "QtTestNet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtTestNet w;
	w.show();
	return a.exec();
}
