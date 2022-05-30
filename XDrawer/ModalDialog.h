#pragma once


// ModalDialog 대화 상자입니다.
class CXDrawerView;

class ModalDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ModalDialog)

public:
	ModalDialog(CXDrawerView *const pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ModalDialog();
	CXDrawerView *m_pView;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MODAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_x1;
	int m_y1;
	CString m_x2;
	CString m_y2;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString figure;
};
