#include "stdafx.h"
#include "UFO.h"

#include "Circle.h"
#include "FigureList.h"


#define DELTA	(6)
IMPLEMENT_SERIAL(UFO, TwoPointFigure, 1)
UFO::UFO()
	:CompositeFigure()
{	
	c1 = new Circle();
	c2 = new Circle();

	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::UFO(int x1, int y1)
	:CompositeFigure()
{	
	c1 = new Circle(x1-DELTA, y1-DELTA, x1+DELTA, y1+DELTA);
	c2 = new Circle(x1-DELTA, y1-DELTA, x1+DELTA, y1+DELTA);

	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::UFO(int x1, int y1, int x2, int y2)
	:CompositeFigure()
{
	c1 = new Circle(x1-DELTA, y1-DELTA, x1+DELTA, y1+DELTA);
	c2 = new Circle(x2-DELTA, y2-DELTA, x2+DELTA, y2+DELTA);

	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::~UFO()
{
	
}
void UFO::Serialize(CArchive& ar)
{
	CompositeFigure::Serialize(ar);
}
//Scope resolution operator
void UFO::setXY2(int x, int y)
{
	c2->setXY12(x-DELTA, y-DELTA, x+DELTA, y+DELTA);
}
