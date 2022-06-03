#pragma once
#include "afx.h"

class FigurePopup;
class Figure :
	public CObject
{
	DECLARE_SERIAL(Figure)	
public:
	CRgn *region;
	FigurePopup *popupPtr;
	Figure();
	// pure virtual function
	void setPopup(FigurePopup *popup) {
		popupPtr = popup;
	}
	void popup(int x, int y);
	virtual void draw(CDC* pDC) {};
	virtual void setXY2(int x, int y) {};
	virtual void setXY12(int x1, int y1, int x2, int y2) {};
	virtual void makeRegion() {};
	virtual void Serialize(CArchive& ar);
	virtual int getX1(){ return -1; }
	virtual int getY1(){ return -1; }
	virtual int getX2(){ return -1; }
	virtual int getY2(){ return -1; }
	virtual BOOL ptInRgn(int x, int y);
	~Figure();
};

