#include "stdafx.h"
#include "resource.h"

#include "FigurePopup.h"


FigurePopup::FigurePopup(CXDrawerView *view, CString title, BOOL fillButtonFlag)
	: Popup(view, title)
{	
	popupPtr->AppendMenuW(MF_STRING, ID_DELETE_FIGURE, _T("지우기"));
	popupPtr->AppendMenu(MF_STRING,ID_COPY_FIGURE, _T("복사하기"));

	colorPopup = new CMenu();
	colorPopup->CreatePopupMenu();
	colorPopup->AppendMenu(MF_STRING, ID_BLACK_COLOR, _T("검정"));
	colorPopup->AppendMenu(MF_STRING, ID_RED_COLOR, _T("빨강"));
	colorPopup->AppendMenu(MF_STRING, ID_GREEN_COLOR, _T("초록"));
	colorPopup->AppendMenu(MF_STRING, ID_BLUE_COLOR, _T("파랑"));
	popupPtr->AppendMenu(MF_POPUP, (unsigned int)colorPopup->m_hMenu, _T("색 정하기"));
	if (fillButtonFlag == TRUE)
		popupPtr->AppendMenu(MF_STRING,ID_FILL_FIGURE, _T("채우기"));
}

FigurePopup::~FigurePopup()
{
	if (popupPtr != NULL) delete popupPtr;
	if (colorPopup != NULL) delete colorPopup;
}
