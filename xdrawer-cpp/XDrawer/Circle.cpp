#include "stdafx.h"
#include "Circle.h"
#include "XDrawerView.h"

IMPLEMENT_SERIAL(Circle, TwoPointFigure, 1)
Circle::Circle()
	:TwoPointFigure()
{
	_fillFlag = FALSE;
}
Circle::Circle(int x1, int y1)
	:TwoPointFigure(x1, y1)
{
	_fillFlag = FALSE;
}
Circle::Circle(int x1, int y1, int x2, int y2)
	:TwoPointFigure(x1, y1, x2, y2)
{
	_fillFlag = FALSE;
}
Circle::~Circle()
{
}
void Circle::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << _fillFlag;
	} else {
		ar >> _fillFlag;
	}
}

//Scope resolution operator
void Circle::draw(CDC* pDC)
{
	if (_fillFlag == FALSE) {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
		pDC->SelectObject(oldPen);
	} else {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		CBrush brush(_color);
		CBrush *oldBrush = pDC->SelectObject(&brush);
		pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);
	}
}
void Circle::setFill()
{
	_fillFlag = !_fillFlag;
}
Figure* Circle::copy(CXDrawerView* view)
{
	Circle *newCircle = new Circle(m_x1,m_y1,m_x2,m_y2);
	newCircle->_fillFlag = _fillFlag;
	newCircle->setColor(_color);
	newCircle->setPopup(view->circlePopup);
	newCircle->move(30,20);
	return newCircle;
}