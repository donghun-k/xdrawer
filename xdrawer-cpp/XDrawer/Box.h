#pragma once
#include "afx.h"
#include "TwoPointFigure.h"

class Box :
	public TwoPointFigure
{
	DECLARE_SERIAL(Box)
	BOOL _fillFlag;
public:	
	Box();
	Box(int x1, int y1);
	Box(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void setFill();
	virtual Figure* copy(CXDrawerView* view);
	virtual void Serialize(CArchive& ar);
	~Box();
};

