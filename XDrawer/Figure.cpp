#include "stdafx.h"
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)
Figure::Figure()
	:CObject()
{
}
void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
}
Figure::~Figure()
{
}
