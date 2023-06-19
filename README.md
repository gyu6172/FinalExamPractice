# FinalExamPractice
C++기말고사 MFC 연습

<h2>CP21.ppt, CP22.ppt</h2>
OnCreate() : create view<br>
OnPaint() : print in the view<br>
Rectangle() : draw Rectangle from (x1,y1) to (x2,y2)<br>
Ellipse() : draw Circle in Rectangle<br>
RoundRect() : round rectangle from(x1,y1) to (x2,y2), with diameter x3,y3<br>
Polygon(CPoint pts[], int ptscnt) : draw polygon <br>
<br>
GetPixel(x,y) : get color from (x,y)<br>
SetPixel(x,y,c) : set pixel color to c, return original color<br>
SetPixel(x,y,c) : same with SetPixel(), no return. more faster.<br>
<br>
CRect : rectangle class, m_top, m_bottom, m_left, m_right<br>
How to know window size?<br>
-> CRect rect; GetClientRect(rect);<br>
draw Line : MoveTo(x,y), LineTo(x,y)<br>
<br>
Text print function<br>
TextOut(x, y, _T("")) : print Text in (x,y)<br>
DrawText(x,y,_T("")) : print Text in rectangle in at (x,y)<br>
SetTextColor(RGB()) : change text color<br>
SetBkColor(RGB()) : change background color<br>
SetTextAlign(TA_CENTER) : align text<br>
<br>
CPen pen(PS_SOLID, 3, RGB()) : mode:SOLID(_____), radius=3, color=RGB()<br>
미리 정의된 객체를 사용할때는 dc.SelectStockObject(NULL_PEN);<br>
<br>
Bitmap : show image<br>
In Resource View, createBitmap<br>
CBitmap bitmap;<br>
bitmap.LoadBitmapW(IDB_BITMAP1)<br>
BITMAP bmpInfo;<br>
bitmap.GetBitmap(&bmpInfo);<br>

CDC memDC;<br>
memDC.CreateCompatibleDC(&dc);<br>
memDC.SelectObject(bitmap);<br>

dc.BitBlt(x, y, w, h, &memDC, 0, 0, SRCCOPY); : at(x,y) in dc, create area width=w, height=h, from (0,0) in bitmap, SRCCOPY<br>
dc.StrechBlt() : ???<br>
<br>
디바이스 컨텍스트<br>
Invalidate()함수<br>
dc의 도형그리기 함수들, COLORREF<br>
창의 사이즈 알고 싶다면?<br>
텍스트 출력함수 <br>
GDI객체(펜, 브러쉬 등), 폰트 <br>
비트맵 띄우는 법<br>
더블 버퍼링<br>
<br>
<h2>CP23.ppt</h2>
비트맵 출력하기 & 더블 버퍼링<br>
마우스 이벤트<br>
마우스 캡쳐(마우스가 밖으로 나갔을 때도 잘 그려지게)<br>
C++ STL라이브러리 복습<br>
MFC에서의 STL라이브러리 : CList, CVector, CMap<br>
코딩연습 : 마우스 왼쪽 버튼으로 곡선 그리고, 오른쪽 버튼으로 사각형 영역 지정해서 영역 안의 점들 지우기<br>
<br>
<h2>CP24.ppt, CP25.ppt</h2>
마우스 이벤트 복습<br>
Useful Tips for programming(디버깅 모드)<br>
디버깅용 명령어(TRACE, Assert)<br>
키보드 이벤트<br>
WM_KEY_DOWN : F10, Alt외의 키를 눌렀을 때<br>
WM_SYSKEY_DOWN : F10, Alt, Alt+키를 눌렀을 때<br>
WM_CHAR : 한글, word 만들 때 사용.<br>
WM_KEY_DOWN -> WM_CHAR -> WM_KEY_UP<br>
타이머 이벤트<br>
코딩연습 : 사각형이 죽~움직이는 장면 만들기<br>
<br>
<h2>CP26.ppt</h2>
"잘라내기(T)  Ctrl+X" : 잘라내기(&T)\tCtrl+X
인터페이스 - 메뉴바 만들기 <br>
리소스 뷰를 이용하여 메뉴 생성하기<br>
메뉴를 눌렀을 때 실행되는 WM_COMMAND 메시지 핸들러 다루기<br>
ON_COMMAND와 ON_UPDATE_COMMAND_UI 알기<br>
인터페이스 - 툴바 만들기<br>
툴바 : 메뉴의 메시지 핸들러 툴바에도 연결시키기<br>
메뉴에 없다면? 직접 메시지 핸들러 연걸<br>
<br>
<h2>CP27.ppt</h2>

우클릭메뉴 생성<br>
CMenu menu;
menu.CreatePopUpMenu():

menu.TrackPopUpMenu(TPM_LEFTALIGN, point.x, point.y, AfxGetMainWnd());<br>
직접 코딩을 통하여 메뉴 생성하기(CMenu 클래스)<br>
컨텍스트(=단축, 팝업) 메뉴(우클릭 눌렀을 때 나오는 메뉴)<br>

버튼 생성하기<br>
1. 일반 윈도우에서 직접 만들기<br>
CChildView에 CButton객체 추가<br>
OnCreate에서 CButton.Create()함수 호출<br>
리스너 : 메시지 핸들러 직접 추

Control(Button Control, Radio Button 그룹 등의 객체를 말함) <br>
각종 객체(버튼, 체크박스, 라디오 버튼 등) 생성하기 <br>
Dialog Box(대화 상자) 생성하기 <br>
대화상자란? 다양한 컨트롤을 포함하고 있는 윈도우, 사용자로부터 입력을 받거나 정보를 출력<br>








