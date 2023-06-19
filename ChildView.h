
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창
#include <vector>
#include "CMyShape.h"
class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();


// 특성입니다.
public:
	CButton m_red;
	CButton m_blue;
	CButton m_green;
	COLORREF m_color;
	// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRedBtnClicked();
	afx_msg void OnGreenBtnClicked();
	afx_msg void OnBlueBtnClicked();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

