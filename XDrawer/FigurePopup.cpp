#include "stdafx.h"
#include "resource.h"

#include "FigurePopup.h"


FigurePopup::FigurePopup(CXDrawerView *view, CString title)
	: Popup(view, title)
{	
	popupPtr->AppendMenuW(MF_STRING, ID_DELETE_FIGURE, _T("Áö¿ì±â"));
}

FigurePopup::~FigurePopup()
{
	if (popupPtr != NULL) delete popupPtr;
}
