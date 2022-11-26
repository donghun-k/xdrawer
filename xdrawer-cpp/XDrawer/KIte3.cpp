#include "stdafx.h"
#include "KIte3.h"

#include "Line.h"
#include "Circle.h"
#include "Box.h"
#include "FigureList.h"
#include "XDrawerView.h"

IMPLEMENT_SERIAL(Kite3, CompositeFigure, 1)
Kite3::Kite3()
	:CompositeFigure()
{	
	frame = new Box();
	l1 = new Line();
	l2 = new Line();
	l3 = new Line();
	l4 = new Line();
	center = new Circle();

	parts->AddTail(frame);
	parts->AddTail(l1);
	parts->AddTail(l2);
	parts->AddTail(l3);
	parts->AddTail(l4);
	parts->AddTail(center);
}
Kite3::Kite3(int x1, int y1)
	:CompositeFigure()
{	
	frame = new Box(x1, y1);
	l1 = new Line(x1, y1);
	l2 = new Line(x1, y1);
	l3 = new Line(x1, y1);
	l4 = new Line(x1, y1);
	center = new Circle(x1, y1);

	parts->AddTail(frame);
	parts->AddTail(l1);
	parts->AddTail(l2);
	parts->AddTail(l3);
	parts->AddTail(l4);
	parts->AddTail(center);
}
Kite3::Kite3(int x1, int y1, int x2, int y2)
	:CompositeFigure()
{
	int w = x2 - x1;
	int h = y2 - y1;
	frame = new Box(x1, y1, x2, y2);
	l1 = new Line(x1, y1, x2, y2);
	l2 = new Line(x1+w/2, y1, x1+w/2, y2);
	l3 = new Line(x2, y1, x1, y2);
	l4 = new Line(x1, y1+h/2, x2, y2-h/2);
	center = new Circle(x1+w/4, y1+h/4,x2-w/4, y2-h/4);

	parts->AddTail(frame);
	parts->AddTail(l1);
	parts->AddTail(l2);
	parts->AddTail(l3);
	parts->AddTail(l4);
	parts->AddTail(center);
}
Kite3::~Kite3()
{
	
}
void Kite3::Serialize(CArchive& ar)
{
	CompositeFigure::Serialize(ar);
}
//Scope resolution operator
void Kite3::setXY2(int x, int y)
{
	int x1 = frame->getX1();
	int y1 = frame->getY1();
	int w = x - x1;
	int h = y - y1;

	frame->setXY2(x, y);
	l1->setXY2(x, y);
	l2->setXY12(x1+w/2, y1, x1+w/2, y);
	l3->setXY12(x, y1, x1, y);
	l4->setXY12(x1, y1+h/2, x, y-h/2);
	center->setXY12(x1+w/4, y1+h/4,x-w/4, y-h/4);
}
void Kite3::drawDots(CDC* pDC)
{
	dotedFlag = TRUE;
	int m_x1 = frame->getX1();
	int m_y1 = frame->getY1();
	int m_x2 = frame->getX2();
	int m_y2 = frame->getY2();
	if (m_x1 > m_x2) {
		int tmp = m_x1;
		m_x1 = m_x2;
		m_x2 = tmp;
	} 
	if (m_y1 > m_y2) {
		int tmp = m_y1;
		m_y1 = m_y2;
		m_y2 = tmp;
	}
	int x1 = m_x1;
	int y1 = m_y1;
	int x2 = m_x2;
	int y2 = m_y2;
	CRect rect1(x1-DOTSIZE,y1-DOTSIZE,x1,y1);
	CRect rect2(x2,y1-DOTSIZE,x2+DOTSIZE,y1);
	CRect rect3(x2,y2,x2+DOTSIZE,y2+DOTSIZE);
	CRect rect4(x1-DOTSIZE,y2,x1,y2+DOTSIZE);
	CBrush brush(BLACK_COLOR);
	pDC->FillRect(&rect1,&brush);
	pDC->FillRect(&rect2,&brush);
	pDC->FillRect(&rect3,&brush);
	pDC->FillRect(&rect4,&brush);
}

Figure* Kite3::copy(CXDrawerView* view)
{
	int x1 = frame->getX1();
	int y1 = frame->getY1();
	int x2 = frame->getX2();
	int y2 = frame->getY2();
	Kite3 *newKite = new Kite3(x1, y1, x2, y2);
	newKite->setColor(_color);
	newKite->setPopup(view->kite3Popup);
	newKite->move(30,20);	
	return newKite;
}
