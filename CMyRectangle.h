#pragma once
class CMyRectangle
{
public:
	CPoint lt,rb;
	CPoint p1,p2;
	COLORREF m_color;

	CMyRectangle();
	CMyRectangle(COLORREF color);

	void draw(CDC &dc);
	void doMouseDown(CPoint p);
	void doMouseUp(CPoint p);
	bool isClicked(CPoint p);
};

