﻿
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창
#include <vector>
#include "CMyShape.h"
#include "CMyShape2022_2.h"
#include "CMyRectangle.h"
class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();
	std::vector<CMyRectangle> m_shapes;
	COLORREF m_color;
	bool isSelected;
	int selectedIdx;
	CPoint p1,p2;

// 특성입니다.
public:

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
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
};

