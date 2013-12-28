#if !defined(AFX_SHORTCUTCTL_H__E3EDEF37_E815_4A66_85C0_A0F6B24DEBA4__INCLUDED_)
#define AFX_SHORTCUTCTL_H__E3EDEF37_E815_4A66_85C0_A0F6B24DEBA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ShortcutCtl.h : Declaration of the CShortcutCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl : See ShortcutCtl.cpp for implementation.

class CShortcutCtrl : public COleControl
{
	DECLARE_DYNCREATE(CShortcutCtrl)

// Constructor
public:
	CShortcutCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShortcutCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CShortcutCtrl();

	DECLARE_OLECREATE_EX(CShortcutCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CShortcutCtrl)      // GetTypeInfo
	DECLARE_OLECTLTYPE(CShortcutCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CShortcutCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CShortcutCtrl)
	afx_msg BOOL MakeShortcut();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CShortcutCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CShortcutCtrl)
	dispidMakeShortcut = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTCUTCTL_H__E3EDEF37_E815_4A66_85C0_A0F6B24DEBA4__INCLUDED)
