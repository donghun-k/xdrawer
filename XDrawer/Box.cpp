#include "stdafx.h"
#include "Box.h"

IMPLEMENT_SERIAL(Box, TwoPointFigure, 1)
Box::Box()
	:TwoPointFigure()
{	
}
Box::Box(int x1, int y1)
	:TwoPointFigure(x1, y1)
{	
}
Box::Box(int x1, int y1, int x2, int y2)
	:TwoPointFigure(x1, y1, x2, y2)
{
}
Box::~Box()
{
}
void Box::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);
}
//Scope resolution operator
void Box::draw(CDC* pDC)
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}
