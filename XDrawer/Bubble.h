#pragma once
#include "figure.h"

class Bubble :
	public Figure
{
	
public:	
	Bubble();
	Bubble(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void setXY2(int x, int y);
	~Bubble();
};

