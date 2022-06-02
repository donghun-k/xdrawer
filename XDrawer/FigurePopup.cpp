#include "stdafx.h"
#include "resource.h"

#include "FigurePopup.h"
#include "XDrawerView.h"


FigurePopup::FigurePopup(CXDrawerView *view, CString title)
{	
	viewPtr = view;
	popupPtr = new CMenu();
	popupPtr->CreatePopupMenu();
	popupPtr->AppendMenuW(MF_STRING, 0, title);
	popupPtr->AppendMenuW(MF_SEPARATOR);
	popupPtr->AppendMenuW(MF_STRING, ID_DELETE_FIGURE, _T("Áö¿ì±â"));
}


FigurePopup::~FigurePopup()
{
	if (popupPtr != NULL) delete popupPtr;
}

void FigurePopup::popup(int x, int y) {
	popupPtr->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, x, y, viewPtr, NULL);
}