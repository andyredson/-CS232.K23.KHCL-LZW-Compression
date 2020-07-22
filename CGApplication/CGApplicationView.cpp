
// CGApplicationView.cpp : implementation of the CCGApplicationView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CGApplication.h"
#endif

#include "CGApplicationDoc.h"
#include "CGApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCGApplicationView

IMPLEMENT_DYNCREATE(CCGApplicationView, CView)

BEGIN_MESSAGE_MAP(CCGApplicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCGApplicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCGApplicationView construction/destruction

CCGApplicationView::CCGApplicationView() noexcept
{
	// TODO: add construction code here

}

CCGApplicationView::~CCGApplicationView()
{
}

BOOL CCGApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCGApplicationView drawing

void CCGApplicationView::OnDraw(CDC* pDC)
{
	CCGApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	
	
}


// CCGApplicationView printing


void CCGApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCGApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCGApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCGApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCGApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCGApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCGApplicationView diagnostics

#ifdef _DEBUG
void CCGApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CCGApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGApplicationDoc* CCGApplicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGApplicationDoc)));
	return (CCGApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CCGApplicationView message handlers
