#include "stdafx.h"
#include "CompositeFigure.h"

#include "FigureList.h"

IMPLEMENT_SERIAL(CompositeFigure, Figure, 1)

CompositeFigure::CompositeFigure()
	: Figure()
{
	parts = new FigureList();
}


CompositeFigure::~CompositeFigure()
{
	delete parts;
}

void CompositeFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);
	if (ar.IsStoring()) {
		ar << parts;
	} else {
		ar >> parts;
	}
}
void CompositeFigure::draw(CDC* pDC)
{
	POSITION pos = parts->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = parts->GetNext(pos);
		ptr->draw(pDC);
	}
}
void CompositeFigure::makeRegion()
{
	POSITION pos = parts->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = parts->GetNext(pos);
		ptr->makeRegion();
	}
}
BOOL CompositeFigure::ptInRgn(int x, int y)
{
	POSITION pos = parts->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = parts->GetNext(pos);
		if (ptr->ptInRgn(x, y) == TRUE) return TRUE;
	}
	return FALSE;
}
void CompositeFigure::move(int dx,int dy)
{
	POSITION pos = parts->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = parts->GetNext(pos);
		ptr->move(dx,dy);
	}
}
void CompositeFigure::setColor(COLORREF color)
{
	POSITION pos = parts->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = parts->GetNext(pos);
		ptr->setColor(color);
	}
}
