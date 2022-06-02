#pragma once
#include "afx.h"
#include "TwoPointFigure.h"

class Line :
	public TwoPointFigure
{
	DECLARE_SERIAL(Line)
public:
	Line();
	Line(int x1, int y1);
	Line(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	virtual void makeRegion();
	~Line();
};

