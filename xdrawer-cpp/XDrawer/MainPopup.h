#pragma once
#include "Popup.h"

//class CXDrawerView;
class MainPopup
	:public Popup
{
public:
	MainPopup(CXDrawerView *view, CString title);
	~MainPopup();
};

