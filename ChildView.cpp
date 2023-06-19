
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
	m_color = RGB(255,0,0);
	isSelected = false;
	selectedIdx = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CChildView::OnColorBlue)
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

	for (auto shape : m_shapes) {
		shape.draw(dc);
	}
	
}



#include "CDialog2021.h"
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	p1 = CPoint(point);
	p2 = CPoint(point);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	for (int i=0;i<m_shapes.size();i++) {
		if (m_shapes[i].isClicked(point)) {
			isSelected = true;
			selectedIdx = i;
			m_shapes[selectedIdx].m_color = RGB(0,255,255);
			break;
		}
	}
	if (!isSelected) {
		CMyRectangle shape = CMyRectangle(m_color);
		shape.doMouseDown(point);
		m_shapes.push_back(shape);
	}

}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags == MK_LBUTTON) {
		int dx = p2.x-p1.x;
		int dy = p2.y-p1.y;
		p1 = p2;
		p2 = CPoint(point);
		if (isSelected) {
			m_shapes[selectedIdx].p1.x += dx;
			m_shapes[selectedIdx].p2.x += dx;
			m_shapes[selectedIdx].p1.y += dy;
			m_shapes[selectedIdx].p2.y += dy;

			m_shapes[selectedIdx].lt.x += dx;
			m_shapes[selectedIdx].rb.x += dx;
			m_shapes[selectedIdx].lt.y += dy;
			m_shapes[selectedIdx].rb.y += dy;
			Invalidate();
		}
		else {
			m_shapes.back().doMouseUp(point);
			Invalidate();

		}
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (isSelected) {
		isSelected = false;
		m_shapes[selectedIdx].m_color = m_color; 
		Invalidate();
	}
	else {
		m_shapes.back().doMouseUp(point);
		Invalidate();

	}
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}


void CChildView::OnColorRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(255, 0, 0);

}


void CChildView::OnColorGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(0, 255, 0);

}


void CChildView::OnColorBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(0, 0, 255);

}
