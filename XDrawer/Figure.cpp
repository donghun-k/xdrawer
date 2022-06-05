#include "stdafx.h"
#include "Figure.h"
#include "FigurePopup.h"
#include "XDrawerView.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)
Figure::Figure()
	:CObject()
{
	_color = 0;
	region = NULL;
	dotedFlag = FALSE;
	popupPtr = NULL;
}
void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << _color;
	} else {
		ar >> _color;
	}
}

void Figure::popup(int x, int y)
{
	popupPtr->popup(x, y);
}
Figure::~Figure()
{
	if (region != NULL) delete region;
}
BOOL Figure::ptInRgn(int x, int y) 
{
	if (region == NULL) return FALSE;
	return region->PtInRegion(x, y);
}
void Figure::move(CDC* pDC,int dx,int dy) 
{
	draw(pDC);
	move(dx,dy);
	draw(pDC);
}
void Figure::eraseDots(CXDrawerView* view) 
{ 
	dotedFlag = FALSE; 
	view->Invalidate();
}
void Figure::setColor(COLORREF color)
{
	_color = color;
}