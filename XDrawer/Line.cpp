#include "stdafx.h"
#include "Line.h"


Line::Line()
{
	m_x1 = m_x2 = m_y1 = m_y2 = 0;
}
Line::Line(int x1, int y1)
{
	m_x1 = m_x2 = x1;
	m_y1 = m_y2 = y1;
}
Line::Line(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}
Line::~Line()
{
}

//Scope resolution operator
void Line::draw(CDC* pDC)
{
	pDC->MoveTo(m_x1, m_y1);
	pDC->LineTo(m_x2, m_y2);
}

void Line::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}
