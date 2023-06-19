#pragma once


// CDialog2021 대화 상자

class CDialog2021 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog2021)

public:
	CDialog2021(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDialog2021();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CButton m_okBtn;
	CButton m_cancelBtn;
	CString m_edit;
};
