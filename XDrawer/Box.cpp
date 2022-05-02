#include "stdafx.h"
#include "Box.h"

Box::Box()
{
	m_x1 = m_x2 = m_y1 = m_y2 = 0;
}
Box::Box(int x1, int y1)
{
	m_x1 = m_x2 = x1;
	m_y1 = m_y2 = y1;
}
Box::Box(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}
Box::~Box()
{
}

//Scope resolution operator
void Box::draw(CDC* pDC)
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}

void Box::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}