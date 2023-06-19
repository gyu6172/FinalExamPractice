
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
	m_rect1 = CRect(100, 100, 600, 300);
	m_rect2 = CRect(100, 400, 600, 600);
	m_str1 = _T("세종대학교");
	m_str2 = _T("소프트웨어");
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
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
	
	dc.Rectangle(m_rect1);
	dc.Rectangle(m_rect2);
	CFont font;
	font.CreatePointFont(100, _T("Arial"));
	dc.SelectObject(font);
	dc.DrawText(m_str1, CRect(m_rect1.left+20, m_rect1.top+20, m_rect1.right, m_rect1.bottom), DT_VCENTER);
	dc.DrawText(m_str2, CRect(m_rect2.left + 20, m_rect2.top + 20, m_rect2.right, m_rect2.bottom), DT_VCENTER);

	
}



#include "CDialog2021.h"
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((m_rect1.left <= point.x && point.x <= m_rect1.right) &&
	(m_rect1.top <= point.y && point.y <= m_rect1.bottom)) {
		CDialog2021 dlg;
		dlg.m_edit = m_str1;

		if (dlg.DoModal() == IDOK) {
			m_str1 = dlg.m_edit;
			Invalidate();
		}
	}

	if ((m_rect2.left <= point.x && point.x <= m_rect2.right) &&
		(m_rect2.top <= point.y && point.y <= m_rect2.bottom)) {
		CDialog2021 dlg;
		dlg.m_edit = m_str2;

		if (dlg.DoModal() == IDOK) {
			m_str2 = dlg.m_edit;
			Invalidate();
		}
	}

	CWnd::OnLButtonDown(nFlags, point);
}
