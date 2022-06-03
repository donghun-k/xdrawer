#pragma once
#include "figure.h"

#define DELTA	(4)

class OnePointFigure :
	public Figure
{
	DECLARE_SERIAL(OnePointFigure)
protected:
	int m_x1;
	int m_y1;
public:
	OnePointFigure();
	OnePointFigure(int x1, int y1);
	virtual void setXY2(int x, int y);
	virtual void Serialize(CArchive& ar);
	virtual void makeRegion();
	virtual int getX1(){ return m_x1; }
	virtual int getY1(){ return m_y1; }
	~OnePointFigure();
};

