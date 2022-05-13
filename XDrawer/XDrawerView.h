
// XDrawerView.h : CXDrawerView 클래스의 인터페이스
//

#pragma once

class Figure;


class CXDrawerView : public CView
{
protected: // serialization에서만 만들어집니다.
	CXDrawerView();
	DECLARE_DYNCREATE(CXDrawerView)

private:
	int whatToDraw;
// 특성입니다.
public:
	CXDrawerDoc* GetDocument() const;

// 작업입니다.
public:
	Figure *currentFigure;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CXDrawerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnObjectBox();
	afx_msg void OnObjectLine();
	afx_msg void OnObjectCircle();
	afx_msg void OnObjectDiamond();
};

#ifndef _DEBUG  // XDrawerView.cpp의 디버그 버전
inline CXDrawerDoc* CXDrawerView::GetDocument() const
   { return reinterpret_cast<CXDrawerDoc*>(m_pDocument); }
#endif

