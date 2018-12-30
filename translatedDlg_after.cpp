#include "stdafx.h"
#include "translate_app.h"
#include "translate_appDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//Dialog for application related menu items

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	//Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    //Support

														//achieve
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


//Dialog



Ctranslate_appDlg::Ctranslate_appDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TRANSLATE_APP_DIALOG, pParent)
	, trans2an(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctranslate_appDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, trans2);
	DDX_CBString(pDX, IDC_COMBO1, trans2an);
}

BEGIN_MESSAGE_MAP(Ctranslate_appDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctranslate_appDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &Ctranslate_appDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &Ctranslate_appDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &Ctranslate_appDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctranslate_appDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Ctranslate_appDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


//Message handler

BOOL Ctranslate_appDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//Add about menu items to the system menu.

	//Must be within the scope of the system command.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	//Set the icon for this dialog. The framework will do this automatically when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			//Set big icon
	SetIcon(m_hIcon, FALSE);		//Set small icon

									//Add extra initialization code here
	TCHAR path[MAX_PATH];
	::GetModuleFileName(NULL, path, MAX_PATH);
	CString p(path);
	int nPos = p.ReverseFind('\\');
	m_PresentFolder = p.Left(nPos + 1);

	return TRUE;  //Returns 1. unless the focus is set to the control.
}

void Ctranslate_appDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

//If you add a minimize button to the dialog, you need the following code
//To draw the icon. For applications that use the document/view model,
//This will be done automatically by the framework.

void Ctranslate_appDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); //Device context for drawing

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		//Center the icon in the workspace rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		//Draw icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//The system calls this function to get the cursor when the user drags the minimized window.
//display
HCURSOR Ctranslate_appDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctranslate_appDlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE, ".cpp||.h", m_PresentFolder + ".cpp",
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"C++нд╪Ч(*.cpp;*.h)|*.cpp;*.h||");
	if (dlg.DoModal())
	{
		codePath = dlg.GetPathName();
	}
}


void Ctranslate_appDlg::OnBnClickedCancel()
{
	//Add control notification handler code here
	CDialogEx::OnCancel();
}


void Ctranslate_appDlg::OnBnClickedOk()
{
	//Add control notification handler code here
	CDialogEx::OnOK();
}
