
// CGApplicationView.h : interface of the CCGApplicationView class
//

#pragma once
#include "CGApplicationDoc.h"


class CCGApplicationView : public CView
{
protected: // create from serialization only
	CCGApplicationView() noexcept;
	DECLARE_DYNCREATE(CCGApplicationView)

// Attributes
public:
	CCGApplicationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCGApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CGApplicationView.cpp
inline CCGApplicationDoc* CCGApplicationView::GetDocument() const
   { return reinterpret_cast<CCGApplicationDoc*>(m_pDocument); }
#endif

