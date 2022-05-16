#include "stdafx.h"
#include "FigureList.h"


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
