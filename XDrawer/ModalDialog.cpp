// ModalDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "XDrawer.h"
#include "ModalDialog.h"
#include "afxdialogex.h"

#include "XDrawerView.h"
#include "XDrawerDoc.h"

#include "Box.h"
#include "X.h"
#include "Bubble.h"
#include "Circle.h"
#include "Line.h"
#include "Diamond.h"
#include "Kite1.h"
#include "Kite2.h"
#include "Kite3.h"
#include "UFO.h"


// ModalDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(ModalDialog, CDialogEx)

ModalDialog::ModalDialog(CXDrawerView *const pView, CWnd* pParent /*=NULL*/)
	: CDialogEx(ModalDialog::IDD, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_x2(_T(""))
	, m_y2(_T(""))
	, m_pView(pView)
{
}

ModalDialog::~ModalDialog()
{
}

void ModalDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_x1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_y1);
	DDX_Text(pDX, IDC_EDIT_X2, m_x2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_y2);
	DDX_Control(pDX, IDC_COMBO_FIGURE, m_combo);
}


BEGIN_MESSAGE_MAP(ModalDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &ModalDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ModalDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// ModalDialog 메시지 처리기입니다.


void ModalDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
	UpdateData();
	int x1 = m_x1;
	int y1 = m_y1;

	int x2 = _ttoi(m_x2);
	int y2 = _ttoi(m_y2);

	CString name;
	m_combo.GetWindowTextW(name);
	Figure *fig = NULL;

	if (name == _T("엑스")) {
		fig = new X(x1, y1);
		fig->setPopup(m_pView->xPopup);
	} else if (name == _T("버블")) {
		fig = new Bubble(x1, y1);
		fig->setPopup(m_pView->bubblePopup);
	} else if (name == _T("사각형")) {
		fig = new Box(x1, y1, x2, y2);
		fig->setPopup(m_pView->boxPopup);
	} else if (name == _T("선")) {
		fig = new Line(x1, y1, x2, y2);
		fig->setPopup(m_pView->linePopup);
	} else if (name == _T("원")) {
		fig = new Circle(x1, y1, x2, y2);
		fig->setPopup(m_pView->circlePopup);
	} else if (name == _T("다이아몬드")) {
		fig = new Diamond(x1, y1, x2, y2);
		fig->setPopup(m_pView->diamondPopup);
	} else if (name == _T("연1")) {
		fig = new Kite1(x1, y1, x2, y2);
		fig->setPopup(m_pView->kite1Popup);
	} else if (name == _T("연2")) {
		fig = new Kite2(x1, y1, x2, y2);
		fig->setPopup(m_pView->kite2Popup);
	} else if (name == _T("연3")) {
		fig = new Kite3(x1, y1, x2, y2);
		fig->setPopup(m_pView->kite3Popup);
	} else if (name == _T("UFO")) {
		fig = new UFO(x1, y1, x2, y2);
		fig->setPopup(m_pView->ufoPopup);
	}
	fig->makeRegion();
	m_pView->GetDocument()->add(fig);
	m_pView->Invalidate();

	m_x1 = 0;
	m_y1 = 0;
	m_x2 = _T("0");
	m_y2 = _T("0");

	UpdateData(FALSE);
}


void ModalDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


BOOL ModalDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_combo.AddString(_T("엑스"));
	m_combo.AddString(_T("버블"));
	m_combo.AddString(_T("사각형"));
	m_combo.AddString(_T("선"));
	m_combo.AddString(_T("원"));
	m_combo.AddString(_T("다이아몬드"));
	m_combo.AddString(_T("연1"));
	m_combo.AddString(_T("연2"));
	m_combo.AddString(_T("연3"));
	m_combo.AddString(_T("UFO"));

	m_combo.SetCurSel(2);

	return TRUE;  // return TRUE unless you set the focus to a control
}
