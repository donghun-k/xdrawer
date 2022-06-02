#include "stdafx.h"
#include <math.h>

#include "Line.h"


#ifndef M_PI
#define M_PI (3.1415926535897)
#endif

#define sign(x) ((x>0) ? x : -x)

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
void Line::makeRegion()
{
	int regionWidth = 6;
	int x = m_x1;
	int y = m_y1;
	int w = m_x2 - m_x1;
	int h = m_y2 - m_y1;
	double angle;
	double theta = w ? atan(double(h)/double(w)) : sign(h)*M_PI/2.;
	if (theta < 0) theta = theta + 2 * M_PI;
	angle = (theta + M_PI / 2.);
	int dx = int(regionWidth * cos(angle));
	int dy = int(regionWidth * sin(angle));
	CPoint points[4];
	points[0].x = x + dx;
	points[0].y = y + dy;
	points[1].x = x - dx;
	points[1].y = y - dy;
	points[2].x = x + w - dx;
	points[2].y = y + h - dy;
	points[3].x = x + w + dx;
	points[3].y = y + h + dy;
	if (region) delete region;
	region = new CRgn();
	region->CreatePolygonRgn(points,4,WINDING);
}
