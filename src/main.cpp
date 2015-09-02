#include <QDesktopWidget>
#include <QApplication>
#include <QSurfaceFormat>
#include "OpenGLWindowBase.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	OpenGLWindowBase W(QRect(700,200,500,500));
	W.show();

    return app.exec();
}
