
// XDrawerView.cpp : CXDrawerView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "XDrawer.h"
#endif

#include "ModalDialog.h"
#include "MainPopup.h"
#include "FigurePopup.h"

#include "XDrawerDoc.h"
#include "XDrawerView.h"

#include "X.h"
#include "Bubble.h"
#include "Box.h"
#include "Line.h"
#include "Circle.h"
#include "Diamond.h"
#include "Kite1.h"
#include "Kite2.h"
#include "Kite3.h"
#include "UFO.h"

#include "Figure.h"
#include "FigureList.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DEFAULT		(0)
#define DRAWING		(1)
#define MOVING		(2)

#define DRAW_X			(1)
#define DRAW_BUBBLE		(2)
#define DRAW_BOX		(3)
#define DRAW_LINE		(4)
#define DRAW_CIRCLE		(5)
#define DRAW_DIAMOND	(6)
#define DRAW_KITE1		(7)
#define DRAW_KITE2		(8)
#define DRAW_KITE3		(9)
#define DRAW_UFO		(10)

// CXDrawerView

IMPLEMENT_DYNCREATE(CXDrawerView, CView)

BEGIN_MESSAGE_MAP(CXDrawerView, CView)
	ON_COMMAND(ID_DELETE_FIGURE, &CXDrawerView::OnDeleteFigure)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CXDrawerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_OBJECT_BOX, &CXDrawerView::OnObjectBox)
	ON_COMMAND(ID_OBJECT_LINE, &CXDrawerView::OnObjectLine)
	ON_COMMAND(ID_OBJECT_CIRCLE, &CXDrawerView::OnObjectCircle)
	ON_COMMAND(ID_OBJECT_DIAMOND, &CXDrawerView::OnObjectDiamond)
	ON_COMMAND(ID_OBJECT_X, &CXDrawerView::OnObjectX)
	ON_COMMAND(ID_OBJECT_BUBBLE, &CXDrawerView::OnObjectBubble)
	ON_COMMAND(ID_MODAL_DIALOG, &CXDrawerView::OnModalDialog)
	ON_COMMAND(ID_MODALESS_DIALOG, &CXDrawerView::OnModalessDialog)
	ON_COMMAND(ID_OBJECT_KITE1, &CXDrawerView::OnObjectKite1)
	ON_COMMAND(ID_OBJECT_KITE2, &CXDrawerView::OnObjectKite2)
	ON_COMMAND(ID_OBJECT_KITE3, &CXDrawerView::OnObjectKite3)
	ON_COMMAND(ID_OBJECT_UFO, &CXDrawerView::OnObjectUfo)
	ON_COMMAND(ID_BLACK_COLOR, OnBlackColor)
	ON_COMMAND(ID_RED_COLOR, OnRedColor)
	ON_COMMAND(ID_GREEN_COLOR, OnGreenColor)
	ON_COMMAND(ID_BLUE_COLOR, OnBlueColor)
	ON_COMMAND(ID_FILL_FIGURE, OnFillFigure)
END_MESSAGE_MAP()

// CXDrawerView 생성/소멸

CXDrawerView::CXDrawerView()
{
	//::MessageBox(NULL, _T("CXDrawerView"), _T("CXDrawerView"), 0);
	// TODO: 여기에 생성 코드를 추가합니다.
	currentFigure = NULL;
	whatToDraw = 0;	
	actionMode = DEFAULT;
	currentX = 0;
	currentY = 0;
	pDlg = new ModalDialog(this);	
	mainPopup = new MainPopup(this, _T("그림들"));
	xPopup = new FigurePopup(this, _T("엑스"));
	bubblePopup = new FigurePopup(this, _T("버블"), TRUE);
	linePopup = new FigurePopup(this, _T("선"));
	boxPopup = new FigurePopup(this, _T("사각형"), TRUE);
	circlePopup = new FigurePopup(this, _T("원"), TRUE);
	diamondPopup = new FigurePopup(this, _T("다이아몬드"), TRUE);
	kite1Popup = new FigurePopup(this, _T("연1"));
	kite2Popup = new FigurePopup(this, _T("연2"));
	kite3Popup = new FigurePopup(this, _T("연3"));
	ufoPopup = new FigurePopup(this, _T("UFO"), TRUE);
}

