#pragma once
#include "afx.h"
class Line :
	public CObject
{
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
public:
	Line(void);
	Line(int x1, int y1);
	Line(int x1, int y1, int x2, int y2);
	void draw(CDC* pDC);
	void setXY2(int x, int y);
	~Line(void);
};

