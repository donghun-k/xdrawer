#pragma once
#include "CompositeFigure.h"

class Circle;
class UFO :
	public CompositeFigure
{		
	DECLARE_SERIAL(UFO)
	Circle *c1;
	Circle *c2;
	bool _fillFlag;
public:	
	UFO();
	UFO(int x1, int y1);
	UFO(int x1, int y1, int x2, int y2);
	virtual void setXY2(int x, int y);
	virtual void drawDots(CDC* pDC);
	virtual void setFill();	
	virtual Figure* copy(CXDrawerView* view);
	virtual void Serialize(CArchive& ar);
	~UFO();
};

