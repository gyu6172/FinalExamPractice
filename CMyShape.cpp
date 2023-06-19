#include "pch.h"
#include "CMyShape.h"

CMyShape::CMyShape()
{
	m_ptsCnt = 0;
	m_color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

void CMyShape::draw(CDC& dc)
{
	CPen pen(PS_SOLID, 3, RGB(0,0,0));
	CBrush brush(m_color);
	dc.SelectObject(pen);
	dc.SelectObject(brush);
	dc.Polygon(m_pts, m_ptsCnt);
}
