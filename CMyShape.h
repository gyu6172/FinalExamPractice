#pragma once
class CMyShape
{
public:
	CPoint m_pts[20];
	int m_ptsCnt;
	COLORREF m_color;

	CMyShape();
	void draw(CDC &dc);
};

