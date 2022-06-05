#include "stdafx.h"
#include "Diamond.h"
#include "XDrawerView.h"

IMPLEMENT_SERIAL(Diamond, TwoPointFigure, 1)
Diamond::Diamond()
	:TwoPointFigure()
{	
	_fillFlag = FALSE;
}
Diamond::Diamond(int x1, int y1)
	:TwoPointFigure(x1, y1)
{	
	_fillFlag = FALSE;
}
Diamond::Diamond(int x1, int y1, int x2, int y2)
	:TwoPointFigure(x1, y1, x2, y2)
{
	_fillFlag = FALSE;
}
Diamond::~Diamond()
{
}
void Diamond::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);
}

//Scope resolution operator
void Diamond::draw(CDC* pDC)
{
	int dx, dy;
	dx = m_x1 + (m_x2 - m_x1) / 2;
	dy = m_y1 + (m_y2 - m_y1) / 2;

	POINT arPt[5] = {{dx, m_y1}, {m_x2, dy}, {dx, m_y2}, {m_x1, dy}};

	if (_fillFlag == FALSE) {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		pDC->Polygon(arPt, 4);
		pDC->SelectObject(oldPen);
	} else {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		CBrush brush(_color);
		CBrush *oldBrush = pDC->SelectObject(&brush);
		pDC->Polygon(arPt, 4);
		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);
	}
	/*
	pDC->MoveTo(dx, m_y1); 
	pDC->LineTo(m_x2, dy);
	pDC->LineTo(dx, m_y2);
	pDC->LineTo(m_x1, dy);
	pDC->LineTo(dx, m_y1);
	*/
}
void Diamond::setFill()
{
	_fillFlag = !_fillFlag;
}
Figure* Diamond::copy(CXDrawerView* view)
{
	Diamond *newDiamond = new Diamond(m_x1,m_y1,m_x2,m_y2);
	newDiamond->_fillFlag = _fillFlag;
	newDiamond->setColor(_color);
	newDiamond->setPopup(view->diamondPopup);
	newDiamond->move(30,20);
	return newDiamond;
}