#include "stdafx.h"
#include "Circle.h"


Circle::Circle()
{
	m_x1 = m_x2 = m_y1 = m_y2 = 0;
}
Circle::Circle(int x1, int y1)
{
	m_x1 = m_x2 = x1;
	m_y1 = m_y2 = y1;
}
Circle::Circle(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}
Circle::~Circle()
{
}

//Scope resolution operator
void Circle::draw(CDC* pDC)
{
	pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
}

void Circle::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}