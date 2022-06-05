#pragma once
#include "afx.h"

#define BLACK_COLOR		(RGB(0,0,0))
#define RED_COLOR		(RGB(255,0,0))
#define GREEN_COLOR		(RGB(0,255,0))
#define BLUE_COLOR		(RGB(0,0,255))

#define DOTSIZE		(4)

class CXDrawerView;
class FigurePopup;
class Figure :
	public CObject
{
	DECLARE_SERIAL(Figure)	
protected:
	BOOL dotedFlag;
	COLORREF _color;
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
	virtual void move(CDC* pDC,int dx,int dy);
	virtual void move(int dx,int dy) {}
	virtual void drawDots(CDC* pDC) {}
	virtual void eraseDots(CXDrawerView* view);
	virtual void setColor(COLORREF color);
	virtual void setFill() {}
	virtual Figure* copy() { 
		return NULL; 
	}
	~Figure();
};

