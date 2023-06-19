
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
	m_color = RGB(0,0,0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_BN_CLICKED(201, OnRedBtnClicked)
	ON_BN_CLICKED(202, OnGreenBtnClicked)
	ON_BN_CLICKED(203, OnBlueBtnClicked)
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

	CBrush brush(m_color);
	dc.SelectObject(brush);
	dc.Rectangle(200,200, 500,500);

	
}

void CChildView::OnRedBtnClicked()
{
	m_color = RGB(255,0,0);
	Invalidate();
}

void CChildView::OnGreenBtnClicked()
{
	m_color = RGB(0, 255, 0);
	Invalidate();
}

void CChildView::OnBlueBtnClicked()
{
	m_color = RGB(0, 0, 255);
	Invalidate();
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	m_red.Create(_T("Red"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, CRect(100,100, 180,180), this, 201);
	m_green.Create(_T("Green"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, CRect(200,100, 280,180), this, 202);
	m_blue.Create(_T("Blue"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, CRect(300,100, 380,180), this, 203);

	return 0;
}
