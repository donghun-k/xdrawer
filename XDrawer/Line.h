#pragma once
#include "afx.h"
#include "TwoPointFigure.h"

class Line :
	public TwoPointFigure
{
	DECLARE_SERIAL(Line)
	int regionWidth;
	int x;
	int y;
	int w;
	int h;
	double angle;
	double theta;
	int dx;
	int dy;
	CPoint points[4];
public:
	Line();
	Line(int x1, int y1);
	Line(int x1, int y1, int x2, int y2);
	void calcPoint();
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	virtual void makeRegion();
	virtual void drawDots(CDC* pDC);
	~Line();
};

