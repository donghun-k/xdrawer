#include "stdafx.h"
#include "Figure.h"
#include "FigureList.h"

IMPLEMENT_SERIAL(FigureList, CObList, 1)
FigureList::FigureList()
	:CObList()
{
}

FigureList::~FigureList()
{
	RemoveAllFigures();
}

Figure *FigureList::GetNext(POSITION &pos)
{
	return (Figure *)CObList::GetNext(pos);
}

void FigureList::RemoveAllFigures()
{
	POSITION pos = GetHeadPosition();
	while (pos != NULL) {
		Figure* fig = (Figure*)GetNext(pos);
		delete fig;
	}
	RemoveAll();
}

void FigureList::removeFigure(Figure *ptr) {
	POSITION found = NULL;
	POSITION pos = GetHeadPosition();
	while (pos != NULL) {
		found = pos;
		Figure* fig = (Figure*)GetNext(pos);
		if (ptr == fig) {
			break;
		}
	}
	RemoveAt(found);
}
