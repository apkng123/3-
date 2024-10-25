
// 3장 실습문제 디지털시계 만들기View.h: CMy3장실습문제디지털시계만들기View 클래스의 인터페이스
//

#pragma once


class CMy3장실습문제디지털시계만들기View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy3장실습문제디지털시계만들기View() noexcept;
	DECLARE_DYNCREATE(CMy3장실습문제디지털시계만들기View)

// 특성입니다.
public:
	CMy3장실습문제디지털시계만들기Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy3장실습문제디지털시계만들기View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	bool m_bTimerRun;
	bool m_bTimerType;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_strTimer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // 3장 실습문제 디지털시계 만들기View.cpp의 디버그 버전
inline CMy3장실습문제디지털시계만들기Doc* CMy3장실습문제디지털시계만들기View::GetDocument() const
   { return reinterpret_cast<CMy3장실습문제디지털시계만들기Doc*>(m_pDocument); }
#endif

