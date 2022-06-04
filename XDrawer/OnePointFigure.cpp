#include "stdafx.h"
#include "OnePointFigure.h"

IMPLEMENT_SERIAL(OnePointFigure, Figure, 1)
OnePointFigure::OnePointFigure()
	: Figure()
{
	m_x1 = m_y1 = 0;
}
OnePointFigure::OnePointFigure(int x1, int y1)
	: Figure()
{
	m_x1 = x1;
	m_y1 = y1;
}
void OnePointFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);
	if (ar.IsStoring()) {
		ar << m_x1 << m_y1;
	} else {
		ar >> m_x1 >> m_y1;
	}
}
void OnePointFigure::setXY2(int x, int y)
{
	m_x1 = x;
	m_y1 = y;
}
OnePointFigure::~OnePointFigure()
{
}

void OnePointFigure::makeRegion()
{
	if(region != NULL) delete region;

	region = new CRgn();
	region->CreateRectRgn(m_x1-DELTA, m_y1-DELTA, m_x1+DELTA, m_y1+DELTA);
}
void OnePointFigure::move(int dx,int dy)
{
	m_x1 = m_x1 + dx; m_y1 = m_y1 + dy;
}
void OnePointFigure::drawDots(CDC* pDC)
{
	dotedFlag = TRUE;
	int x1 = m_x1;
	int y1 = m_y1;
	CRect rect1(m_x1-DELTA-DOTSIZE, m_y1-DELTA-DOTSIZE, m_x1-DELTA, m_y1-DELTA);
	CRect rect2(m_x1+DELTA, m_y1-DELTA-DOTSIZE, m_x1+DELTA+DOTSIZE, m_y1-DELTA);
	CRect rect3(m_x1-DELTA-DOTSIZE, m_y1+DELTA+DOTSIZE, m_x1-DELTA, m_y1+DELTA);
	CRect rect4(m_x1+DELTA, m_y1+DELTA+DOTSIZE, m_x1+DELTA+DOTSIZE, m_y1+DELTA);
	CBrush brush(BLACK_COLOR);
	pDC->FillRect(&rect1,&brush);
	pDC->FillRect(&rect2,&brush);
	pDC->FillRect(&rect3,&brush);
	pDC->FillRect(&rect4,&brush);
}
