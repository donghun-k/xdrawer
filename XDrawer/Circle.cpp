#include "stdafx.h"
#include "Circle.h"

IMPLEMENT_SERIAL(Circle, TwoPointFigure, 1)
Circle::Circle()
	:TwoPointFigure()
{
}
Circle::Circle(int x1, int y1)
	:TwoPointFigure(x1, y1)
{
}
Circle::Circle(int x1, int y1, int x2, int y2)
	:TwoPointFigure(x1, y1, x2, y2)
{
}
Circle::~Circle()
{
}
void Circle::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);
}

//Scope resolution operator
void Circle::draw(CDC* pDC)
{
	pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
}