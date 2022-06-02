#pragma once
#include "Popup.h"

//class CXDrawerView;
class FigurePopup
	:public Popup
{	
public:
	FigurePopup(CXDrawerView *view, CString title);
	~FigurePopup();
};

