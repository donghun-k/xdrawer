#include "stdafx.h"
#include "resource.h"

#include "MainPopup.h"


MainPopup::MainPopup(CXDrawerView *view, CString title)
	: Popup(view, title)
{	
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_X, _T("엑스"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_BUBBLE, _T("버블"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_BOX, _T("사각형"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_LINE, _T("선"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_CIRCLE, _T("원"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_DIAMOND, _T("다이아몬드"));
	popupPtr->AppendMenuW(MF_STRING, ID_OBJECT_KITE1, _T("연1"));
}


MainPopup::~MainPopup()
{
	if (popupPtr != NULL) delete popupPtr;
}

