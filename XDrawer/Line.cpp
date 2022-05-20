#include "stdafx.h"
#include "Line.h"

IMPLEMENT_SERIAL(Line, TwoPointFigure, 1)
Line::Line()
	:TwoPointFigure()
{
}
Line::Line(int x1, int y1)
	:TwoPointFigure(x1, y1)
{
}
Line::Line(int x1, int y1, int x2, int y2)
	:TwoPointFigure(x1, y1, x2, y2)
{
}
Line::~Line()
{
}

void Line::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);
}
//Scope resolution operator
void Line::draw(CDC* pDC)
{
	pDC->MoveTo(m_x1, m_y1);
	pDC->LineTo(m_x2, m_y2);
}
