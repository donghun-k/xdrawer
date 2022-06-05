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
	CPen pen(PS_SOLID,1,_color);
	CPen *oldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(m_x1, m_y1);
	pDC->LineTo(m_x2, m_y2);
	pDC->SelectObject(oldPen);
}
void Line::calcPoint()
{
	regionWidth = 15;
	x = m_x1;
	y = m_y1;
	w = m_x2 - m_x1;
	h = m_y2 - m_y1;
	theta = w ? atan(double(h)/double(w)) : sign(h)*M_PI/2.;
	if (theta < 0) theta = theta + 2 * M_PI;
	angle = (theta + M_PI / 2.);
	dx = int(regionWidth * cos(angle));
	dy = int(regionWidth * sin(angle));	
	points[0].x = x + dx;
	points[0].y = y + dy;
	points[1].x = x - dx;
	points[1].y = y - dy;
	points[2].x = x + w - dx;
	points[2].y = y + h - dy;
	points[3].x = x + w + dx;
	points[3].y = y + h + dy;
}
void Line::makeRegion()
{	
	calcPoint();
	if (region) delete region;
	region = new CRgn();
	region->CreatePolygonRgn(points,4,WINDING);
}
void Line::drawDots(CDC* pDC)
{
	calcPoint();
	dotedFlag = TRUE;	
	CRect rect1(points[0].x-DOTSIZE,points[0].y-DOTSIZE,points[0].x,points[0].y);
	CRect rect2(points[1].x, points[1].y, points[1].x+DOTSIZE, points[1].y+DOTSIZE);
	CRect rect3(points[2].x+DOTSIZE,points[2].y+DOTSIZE,points[2].x,points[2].y);
	CRect rect4(points[3].x, points[3].y, points[3].x-DOTSIZE, points[3].y-DOTSIZE);
	CBrush brush(BLACK_COLOR);
	pDC->FillRect(&rect1,&brush);
	pDC->FillRect(&rect2,&brush);
	pDC->FillRect(&rect3,&brush);
	pDC->FillRect(&rect4,&brush);
}
