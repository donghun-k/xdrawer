#include "stdafx.h"
#include "resource.h"

#include "MainPopup.h"
#include "XDrawerView.h"


MainPopup::MainPopup(CXDrawerView *view, CString title)
{	
	viewPtr = view;
	popupPtr = new CMenu();
	popupPtr->CreatePopupMenu();
	popupPtr->AppendMenuW(MF_STRING, 0, title);
	popupPtr->AppendMenuW(MF_SEPARATOR);
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_X, _T("엑스"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_BUBBLE, _T("버블"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_BOX, _T("사각형"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_LINE, _T("선"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_CIRCLE, _T("원"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_DIAMOND, _T("다이아몬드"));
}


MainPopup::~MainPopup()
{
	if (popupPtr != NULL) delete popupPtr;
}

void MainPopup::popup(int x, int y) {
	popupPtr->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, x, y, viewPtr, NULL);
}
