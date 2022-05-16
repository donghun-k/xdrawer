#include "stdafx.h"
#include "X.h"
#define DELTA	(4)

X::X()
	:Figure()
{	
}
X::X(int x1, int y1)
	:Figure(x1, y1)
{	
}
X::~X()
{
}

//Scope resolution operator
void X::draw(CDC* pDC)
{
	pDC->MoveTo(m_x1-DELTA, m_y1-DELTA);
	pDC->LineTo(m_x1+DELTA, m_y1+DELTA);
	pDC->MoveTo(m_x1+DELTA, m_y1-DELTA);
	pDC->LineTo(m_x1-DELTA, m_y1+DELTA);
}

void X::setXY2(int x, int y)
{
	m_x1 = x;
	m_y1 = y;
}