#pragma once
#include "afx.h"
#include "TwoPointFigure.h"

class Box :
	public TwoPointFigure
{
	DECLARE_SERIAL(Box)
public:	
	Box();
	Box(int x1, int y1);
	Box(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	~Box();
};

