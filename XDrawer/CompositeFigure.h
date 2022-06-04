#pragma once

class FigureList;
#include "figure.h"
class CompositeFigure :
	public Figure
{
	DECLARE_SERIAL(CompositeFigure)
protected:
	FigureList *parts;
public:
	CompositeFigure();
	~CompositeFigure();
	virtual void Serialize(CArchive& ar);
	virtual void draw(CDC* pDC);
	virtual void makeRegion();
	virtual BOOL ptInRgn(int x, int y);
	virtual void move(int dx,int dy);
};

