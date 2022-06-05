#include "stdafx.h"
#include "UFO.h"

#include "Circle.h"
#include "FigureList.h"
#include "XDrawerView.h"


#define DELTA	(10)
IMPLEMENT_SERIAL(UFO, TwoPointFigure, 1)
UFO::UFO()
	:CompositeFigure()
{	
	c1 = new Circle();
	c2 = new Circle();

	_fillFlag = FALSE;

	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::UFO(int x1, int y1)
	:CompositeFigure()
{
	c1 = new Circle(x1-DELTA, y1-DELTA, x1+DELTA, y1+DELTA);
	c2 = new Circle(x1-DELTA, y1-DELTA, x1+DELTA, y1+DELTA);

	_fillFlag = FALSE;

	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::UFO(int x1, int y1, int x2, int y2)
	:CompositeFigure()
{
	c1 = new Circle(x1-DELTA, y1-DELTA, x1+DELTA, y1+DELTA);
	c2 = new Circle(x2-DELTA, y2-DELTA, x2+DELTA, y2+DELTA);

	_fillFlag = FALSE;

	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::~UFO()
{
	
}
void UFO::Serialize(CArchive& ar)
{
	CompositeFigure::Serialize(ar);
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << _fillFlag;
	} else {
		ar >> _fillFlag;
	}
}
void UFO::setXY2(int x, int y)
{
	c2->setXY12(x-DELTA, y-DELTA, x+DELTA, y+DELTA);
}
void UFO::drawDots(CDC* pDC) 
{
	POSITION pos = parts->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = parts->GetNext(pos);
		ptr->drawDots(pDC);
	}
}
void UFO::setFill()
{
	_fillFlag = TRUE;
	POSITION pos = parts->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = parts->GetNext(pos);
		ptr->setFill();
	}
}
Figure* UFO::copy(CXDrawerView* view)
{
	int x1 = c1->getX1()+DELTA;
	int y1 = c1->getY1()+DELTA;
	int x2 = c2->getX1()+DELTA;
	int y2 = c2->getY1()+DELTA;
	UFO *newUFO = new UFO(x1, y1, x2, y2);
	newUFO->setColor(_color);
	if(_fillFlag == TRUE) {
		newUFO->setFill();
	}
	newUFO->setPopup(view->ufoPopup);
	newUFO->move(30,20);	
	return newUFO;
}
