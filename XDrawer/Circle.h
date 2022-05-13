#pragma once
#include "afx.h"
#include "Figure.h"

class Circle :
	public Figure
{
public:
	Circle();
	Circle(int x1, int y1);
	Circle(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	~Circle();
};

