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
