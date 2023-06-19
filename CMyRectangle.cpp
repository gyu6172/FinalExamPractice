#include "pch.h"
#include "CMyRectangle.h"

CMyRectangle::CMyRectangle()
{
	m_color = RGB(255,255,255);
}

CMyRectangle::CMyRectangle(COLORREF color)
{
	m_color = color;
}

void CMyRectangle::draw(CDC& dc)
{
	CBrush brush(m_color);
	CPen pen(PS_SOLID, 3, RGB(0,0,0));
	dc.SelectObject(brush);
	dc.SelectObject(pen);
	dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
}

void CMyRectangle::doMouseDown(CPoint p)
{
	p1 = CPoint(p);
	p2 = CPoint(p);
}

void CMyRectangle::doMouseUp(CPoint p)
{
	p2 = CPoint(p);

	lt.x = min(p1.x, p2.x);
	rb.x = max(p1.x, p2.x);
	lt.y = min(p1.y, p2.y);
	rb.y = max(p1.y, p2.y);
}

bool CMyRectangle::isClicked(CPoint p)
{
	if (lt.x <= p.x && p.x <= rb.x && lt.y <= p.y && p.y <= rb.y) {
		return true;
	}
	else return false;
}
