// ShortcutCtl.cpp : Implementation of the CShortcutCtrl ActiveX Control class.

#include "stdafx.h"
#include "Shortcut.h"
#include "ShortcutCtl.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CShortcutCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CShortcutCtrl, COleControl)
	//{{AFX_MSG_MAP(CShortcutCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CShortcutCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CShortcutCtrl)
	DISP_FUNCTION(CShortcutCtrl, "MakeShortcut", MakeShortcut, VT_BOOL, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CShortcutCtrl, COleControl)
	//{{AFX_EVENT_MAP(CShortcutCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()



/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CShortcutCtrl, "SHORTCUT.ShortcutCtrl.1",
	0xfd1b28ad, 0x5024, 0x45e8, 0x90, 0x13, 0x54, 0xb8, 0xfd, 0xb9, 0xd7, 0x40)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CShortcutCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DShortcut =
		{ 0x9671cf70, 0xd29d, 0x403d, { 0x98, 0x78, 0x98, 0xb1, 0x4e, 0xf6, 0xde, 0x3e } };
const IID BASED_CODE IID_DShortcutEvents =
		{ 0x90d8fcea, 0x194f, 0x48e8, { 0xa2, 0xb0, 0xa7, 0xf7, 0x33, 0xfb, 0xcb, 0x84 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwShortcutOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CShortcutCtrl, IDS_SHORTCUT, _dwShortcutOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl::CShortcutCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CShortcutCtrl

BOOL CShortcutCtrl::CShortcutCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_SHORTCUT,
			IDB_SHORTCUT,
			afxRegApartmentThreading,
			_dwShortcutOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl::CShortcutCtrl - Constructor

CShortcutCtrl::CShortcutCtrl()
{
	InitializeIIDs(&IID_DShortcut, &IID_DShortcutEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl::~CShortcutCtrl - Destructor

CShortcutCtrl::~CShortcutCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl::OnDraw - Drawing function

void CShortcutCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl::DoPropExchange - Persistence support

void CShortcutCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl::OnResetState - Reset control to default state

void CShortcutCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CShortcutCtrl message handlers

BOOL FileExists(CString strFilePath)
{
	if(strFilePath.GetLength() == 3 && strFilePath.Right(2) == ":\\") {
		return TRUE;
	}

	CFileFind finder;
	BOOL bRet = finder.FindFile(strFilePath);
	finder.Close();

	return bRet;
}
/*
void WriteIconFile(CString strIconFile)
{
//	MessageBox(NULL, "3", "", MB_OK);
	HRSRC hResInfo;
    HGLOBAL hGlobal;
	HMODULE GetModuleHandle();
	HMODULE hModule = AfxGetInstanceHandle();
    hResInfo = FindResource(hModule, "ICON" ,"BIN");
    hGlobal = LoadResource(NULL,hResInfo);
    if (hGlobal)
	{
//		MessageBox(NULL, "4", "", MB_OK);
		BYTE *data = (BYTE FAR*)LockResource(hGlobal);       	 
		if (data)
		{
//			MessageBox(NULL, "5", "", MB_OK);
			FILE *fp = fopen(strIconFile,"wb");
			int nLen = sizeof(BYTE);
			int nLen2 = SizeofResource(hModule, hResInfo); 
			fwrite(data,nLen,nLen2,fp);
			fclose(fp);
		}
		::UnlockResource(hGlobal);
	}
    
    if(hGlobal) ::FreeResource(hGlobal);
}
*/

BOOL CShortcutCtrl::MakeShortcut() 
{
	LPMALLOC pMalloc;
	LPITEMIDLIST lpidl;
	char szSCPath[MAX_PATH];
	char szShortcutInfo[MAX_PATH];

	HANDLE hFile;
	DWORD dwWritten;

	::SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &lpidl);
	::SHGetPathFromIDList(lpidl, szSCPath);
	strcat(szSCPath, "\\");
	strcat(szSCPath, ".url");

	::SHGetMalloc(&pMalloc);
	pMalloc->Free(lpidl);
	pMalloc->Release();


/*	char buff[MAX_PATH];
	if(GetSystemDirectory(buff, MAX_PATH)){
//		MessageBox("1");
		strcat(buff, "\\.ico");
		if(!FileExists(buff)){
//			MessageBox("2");
			WriteIconFile(buff);
		}
	}
*/
	wsprintf(szShortcutInfo, "[InternetShortcut]\r\nURL=%s\r\nIconIndex=0\r\nIconFile=%s\r\n"
		"Modified=000000000000000000\r\n", 
		"http://www..co.kr", 
		"http://www..co.kr/favicon.ico");

	hFile = CreateFile(szSCPath, 
		GENERIC_READ|GENERIC_WRITE,0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(!hFile) {
		return FALSE;
	}

	WriteFile(hFile, szShortcutInfo, strlen(szShortcutInfo), &dwWritten, NULL);
	CloseHandle(hFile);

	return TRUE;
}
