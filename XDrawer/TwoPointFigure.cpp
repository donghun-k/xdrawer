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
TwoPointFigure::~TwoPointFigure()
{
}
