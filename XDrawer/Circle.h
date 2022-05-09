#pragma once
#include "afx.h"
class Circle :
	public CObject
{
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
public:
	Circle(void);
	Circle(int x1, int y1);
	Circle(int x1, int y1, int x2, int y2);
	void draw(CDC* pDC);
	void setXY2(int x, int y);
	~Circle(void);
};

