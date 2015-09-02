#pragma once
#include <windows.h>
#include <gl/GL.h>

namespace BasicGL
{
	inline void drawQuad(float x, float y, float w, float h);
	inline void drawFilledQuad(float x, float y, float w, float h);
	void drawSingleArrows(float wx, float wy, float len, float agl);
	void drawQuadButton(float x, float y, float w, float h);
	void drawLine(float x, float y, float len, float agl = 0);
	void drawCircle(float x, float y, float r, int n);
	void drawArrows(float x, float y, float linelen, float triglen, GLfloat agl);
	void drawTriangle(float x, float y, float linelen, int ang);
	void setStencilTest();
	void beginStencilTest();
	void endStencilTest();
};
