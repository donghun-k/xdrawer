#pragma once
#include "figure.h"

class X :
	public Figure
{
	
public:	
	X();
	X(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void setXY2(int x, int y);
	~X();
};

