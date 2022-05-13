#pragma once
#include "figure.h"
class Diamond :
	public Figure
{
public:
	Diamond();
	Diamond(int x1, int y1);
	Diamond(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);	
	~Diamond();
};

