#include "stdafx.h"

#include "Popup.h"
#include "XDrawerView.h"

Popup::Popup(CXDrawerView *view, CString title)
{	
	viewPtr = view;
	popupPtr = new CMenu();
	popupPtr->CreatePopupMenu();
	popupPtr->AppendMenuW(MF_STRING, 0, title);	
	popupPtr->AppendMenuW(MF_SEPARATOR);
}
Popup::~Popup()
{
}
void Popup::popup(int x, int y) {
	popupPtr->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, x, y, viewPtr, NULL);
}
