#if !defined(AFX_SHORTCUT_H__769F454B_8939_44F3_A6A0_DE96A38361E3__INCLUDED_)
#define AFX_SHORTCUT_H__769F454B_8939_44F3_A6A0_DE96A38361E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Shortcut.h : main header file for SHORTCUT.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShortcutApp : See Shortcut.cpp for implementation.

class CShortcutApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTCUT_H__769F454B_8939_44F3_A6A0_DE96A38361E3__INCLUDED)
