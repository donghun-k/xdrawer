#pragma once
#include "figure.h"
class TwoPointFigure :
	public Figure
{
	DECLARE_SERIAL(TwoPointFigure)
protected:
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
public:
	TwoPointFigure();
	TwoPointFigure(int x1, int y1);
	TwoPointFigure(int x1, int y1, int x2, int y2);	
	void virtual setXY2(int x, int y);
	void virtual setXY12(int x1, int y1, int x2, int y2);
	virtual void Serialize(CArchive& ar);
	virtual void makeRegion();
	virtual int getX1(){ return m_x1; }
	virtual int getY1(){ return m_y1; }
	virtual int getX2(){ return m_x2; }
	virtual int getY2(){ return m_y2; }
	~TwoPointFigure();
};

