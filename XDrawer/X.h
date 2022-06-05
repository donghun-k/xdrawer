#pragma once
#include "OnePointFigure.h"

class X :
	public OnePointFigure
{
	DECLARE_SERIAL(X)
public:	
	X();
	X(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual Figure* copy(CXDrawerView* view);
	virtual void Serialize(CArchive& ar);
	~X();
};

