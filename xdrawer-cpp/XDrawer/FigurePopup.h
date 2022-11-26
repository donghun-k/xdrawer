#pragma once
#include "Popup.h"

//class CXDrawerView;
class FigurePopup
	:public Popup
{	
	CMenu *colorPopup;
public:
	FigurePopup(CXDrawerView *view, CString title, BOOL fillButtonFlag=FALSE);
	~FigurePopup();
};

