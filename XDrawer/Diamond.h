#pragma once
#include "afx.h"
#include "TwoPointFigure.h"

class Diamond :
	public TwoPointFigure
{
	DECLARE_SERIAL(Diamond)
	BOOL _fillFlag;
public:
	Diamond();
	Diamond(int x1, int y1);
	Diamond(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void setFill();
	virtual void Serialize(CArchive& ar);
	~Diamond();
};

