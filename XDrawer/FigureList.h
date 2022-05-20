#pragma once
#include "afxcoll.h"

class Figure;

class FigureList :
	public CObList
{
	DECLARE_SERIAL(FigureList)
public:
	FigureList();
	~FigureList();

	Figure  *FigureList::GetNext(POSITION &pos);
};

