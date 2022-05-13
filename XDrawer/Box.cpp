#include "stdafx.h"
#include "Box.h"

Box::Box()
	:Figure()
{	
}
Box::Box(int x1, int y1)
	:Figure(x1, y1)
{	
}
Box::Box(int x1, int y1, int x2, int y2)
	:Figure(x1, y1, x2, y2)
{
}
Box::~Box()
{
}

//Scope resolution operator
void Box::draw(CDC* pDC)
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}
