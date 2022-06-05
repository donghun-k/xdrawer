#include "stdafx.h"
#include "Bubble.h"
#include "XDrawerView.h"

IMPLEMENT_SERIAL(Bubble, OnePointFigure, 1)
Bubble::Bubble()
	:OnePointFigure()
{	
	_fillFlag = FALSE;
}
Bubble::Bubble(int x1, int y1)
	:OnePointFigure(x1, y1)
{	
	_fillFlag = FALSE;
}
Bubble::~Bubble()
{
}
void Bubble::Serialize(CArchive& ar)
{
	OnePointFigure::Serialize(ar);
}
//Scope resolution operator
void Bubble::draw(CDC* pDC)
{
	if (_fillFlag == FALSE) {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		pDC->Ellipse(m_x1-DELTA, m_y1-DELTA, m_x1+DELTA, m_y1+DELTA);
		pDC->SelectObject(oldPen);
	} else {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		CBrush brush(_color);
		CBrush *oldBrush = pDC->SelectObject(&brush);
		pDC->Ellipse(m_x1-DELTA, m_y1-DELTA, m_x1+DELTA, m_y1+DELTA);
		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);
	}	
}
void Bubble::setFill()
{
	_fillFlag = !_fillFlag;
}
Figure* Bubble::copy(CXDrawerView* view)
{
	Bubble *newBubble = new Bubble(m_x1,m_y1);
	newBubble->setColor(_color);
	newBubble->setPopup(view->bubblePopup);
	newBubble->move(30,20);
	return newBubble;
}

