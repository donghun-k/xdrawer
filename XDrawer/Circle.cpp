#include "stdafx.h"
#include "Circle.h"


Circle::Circle()
	:Figure()
{
}
Circle::Circle(int x1, int y1)
	:Figure(x1, y1)
{
}
Circle::Circle(int x1, int y1, int x2, int y2)
	:Figure(x1, y1, x2, y2)
{
}
Circle::~Circle()
{
}

//Scope resolution operator
void Circle::draw(CDC* pDC)
{
	pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
}