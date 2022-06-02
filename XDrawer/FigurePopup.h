#pragma once

class CXDrawerView;
class FigurePopup
{
	CMenu *popupPtr;
	CXDrawerView *viewPtr;
public:
	FigurePopup(CXDrawerView *view, CString title);
	~FigurePopup();

	void popup(int x, int y);
};

