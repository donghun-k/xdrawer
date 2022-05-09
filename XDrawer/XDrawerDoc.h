
// XDrawerDoc.h : CXDrawerDoc 클래스의 인터페이스
//


#pragma once

class Box;
class Line;
class Circle;

class CXDrawerDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CXDrawerDoc();
	DECLARE_DYNCREATE(CXDrawerDoc)

	Box *boxes[100];
	int nBox;
	Line *lines[100];
	int nLine;
	Circle *circles[100];
	int nCircle;
// 특성입니다.
public:	

// 작업입니다.
public:
	void add(Box *pBox);
	void add(Line *pLine);
	void add(Circle *pCircle);
	inline int boxCount() { return nBox; }
	inline Box *getBox(int i) { return boxes[i]; }
	inline int lineCount() { return nLine; }
	inline Line *getLine(int i) { return lines[i]; }
	inline int circleCount() { return nCircle; }
	inline Circle *getCircle(int i) { return circles[i]; }
// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CXDrawerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
