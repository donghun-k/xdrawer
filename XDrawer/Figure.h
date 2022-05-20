#pragma once
#include "afx.h"
class Figure :
	public CObject
{
	DECLARE_SERIAL(Figure)
public:
	Figure();
	// pure virtual function
	virtual void draw(CDC* pDC) {};
	virtual void setXY2(int x, int y) {};
	virtual void Serialize(CArchive& ar);
	~Figure();
};

