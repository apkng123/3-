
// 3장 실습문제 디지털시계 만들기View.cpp: CMy3장실습문제디지털시계만들기View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "3장 실습문제 디지털시계 만들기.h"
#endif

#include "3장 실습문제 디지털시계 만들기Doc.h"
#include "3장 실습문제 디지털시계 만들기View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3장실습문제디지털시계만들기View

IMPLEMENT_DYNCREATE(CMy3장실습문제디지털시계만들기View, CView)

BEGIN_MESSAGE_MAP(CMy3장실습문제디지털시계만들기View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMy3장실습문제디지털시계만들기View 생성/소멸

CMy3장실습문제디지털시계만들기View::CMy3장실습문제디지털시계만들기View() noexcept
{
	m_bTimerRun = false;
	m_bTimerType = true;
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy3장실습문제디지털시계만들기View::~CMy3장실습문제디지털시계만들기View()
{
}

BOOL CMy3장실습문제디지털시계만들기View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy3장실습문제디지털시계만들기View 그리기

void CMy3장실습문제디지털시계만들기View::OnDraw(CDC* pDC)
{
	CMy3장실습문제디지털시계만들기Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);

	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy3장실습문제디지털시계만들기View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy3장실습문제디지털시계만들기View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy3장실습문제디지털시계만들기View 진단

#ifdef _DEBUG
void CMy3장실습문제디지털시계만들기View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3장실습문제디지털시계만들기View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3장실습문제디지털시계만들기Doc* CMy3장실습문제디지털시계만들기View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3장실습문제디지털시계만들기Doc)));
	return (CMy3장실습문제디지털시계만들기Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3장실습문제디지털시계만들기View 메시지 처리기


int CMy3장실습문제디지털시계만들기View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	SetTimer(0, 1000, NULL);
	m_bTimerRun = true;

	return 0;
}


void CMy3장실습문제디지털시계만들기View::OnTimer(UINT_PTR nIDEvent)
{
	int hour;
	CString str;

	
	CTime timer;
	timer = CTime::GetCurrentTime();
	if (m_bTimerType)
	{
		m_strTimer.Format(_T("현재는 %d년 %d월 %d일 %d시 %d분 %d초"), timer.GetYear(), timer.GetMonth(), timer.GetDay(), timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	}
	else {
	
		hour = timer.GetHour();
		if (hour >= 12)
		{
			str = _T("PM");
			hour = hour - 12;
		}
		else {
			str = _T("AM");
		}

		m_strTimer.Format(_T("지금은 %s %d시 %d분 %d초"), str, hour, timer.GetMinute(), timer.GetSecond());
	}
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy3장실습문제디지털시계만들기View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerType )
	{
		if (AfxMessageBox(_T("시, 분, 초 형태로 표시하시겠습니까?"),MB_YESNO|MB_ICONQUESTION )==IDYES)
		{
			m_bTimerType = false;
	
		
		}

	}
	else {
		if (AfxMessageBox(_T("년, 월, 일, 시, 분, 초 형태로 표시하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_bTimerType = true;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy3장실습문제디지털시계만들기View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerRun == false)
	{
		if (AfxMessageBox(_T("디지털 시계를 작동시키겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			SetTimer(0, 1000, NULL);
			m_bTimerRun = TRUE;
		}
	}
	else {
		if (AfxMessageBox(_T("정말로 디지털시계 동작을 멈추겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			KillTimer(0);
			m_bTimerRun = FALSE;

		}
	}

	CView::OnRButtonDown(nFlags, point);
}


void CMy3장실습문제디지털시계만들기View::OnDestroy()
{
	CView::OnDestroy();
	if (m_bTimerRun)
	{
		KillTimer(0);
	}
	

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
