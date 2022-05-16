#pragma once
#include "afx.h"
class Figure :
	public CObject
{
	// c++ 기본 접근제어는 private
protected:
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
public:
	Figure();
	Figure(int x1, int y1);
	Figure(int x1, int y1, int x2, int y2);	
	// pure virtual function
	virtual void draw(CDC* pDC) = 0;
	virtual void setXY2(int x, int y);
	~Figure();
};

