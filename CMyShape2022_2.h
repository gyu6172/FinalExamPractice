#pragma once
class CMyShape2022_2
{
public:
	CPoint p1,p2;
	CPoint lt,rb;
	CString m_str;

	CMyShape2022_2();
	void draw(CDC& dc);
	void doMouseDown(CPoint p);
	void doMouseUp(CPoint p);
};

