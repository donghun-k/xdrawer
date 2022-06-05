#include "stdafx.h"
#include "Box.h"
#include "XDrawerView.h"

IMPLEMENT_SERIAL(Box, TwoPointFigure, 1)
Box::Box()
	:TwoPointFigure()
{	
	_fillFlag = FALSE;
}
Box::Box(int x1, int y1)
	:TwoPointFigure(x1, y1)
{	
	_fillFlag = FALSE;
}
Box::Box(int x1, int y1, int x2, int y2)
	:TwoPointFigure(x1, y1, x2, y2)
{
	_fillFlag = FALSE;
}
Box::~Box()
{
}
void Box::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);
}
void Box::draw(CDC* pDC)
{
	if (_fillFlag == FALSE) {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
		pDC->SelectObject(oldPen);	
	} else {
		CPen pen(PS_SOLID,1,_color);
		CPen *oldPen = pDC->SelectObject(&pen);
		CBrush brush(_color);
		CBrush *oldBrush = pDC->SelectObject(&brush);
		pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);
	}	
}
void Box::setFill()
{
	_fillFlag = !_fillFlag;
}
Figure* Box::copy(CXDrawerView* view)
{
	Box *newBox = new Box(m_x1,m_y1,m_x2,m_y2);
	newBox->_fillFlag = _fillFlag;
	newBox->setColor(_color);
	newBox->setPopup(view->boxPopup);
	newBox->move(30,20);
	return newBox;
}
