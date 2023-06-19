// CDialog2021.cpp: 구현 파일
//

#include "pch.h"
#include "FinalExamPractice.h"
#include "CDialog2021.h"
#include "afxdialogex.h"


// CDialog2021 대화 상자

IMPLEMENT_DYNAMIC(CDialog2021, CDialogEx)

CDialog2021::CDialog2021(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_edit(_T(""))
{

}

CDialog2021::~CDialog2021()
{
}

void CDialog2021::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_okBtn);
	DDX_Control(pDX, IDCANCEL, m_cancelBtn);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CDialog2021, CDialogEx)
END_MESSAGE_MAP()


// CDialog2021 메시지 처리기
