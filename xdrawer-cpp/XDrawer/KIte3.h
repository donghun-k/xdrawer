#pragma once
#include "CompositeFigure.h"

class Line;
class Circle;
class Box;
class Kite3 :
	public CompositeFigure
{
	Line *l1;
	Line *l2;
	Line *l3;
	Line *l4;
	Circle *center;
	Box *frame;
	DECLARE_SERIAL(Kite3)
public:	
	Kite3();
	Kite3(int x1, int y1);
	Kite3(int x1, int y1, int x2, int y2);
	virtual void setXY2(int x, int y);		
	virtual void drawDots(CDC* pDC);
	virtual Figure* copy(CXDrawerView* view);
	virtual void Serialize(CArchive& ar);
	~Kite3();
};
