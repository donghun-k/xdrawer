#include "stdafx.h"
#include "TwoPointFigure.h"

IMPLEMENT_SERIAL(TwoPointFigure, Figure, 1)
TwoPointFigure::TwoPointFigure()
	: Figure()
{
	m_x1 = m_x2 = m_y1 = m_y2 = 0;
}
TwoPointFigure::TwoPointFigure(int x1, int y1)
	: Figure()
{
	m_x1 = m_x2 = x1;
	m_y1 = m_y2 = y1;
}
TwoPointFigure::TwoPointFigure(int x1, int y1, int x2, int y2)
	: Figure()
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}
void TwoPointFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);
	if (ar.IsStoring()) {
		ar << m_x1 << m_y1 << m_x2 << m_y2;
	} else {
		ar >> m_x1 >> m_y1 >> m_x2 >> m_y2;
	}
}
void TwoPointFigure::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}
void TwoPointFigure::setXY12(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}
void TwoPointFigure::makeRegion()
{
	if(region != NULL) delete region;

	region = new CRgn();
	region->CreateRectRgn(m_x1, m_y1, m_x2, m_y2);
}
void TwoPointFigure::move(int dx,int dy)
{
	m_x1 = m_x1 + dx; m_y1 = m_y1 + dy;
	m_x2 = m_x2 + dx; m_y2 = m_y2 + dy;
}
void TwoPointFigure::drawDots(CDC* pDC)
{
	dotedFlag = TRUE;
	if (m_x1 > m_x2) {
		int tmp = m_x1;
		m_x1 = m_x2;
		m_x2 = tmp;
	} 
	if (m_y1 > m_y2) {
		int tmp = m_y1;
		m_y1 = m_y2;
		m_y2 = tmp;
	}
	int x1 = m_x1;
	int y1 = m_y1;
	int x2 = m_x2;
	int y2 = m_y2;
	CRect rect1(x1-DOTSIZE,y1-DOTSIZE,x1,y1);
	CRect rect2(x2,y1-DOTSIZE,x2+DOTSIZE,y1);
	CRect rect3(x2,y2,x2+DOTSIZE,y2+DOTSIZE);
	CRect rect4(x1-DOTSIZE,y2,x1,y2+DOTSIZE);
	CBrush brush(BLACK_COLOR);
	pDC->FillRect(&rect1,&brush);
	pDC->FillRect(&rect2,&brush);
	pDC->FillRect(&rect3,&brush);
	pDC->FillRect(&rect4,&brush);
}
TwoPointFigure::~TwoPointFigure()
{
}
