#include "stdafx.h"
#include "Bubble.h"

IMPLEMENT_SERIAL(Bubble, OnePointFigure, 1)
Bubble::Bubble()
	:OnePointFigure()
{	
}
Bubble::Bubble(int x1, int y1)
	:OnePointFigure(x1, y1)
{	
}
Bubble::~Bubble()
{
}
void Bubble::Serialize(CArchive& ar)
{
	OnePointFigure::Serialize(ar);
}
//Scope resolution operator
void Bubble::draw(CDC* pDC)
{
	pDC->Ellipse(m_x1-DELTA, m_y1-DELTA, m_x1+DELTA, m_y1+DELTA);
}

