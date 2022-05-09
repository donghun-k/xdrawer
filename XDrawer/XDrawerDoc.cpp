
// XDrawerDoc.cpp : CXDrawerDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "XDrawer.h"
#endif

#include "XDrawerDoc.h"
#include "Box.h"
#include "Line.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CXDrawerDoc

IMPLEMENT_DYNCREATE(CXDrawerDoc, CDocument)

BEGIN_MESSAGE_MAP(CXDrawerDoc, CDocument)
END_MESSAGE_MAP()


// CXDrawerDoc 생성/소멸

CXDrawerDoc::CXDrawerDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	for(int i=0; i<100; i++)
	{
		boxes[i] = NULL;
		lines[i] = NULL;
		circles[i] = NULL;
	}
	nBox = 0;
	nLine = 0;
	nCircle = 0;
}

CXDrawerDoc::~CXDrawerDoc()
{
}

BOOL CXDrawerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CXDrawerDoc serialization

void CXDrawerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CXDrawerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CXDrawerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CXDrawerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CXDrawerDoc 진단

#ifdef _DEBUG
void CXDrawerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CXDrawerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CXDrawerDoc 명령

void CXDrawerDoc::add(Box *pBox)
{
	boxes[nBox++] = pBox;
}
void CXDrawerDoc::add(Line *pLine)
{
	lines[nLine++] = pLine;
}
void CXDrawerDoc::add(Circle *pCircle)
{
	circles[nCircle++] = pCircle;
}
