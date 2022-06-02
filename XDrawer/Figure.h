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
	virtual void makeRegion() {};
	virtual void Serialize(CArchive& ar);
	~Figure();
};

