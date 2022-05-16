#pragma once
#include "afxcoll.h"

class Figure;

class FigureList :
	public CObList
{
public:
	FigureList();
	~FigureList();

	Figure  *FigureList::GetNext(POSITION &pos);
};

