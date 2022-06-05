#pragma once
#include "box.h"

class Line;
class Circle;
class Kite1 :
	public Box
{
	Line *l1;
	Line *l2;
	Line *l3;
	Line *l4;
	Circle *center;
	DECLARE_SERIAL(Kite1)
public:	
	Kite1();
	Kite1(int x1, int y1);
	Kite1(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void setXY2(int x, int y);	
	virtual void move(int dx,int dy);
	virtual void setColor(COLORREF color);
	virtual Figure* copy(CXDrawerView* view);
	virtual void Serialize(CArchive& ar);
	~Kite1();
};

