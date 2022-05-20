#include "stdafx.h"
#include "FigureList.h"

IMPLEMENT_SERIAL(FigureList, CObList, 1)
FigureList::FigureList()
	:CObList()
{
}

FigureList::~FigureList()
{
}

Figure *FigureList::GetNext(POSITION &pos)
{
	return (Figure *)CObList::GetNext(pos);
}
