#include "OpenGLWindowBase.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <math.h>
#include "ColorUlity.h"

OpenGLWindowBase::OpenGLWindowBase(QRect rect, QWidget *parent) :
QOpenGLWidget(parent), mRectWindows(rect)
{
	fullScreen = false;
}

OpenGLWindowBase::~OpenGLWindowBase()
{
	// Make sure the context is current when deleting the texture
	// and the buffers.
	makeCurrent();
	doneCurrent();
}
//! [0]

//! [1]
void OpenGLWindowBase::timerEvent(QTimerEvent *)
{
}
//! [1]

void OpenGLWindowBase::initializeGL()
{
	initializeOpenGLFunctions();

	setGeometry(mRectWindows);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(5.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glDepthMask(GL_TRUE);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA4, mRectWindows.width(), mRectWindows.height());

	glPointSize(POINT_WIDTH);
	glLineWidth(LINE_WIDTH);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // Make round points, not square points  
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);  // Antialias the lines  
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}


//! [5]
void OpenGLWindowBase::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, 1, 8);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	
}
//! [5]

void OpenGLWindowBase::paintGL()
{
	QPainter painter(this);
	
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer

	glLoadIdentity();									// Reset The Current Modelview Matrix
	
	glMatrixMode(GL_MODELVIEW);	 
	glLoadIdentity();
	
	gluLookAt(0, 0, 2, 0, 0, 0, 0, 1, 0);

	//begin to render GUI
	//mPopRender.draw(&painter);

	painter.beginNativePainting();
	ColorGreen();
	glTranslatef(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 60);
	glVertex2f(10, 60);
	glVertex2f(10, 0);
	glEnd();
	painter.endNativePainting();
}

void OpenGLWindowBase::keyPressEvent(QKeyEvent *e)
{
 		switch (e->key())
 		{
 			//F1键为全屏和普通屏显示切换键
		case Qt::Key_F1:
			fullScreen = !fullScreen;
			if (fullScreen)
			{
				showFullScreen();
			}
			else
			{
				setWindowState(Qt::WindowActive);
				showNormal();
			}
			update();
 			break;
 			//Ese为退出程序键
 		case Qt::Key_Escape:
 			close();
 		}
}


//! [0]
void OpenGLWindowBase::mousePressEvent(QMouseEvent *e)
{	

}

void OpenGLWindowBase::mouseReleaseEvent(QMouseEvent *e)
{

}