CXDrawerView::~CXDrawerView()
{
	if (pDlg != NULL) delete pDlg;
	if (mainPopup != NULL) delete mainPopup;
	if (xPopup != NULL) delete xPopup;
	if (bubblePopup != NULL) delete bubblePopup;
	if (linePopup != NULL) delete linePopup;
	if (boxPopup != NULL) delete boxPopup;
	if (circlePopup != NULL) delete circlePopup;
	if (diamondPopup != NULL) delete diamondPopup;
	if (kite1Popup != NULL) delete kite1Popup;
	if (kite2Popup != NULL) delete kite2Popup;
	if (kite3Popup != NULL) delete kite3Popup;
	if (ufoPopup != NULL) delete ufoPopup;
}

BOOL CXDrawerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CXDrawerView 그리기

void CXDrawerView::OnDraw(CDC* pDC)
{
	CXDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	/*
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Ellipse(100, 100, 200, 200);

	CPen pen(PS_SOLID, 3, RGB(0, 0, 255));
	CPen *oldPen = pDC->SelectObject(&pen);	
	
	pDC->Rectangle(100, 100, 200, 200);

	pDC->SelectObject(oldPen);

	pDC->MoveTo(300, 300);
	pDC->LineTo(100, 100);

	CPen pen2(PS_SOLID, 1, RGB(0, 0, 0));
	pDC->SelectObject(&pen2);
	pDC->MoveTo(300, 300);
	pDC->LineTo(500, 500);

	CRect rect(50, 50, 100, 100);
	CBrush br(RGB(255, 0, 0));
	pDC->FillRect(&rect, &br);
	*/
	CGdiObject *oldBrush =pDC->SelectStockObject(NULL_BRUSH);

	FigureList *list = pDoc->getFigures();
	POSITION pos = list->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = list->GetNext(pos);
		ptr->draw(pDC);
	}
	pDC->SelectObject(oldBrush);
	if (currentFigure != NULL && actionMode == DEFAULT)
		currentFigure->drawDots(pDC);
}


// CXDrawerView 인쇄


void CXDrawerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CXDrawerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CXDrawerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CXDrawerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CXDrawerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CXDrawerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CPoint testPoint(point);
	ScreenToClient(&testPoint);

	currentFigure = NULL;

	CXDrawerDoc* pDoc = GetDocument();

	FigureList *list = pDoc->getFigures();
	POSITION pos = list->GetHeadPosition();
	while (pos != NULL) {
		Figure *ptr = list->GetNext(pos);
		//if (ptr->region->PtInRegion(testPoint.x, testPoint.y)) {
		if (ptr->ptInRgn(testPoint.x, testPoint.y)) {
			currentFigure = ptr;
			break;
		}
	}
	if (currentFigure == NULL) {
		mainPopup->popup(point.x, point.y);
	} else {
		currentFigure->popup(point.x, point.y);
	}
}


// CXDrawerView 진단

#ifdef _DEBUG
void CXDrawerView::AssertValid() const
{
	CView::AssertValid();
}

void CXDrawerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXDrawerDoc* CXDrawerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXDrawerDoc)));
	return (CXDrawerDoc*)m_pDocument;
}
#endif //_DEBUG


// CXDrawerView 메시지 처리기


void CXDrawerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC *pDC = GetDC();

	if (whatToDraw == 0) {
		if (currentFigure != NULL) {
			if (currentFigure->ptInRgn(point.x, point.y)) {
				currentX = point.x;
				currentY = point.y;
				actionMode = MOVING;
				//GetDocument()->removeFigure(currentFigure);
				GetDocument()->SetModifiedFlag();
				CView::OnLButtonDown(nFlags, point);
			}
			currentFigure = NULL;
		}				
		FigureList *figures = GetDocument()->getFigures();
		POSITION pos = figures->GetHeadPosition();
		while(pos != NULL) {
			Figure *ptr = figures->GetNext(pos);
			if (ptr->ptInRgn(point.x,point.y)) {
				currentFigure = ptr;
				break;
			}
		}
		Invalidate();
		CView::OnLButtonDown(nFlags, point);
		return;
	} else if(whatToDraw == DRAW_X) {
		currentFigure = new X(point.x, point.y);
		currentFigure->setPopup(xPopup);
	} else if(whatToDraw == DRAW_BUBBLE) {
		currentFigure = new Bubble(point.x, point.y);
		currentFigure->setPopup(bubblePopup);
	} else if(whatToDraw == DRAW_BOX) {
		currentFigure = new Box(point.x, point.y);	
		currentFigure->setPopup(boxPopup);
	} else if(whatToDraw == DRAW_LINE) {
		currentFigure = new Line(point.x, point.y);	
		currentFigure->setPopup(linePopup);
	} else if(whatToDraw == DRAW_CIRCLE) {
		currentFigure = new Circle(point.x, point.y);	
		currentFigure->setPopup(circlePopup);
	} else if(whatToDraw == DRAW_DIAMOND) {
		currentFigure = new Diamond(point.x, point.y);	
		currentFigure->setPopup(diamondPopup);
	} else if(whatToDraw == DRAW_KITE1) {
		currentFigure = new Kite1(point.x, point.y);	
		currentFigure->setPopup(kite1Popup);
	} else if(whatToDraw == DRAW_KITE2) {
		currentFigure = new Kite2(point.x, point.y);	
		currentFigure->setPopup(kite2Popup);
	} else if(whatToDraw == DRAW_KITE3) {
		currentFigure = new Kite3(point.x, point.y);	
		currentFigure->setPopup(kite3Popup);
	} else if(whatToDraw == DRAW_UFO) {
		currentFigure = new UFO(point.x, point.y);	
		currentFigure->setPopup(ufoPopup);
	}
	whatToDraw = 0;
	actionMode = DRAWING;
	currentFigure->draw(pDC);
	
	CView::OnLButtonDown(nFlags, point);
}


void CXDrawerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (currentFigure == NULL || actionMode == DEFAULT) {
		CView::OnLButtonUp(nFlags, point);
		return;
	}
	CDC *pDC = GetDC();
	if (actionMode == DRAWING) {
		CDC *pDC = GetDC();
		CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH);

		currentFigure->setXY2(point.x, point.y);
		currentFigure->draw(pDC);

		pDC->SelectObject(oldBrush);

		CXDrawerDoc *pDoc = GetDocument();		

		pDoc->add(currentFigure);
		pDoc->SetModifiedFlag(TRUE);
	}
	currentFigure->makeRegion();
	actionMode = DEFAULT;
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CXDrawerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(currentFigure != NULL)
	{
		CDC *pDC = GetDC();

		if (actionMode == DRAWING) {
			int oldMode = pDC->SetROP2(R2_NOTXORPEN);
			CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH);

			currentFigure->draw(pDC);
			currentFigure->setXY2(point.x, point.y);
			currentFigure->draw(pDC);

			pDC->SelectObject(oldBrush);
			pDC->SetROP2(oldMode);
		} else if (actionMode == MOVING) {
			int oldMode = pDC->SetROP2(R2_NOTXORPEN);
			currentFigure->move(pDC,point.x-currentX,point.y-currentY);
			pDC->SetROP2(oldMode);
			currentX = point.x;
			currentY = point.y;
		}		
	}
	CView::OnMouseMove(nFlags, point);
}


void CXDrawerView::OnObjectBox()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_BOX;
}


void CXDrawerView::OnObjectLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_LINE;
}


void CXDrawerView::OnObjectCircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_CIRCLE;
}


void CXDrawerView::OnObjectDiamond()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_DIAMOND;
}


void CXDrawerView::OnObjectX()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_X;
}


void CXDrawerView::OnObjectBubble()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_BUBBLE;
}


void CXDrawerView::OnModalDialog()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ModalDialog aDlg(this);
	aDlg.DoModal();
}


void CXDrawerView::OnModalessDialog()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.	
	pDlg->ShowWindow(SW_SHOW);
}


BOOL CXDrawerView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	pDlg->Create(ModalDialog::IDD);
	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CXDrawerView::OnDeleteFigure() {
	if (currentFigure == NULL) return;
	GetDocument()->removeFigure(currentFigure);
	delete currentFigure;
	currentFigure = NULL;
	Invalidate();
}

void CXDrawerView::OnObjectKite1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_KITE1;
}


void CXDrawerView::OnObjectKite2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_KITE2;
}


void CXDrawerView::OnObjectKite3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_KITE3;
}


void CXDrawerView::OnObjectUfo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_UFO;
}
void CXDrawerView::setColorForSelectedFigure(COLORREF color)
{
	if (currentFigure == NULL) return;
	currentFigure->setColor(color);
	GetDocument()->SetModifiedFlag();
	Invalidate();
}

void CXDrawerView::OnBlackColor()
{
	setColorForSelectedFigure(BLACK_COLOR);
}

void CXDrawerView::OnRedColor()
{
	setColorForSelectedFigure(RED_COLOR);
}

void CXDrawerView::OnGreenColor()
{
	setColorForSelectedFigure(GREEN_COLOR);
}

void CXDrawerView::OnBlueColor()
{
	setColorForSelectedFigure(BLUE_COLOR);
}
void CXDrawerView::OnFillFigure()
{
	if (currentFigure == NULL) return;
	currentFigure->setFill();
	GetDocument()->SetModifiedFlag();
	Invalidate();
}