#include "stdafx.h"
#include "translate_app.h"
#include "translate_appDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó�����ڲ˵���ĶԻ���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	//�Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    //֧��

														//ʵ��
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


//�Ի���



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


//��Ϣ�������

BOOL Ctranslate_appDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �����ڲ˵�����ӵ�ϵͳ�˵��С�

	//������ϵͳ���Χ�ڡ�
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

	//���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//ִ�д˲���
	SetIcon(m_hIcon, TRUE);			//���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		//����Сͼ��

									//�ڴ���Ӷ���ĳ�ʼ������
	TCHAR path[MAX_PATH];
	::GetModuleFileName(NULL, path, MAX_PATH);
	CString p(path);
	int nPos = p.ReverseFind('\\');
	m_PresentFolder = p.Left(nPos + 1);

	return TRUE;  //���ǽ��������õ��ؼ������򷵻�1.
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

//�����Ի��������С����ť������Ҫ����Ĵ���
//�����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵�Ӧ�ó���
//�⽫�ɿ���Զ���ɡ�

void Ctranslate_appDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ
HCURSOR Ctranslate_appDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctranslate_appDlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE, ".cpp||.h", m_PresentFolder + ".cpp",
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"C++�ļ�(*.cpp;*.h)|*.cpp;*.h||");
	if (dlg.DoModal())
	{
		codePath = dlg.GetPathName();
	}
}


void Ctranslate_appDlg::OnBnClickedCancel()
{
	//�ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void Ctranslate_appDlg::OnBnClickedOk()
{
	//�ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
