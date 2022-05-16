#include "stdafx.h"
#include "Bubble.h"
#define DELTA	(4)

Bubble::Bubble()
	:Figure()
{	
}
Bubble::Bubble(int x1, int y1)
	:Figure(x1, y1)
{	
}
Bubble::~Bubble()
{
}

//Scope resolution operator
void Bubble::draw(CDC* pDC)
{
	pDC->Ellipse(m_x1-DELTA, m_y1-DELTA, m_x1+DELTA, m_y1+DELTA);
}

void Bubble::setXY2(int x, int y)
{
	m_x1 = x;
	m_y1 = y;
}
