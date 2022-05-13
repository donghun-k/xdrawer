#pragma once
#include "afx.h"
#include "Figure.h"

class Box :
	public Figure
{
	
public:	
	Box();
	Box(int x1, int y1);
	Box(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);	
	~Box();
};

