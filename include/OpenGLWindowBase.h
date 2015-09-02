#ifndef OpenGLWindowBase_H
#define OpenGLWindowBase_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QWidget>
#include <QVector2D>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QDesktopWidget>
#include <QPainter>
#include <QPushButton>
#include "gl/glut.h"

#define POINT_WIDTH 2
#define LINE_WIDTH 2

class OpenGLWindowBase : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

public:
	explicit OpenGLWindowBase(QRect rect, QWidget *parent = 0);
	virtual ~OpenGLWindowBase();
protected:
	//virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
	virtual void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
	virtual void timerEvent(QTimerEvent *e) Q_DECL_OVERRIDE;
	//virtual void mouseDoubleClickEvent(QMouseEvent *);
	virtual void keyPressEvent(QKeyEvent *e);

	virtual void initializeGL() Q_DECL_OVERRIDE;
	virtual void resizeGL(int w, int h) Q_DECL_OVERRIDE;
	virtual void paintGL() Q_DECL_OVERRIDE;

protected:
	QRect	mRectWindows;

	QVector2D mousePressPosition;
	QVector2D mousePressGlobalPosition;
    QVector3D rotationAxis;

	bool fullScreen;
};

#endif // OpenGLWindow_H
