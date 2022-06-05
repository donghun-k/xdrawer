#include "stdafx.h"
#include "X.h"

IMPLEMENT_SERIAL(X, OnePointFigure, 1)
X::X()
	:OnePointFigure()
{	
}
X::X(int x1, int y1)
	:OnePointFigure(x1, y1)
{	
}
X::~X()
{
}
void X::Serialize(CArchive& ar)
{
	OnePointFigure::Serialize(ar);
}

//Scope resolution operator
void X::draw(CDC* pDC)
{
	CPen pen(PS_SOLID,1,_color);
	CPen *oldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(m_x1-DELTA, m_y1-DELTA);
	pDC->LineTo(m_x1+DELTA, m_y1+DELTA);
	pDC->MoveTo(m_x1+DELTA, m_y1-DELTA);
	pDC->LineTo(m_x1-DELTA, m_y1+DELTA);
	pDC->SelectObject(oldPen);
}
