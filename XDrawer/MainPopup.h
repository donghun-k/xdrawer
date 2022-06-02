#pragma once

class CXDrawerView;
class MainPopup
{
	CMenu *popupPtr;
	CXDrawerView *viewPtr;
public:
	MainPopup(CXDrawerView *view, CString title);
	~MainPopup();

	void popup(int x, int y);
};

