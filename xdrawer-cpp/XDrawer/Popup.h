#pragma once

class CXDrawerView;

class Popup
{
protected:
	CMenu *popupPtr;
	CXDrawerView *viewPtr;
public:
	Popup(CXDrawerView *view, CString title);
	void popup(int x, int y);
	~Popup();	
};

