// grefishmap.h : main header file for the GREFISHMAP application
//

#if !defined(AFX_GREFISHMAP_H__7CEAD6D6_C08D_4BE0_B788_517153134FBC__INCLUDED_)
#define AFX_GREFISHMAP_H__7CEAD6D6_C08D_4BE0_B788_517153134FBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGrefishmapApp:
// See grefishmap.cpp for the implementation of this class
//

class CGrefishmapApp : public CWinApp
{
public:
	CGrefishmapApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrefishmapApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGrefishmapApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREFISHMAP_H__7CEAD6D6_C08D_4BE0_B788_517153134FBC__INCLUDED_)
