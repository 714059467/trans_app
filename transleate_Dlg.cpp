#include "stdafx.h"
#include "translate_app.h"
#include "translate_appDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序关于菜单项的对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	//对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    //支持

														//实现
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


//对话框



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


//消息处理程序

BOOL Ctranslate_appDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将关于菜单项添加到系统菜单中。

	//必须在系统命令范围内。
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

	//设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//执行此操作
	SetIcon(m_hIcon, TRUE);			//设置大图标
	SetIcon(m_hIcon, FALSE);		//设置小图标

									//在此添加额外的初始化代码
	TCHAR path[MAX_PATH];
	::GetModuleFileName(NULL, path, MAX_PATH);
	CString p(path);
	int nPos = p.ReverseFind('\\');
	m_PresentFolder = p.Left(nPos + 1);

	return TRUE;  //除非将焦点设置到控件，否则返回1.
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

//如果向对话框添加最小化按钮，则需要下面的代码
//来绘制该图标。对于使用文档/视图模型的应用程序，
//这将由框架自动完成。

void Ctranslate_appDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示
HCURSOR Ctranslate_appDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctranslate_appDlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE, ".cpp||.h", m_PresentFolder + ".cpp",
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"C++文件(*.cpp;*.h)|*.cpp;*.h||");
	if (dlg.DoModal())
	{
		codePath = dlg.GetPathName();
	}
}


void Ctranslate_appDlg::OnBnClickedCancel()
{
	//在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void Ctranslate_appDlg::OnBnClickedOk()
{
	//在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
