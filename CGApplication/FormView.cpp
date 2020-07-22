// FormView.cpp : implementation file
//

#include "pch.h"
#include "CGApplication.h"
#include "FormView.h"



// FormView

IMPLEMENT_DYNCREATE(FormView, CFormView)

FormView::FormView()
	: CFormView(IDD_FormView)
{

}

FormView::~FormView()
{
}

void FormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FormView, CFormView)
	//ON_BN_CLICKED(IDC_BUTTON4, &FormView::OnBnClickedButton4)
END_MESSAGE_MAP()


// FormView diagnostics

#ifdef _DEBUG
void FormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormView message handlers

