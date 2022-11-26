#pragma once
#include "TwoPointFigure.h"

class Line;
class Circle;
class Box;
class Kite2 :
	public TwoPointFigure
{
	Line *l1;
	Line *l2;
	Line *l3;
	Line *l4;
	Circle *center;
	Box *frame;
	DECLARE_SERIAL(Kite2)
public:	
	Kite2();
	Kite2(int x1, int y1);
	Kite2(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void setXY2(int x, int y);
	virtual void move(int dx,int dy);
	virtual void setColor(COLORREF color);
	virtual Figure* copy(CXDrawerView* view);	
	virtual void Serialize(CArchive& ar);
	~Kite2();
};

