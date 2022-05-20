#pragma once
#include "afx.h"
#include "TwoPointFigure.h"

class Circle :
	public TwoPointFigure
{
	DECLARE_SERIAL(Circle)
public:
	Circle();
	Circle(int x1, int y1);
	Circle(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	~Circle();
};

