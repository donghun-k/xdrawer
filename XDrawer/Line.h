#pragma once
#include "afx.h"
#include "Figure.h"

class Line :
	public Figure
{
public:
	Line();
	Line(int x1, int y1);
	Line(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	~Line();
};

