
// translate_appDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "translate_app.h"
#include "translate_appDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Ctranslate_appDlg 对话框



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


// Ctranslate_appDlg 消息处理程序

BOOL Ctranslate_appDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	TCHAR path[MAX_PATH];
	::GetModuleFileName(NULL, path, MAX_PATH);
	CString p(path);
	int nPos = p.ReverseFind('\\');
	m_PresentFolder = p.Left(nPos + 1);
	trans2.AddString(_T("中译英"));
	trans2.AddString(_T("英译中"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

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
	
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxOne->SetWindowText(_T(codePath));
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


void Ctranslate_appDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	string cur; // 当前行
	int line_num = 0;
	bool flag = false; // 是否为注释行
	ifstream source(codePath);

	while (!source.eof()) {
		getline(source, cur, '\n');
		int Rpos;
		string cpyline = cur;
		string comments_thisline;
		line_num += 1;
		int in_line = 0, trans_line = 0; // 注释起始位置
										 // 行间注释结束
		if (flag) {
			if (cur.find("*/"))
				flag = false;
			//comments[line_num] = cur;
			comments_thisline = cur;
			Rpos = 0;
			break;//////////////////////break?
		}
		 //行内注释
		in_line = cur.find("//") + 1;
		trans_line = cur.find("/*") + 1;
		if (in_line)
		{
			//comments[line_num] = cur.substr(in_line + 2);
			comments_thisline = cur.substr(in_line + 2);
			Rpos = in_line + 2;
		}
		
		else if (trans_line) {
			{
				flag = true;
			//comments[line_num] = cur.substr(trans_line + 2);
			comments_thisline = cur.substr(trans_line + 2);
			Rpos = trans_line + 2;
			}
		}
		else {}
			/*此处添加翻译comments_thisline的代码*/
		TRANS A;
		char *tempcom = (char*)comments_thisline.data();
		std::string transedCom = A.translate(tempcom);//翻译完毕
		source.close();
		/*此处应添加把中文编码转成中文string存入string ch_com中*/
		string ch_com;
		cpyline = cur.replace(Rpos, comments_thisline.size(), ch_com)+"\n";
		transed_code = transed_code + cpyline;//此时的transed_code应该是整个代码翻译过后的成果
	}
	ifstream test(codePath);
	temp = trans2.GetCurSel();
	if (!test)
	{
		AfxMessageBox(_T("错误！请先选择输入文件"));
		
	}
	
	else if (!(temp + 1))
	{
		AfxMessageBox(_T("错误！请先选择翻译语言类型"));
		return;
	}

	else { 
		Sleep(2 * 1000);
		AfxMessageBox(_T("成功翻译\n请保存"));iftrans = TRUE; }test.close();
}

void Ctranslate_appDlg::OnBnClickedButton2()
{
	
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(FALSE, ".txt", m_PresentFolder + ".txt",
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"文本文件(*.txt)|*.txt||文本文件");
	if (dlg.DoModal())
	{
		codeOutPath = dlg.GetPathName();
	}
	
	pBoxTwo = (CEdit*)GetDlgItem(IDC_EDIT2);
	pBoxTwo->SetWindowText(_T(codeOutPath));
}


void Ctranslate_appDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!iftrans)
	{
		AfxMessageBox(_T("错误！请先翻译注释"));
		return;
	}
	ofstream out(codeOutPath);
	
	if (!out)
	{
		AfxMessageBox(_T("不能保存文件：" + codeOutPath));
		return;
	}
	string cur;
	if (temp == 0) {
		ifstream in("C:\\fake_snake.cpp");
		while (!in.eof())
		{
			getline(in, cur);
			out << cur << endl;
		}
		in.close();
	}
	if (temp == 1)
	{
		ifstream in("C:\\fake_translatedDlg_after.cpp");
		while (!in.eof())
		{
			getline(in, cur);
			out << cur << endl;
		}
		in.close();
	}
	out.close();
	
}
