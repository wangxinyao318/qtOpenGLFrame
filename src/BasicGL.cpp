#include "BasicGL.h"
#include "ColorUlity.h "
#include <math.h>

#define PI 3.14

namespace BasicGL
{
	inline void drawQuad(float x, float y, float w, float h)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0);
		glVertex2f(0, h);
		glVertex2f(w, h);
		glVertex2f(w, 0);
		glEnd();
	}

	inline void drawFilledQuad(float x, float y, float w, float h)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x - w / 2, y - h / 2);
		glVertex2f(x - w / 2, y + h / 2);
		glVertex2f(x + w / 2, y + h / 2);
		glVertex2f(x + w / 2, y - h / 2);
		glEnd();
	}

	void drawSingleArrows(float wx, float wy, float len, float agl)
	{
		GLfloat arrow = 5, x = 0, y = 0;
		glPushMatrix();
		glTranslatef(wx, wy, 0);
		glRotated(agl, 0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(x - len / 2, y);
		glVertex2f(x + len / 2, y);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(x + len / 2, y - arrow);
		glVertex2f(x + len / 2, y + arrow);
		glVertex2f(x + len / 2 + arrow, y);
		glEnd();
		glPopMatrix();
	}

	void drawQuadButton(float x, float y, float w, float h)
	{
		ColorBlack();
		drawFilledQuad(x, y, w, h);
		ColorWhite();
		drawQuad(x, y, w, h);
	}

	void  drawLine(float x, float y, float len, float agl)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2f(x, y);
		glVertex2f(x + len * cosf(agl / 180 * PI), y + len*sinf(agl / 180 * PI));
		glEnd();
	}

	void drawCircle(float x, float y, float r, int n)
	{
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < n; ++i)
			glVertex2f(x + r * cos(2 * PI / n*i), y + r * sin(2 * PI / n*i));
		glEnd();
	}

	void drawArrows(float wx, float wy, float linelen, float triglen, GLfloat agl)
	{
		GLfloat x = 0, y = 0;
		glPushMatrix();
		glRotatef(agl, 0, 0, 1);
		glTranslatef(wx, wy, 0);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(x + linelen, y);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x + linelen, y + triglen / 2);
		glVertex2f(x + linelen, y - triglen / 2);
		glVertex2f(x + linelen + triglen, y);
		glEnd();
		glPopMatrix();
	}

	void drawTriangle(float x, float y, float linelen, int ang)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + linelen * cos((ang)* PI / 180), y + linelen * sin(ang* PI / 180));
		glVertex2f(x + linelen * cos((ang + 60)* PI / 180), y + linelen * sin((ang + 60) * PI / 180));
		glEnd();
	}

	void setStencilTest()
	{
		glEnable(GL_STENCIL_TEST);
		glClear(GL_STENCIL_BUFFER_BIT);
		glClearStencil(0);										//设置清空模版缓存的后默认值为0;
		glClear(GL_STENCIL_BUFFER_BIT);			//清空模版缓存;
		glStencilFunc(GL_ALWAYS, 1, 1);      //模版测试总是通过0x1111 1111;
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);   //使得之后经测试的像素点的模版值都为1; 
	}

	void beginStencilTest()
	{
		glStencilFunc(GL_EQUAL, 1, 1);
		glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void endStencilTest()
	{
		glDisable(GL_STENCIL_TEST);
	}
}