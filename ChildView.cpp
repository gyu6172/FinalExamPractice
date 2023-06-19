
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "FinalExamPractice.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	dx = 0;
	dy = 0;
	lt = CPoint(100,100);
	rb = CPoint(150,150);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{

	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CRect rect;
	GetClientRect(rect);

	CBrush brush(RGB(0,0,0));
	dc.SelectObject(brush);
	dc.Rectangle(lt.x, lt.y, rb.x, rb.y);

	
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetTimer(201, 30, NULL);
	if (nChar == VK_LEFT) {
		dx = -10;
		dy=0;
	}
	if (nChar == VK_RIGHT) {
		dx = 10;
		dy = 0;

	}
	if (nChar == VK_UP) {
		dx=0;
		dy = -10;
	}
	if (nChar == VK_DOWN) {
		dx=0;
		dy = 10;
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 201) {
		CRect rect;
		GetClientRect(rect);
		lt.x += dx;
		lt.y += dy;
		rb.x += dx;
		rb.y += dy;

		if (rb.x >= rect.Width()) {
			rb.x = rect.Width();
			dx *=- 1;
		}
		if (lt.x <= 0) {
			lt.x = 0;
			dx *= -1;
		}
		if (rb.y >= rect.Height()) {
			rb.y = rect.Height();
			dy *= -1;
		}
		if (lt.y <= 0) {
			lt.y = 0;
			dy *= -1;
		}


		Invalidate();
	}


	CWnd::OnTimer(nIDEvent);
}
