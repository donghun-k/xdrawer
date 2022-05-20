#pragma once
#include "OnePointFigure.h"

class Bubble :
	public OnePointFigure
{
	DECLARE_SERIAL(Bubble)
public:	
	Bubble();
	Bubble(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	~Bubble();
};

