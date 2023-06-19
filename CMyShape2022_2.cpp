#include "pch.h"
#include "CMyShape2022_2.h"

CMyShape2022_2::CMyShape2022_2()
{
	lt = CPoint(0,0);
	rb = CPoint(0,0);
	m_str = _T("");
}

void CMyShape2022_2::draw(CDC &dc)
{
	dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
	dc.TextOutW(lt.x, lt.y, m_str);
}

void CMyShape2022_2::doMouseDown(CPoint p)
{
	p1 = CPoint(p);
	p2 = CPoint(p);
}

void CMyShape2022_2::doMouseUp(CPoint p)
{
	p2 = CPoint(p);

	lt.x = min(p1.x, p2.x);
	rb.x = max(p1.x, p2.x);
	lt.y = min(p1.y, p2.y);
	rb.y = max(p1.y, p2.y);
}
