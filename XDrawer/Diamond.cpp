#include "stdafx.h"
#include "Diamond.h"


Diamond::Diamond()
	:Figure()
{	
}
Diamond::Diamond(int x1, int y1)
	:Figure(x1, y1)
{	
}
Diamond::Diamond(int x1, int y1, int x2, int y2)
	:Figure(x1, y1, x2, y2)
{
}
Diamond::~Diamond()
{
}

//Scope resolution operator
void Diamond::draw(CDC* pDC)
{
	pDC->RoundRect(m_x1, m_y1, m_x2, m_y2, 10, 10);
}
