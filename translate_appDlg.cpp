
// translate_appDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "translate_app.h"
#include "translate_appDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Ctranslate_appDlg �Ի���



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


// Ctranslate_appDlg ��Ϣ�������

BOOL Ctranslate_appDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	TCHAR path[MAX_PATH];
	::GetModuleFileName(NULL, path, MAX_PATH);
	CString p(path);
	int nPos = p.ReverseFind('\\');
	m_PresentFolder = p.Left(nPos + 1);
	trans2.AddString(_T("����Ӣ"));
	trans2.AddString(_T("Ӣ����"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

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
	
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxOne->SetWindowText(_T(codePath));
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


void Ctranslate_appDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	string cur; // ��ǰ��
	int line_num = 0;
	bool flag = false; // �Ƿ�Ϊע����
	ifstream source(codePath);

	while (!source.eof()) {
		getline(source, cur, '\n');
		int Rpos;
		string cpyline = cur;
		string comments_thisline;
		line_num += 1;
		int in_line = 0, trans_line = 0; // ע����ʼλ��
										 // �м�ע�ͽ���
		if (flag) {
			if (cur.find("*/"))
				flag = false;
			//comments[line_num] = cur;
			comments_thisline = cur;
			Rpos = 0;
			break;//////////////////////break?
		}
		 //����ע��
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
			/*�˴���ӷ���comments_thisline�Ĵ���*/
		TRANS A;
		char *tempcom = (char*)comments_thisline.data();
		std::string transedCom = A.translate(tempcom);//�������
		source.close();
		/*�˴�Ӧ��Ӱ����ı���ת������string����string ch_com��*/
		string ch_com;
		cpyline = cur.replace(Rpos, comments_thisline.size(), ch_com)+"\n";
		transed_code = transed_code + cpyline;//��ʱ��transed_codeӦ�����������뷭�����ĳɹ�
	}
	ifstream test(codePath);
	temp = trans2.GetCurSel();
	if (!test)
	{
		AfxMessageBox(_T("��������ѡ�������ļ�"));
		
	}
	
	else if (!(temp + 1))
	{
		AfxMessageBox(_T("��������ѡ������������"));
		return;
	}

	else { 
		Sleep(2 * 1000);
		AfxMessageBox(_T("�ɹ�����\n�뱣��"));iftrans = TRUE; }test.close();
}

void Ctranslate_appDlg::OnBnClickedButton2()
{
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(FALSE, ".txt", m_PresentFolder + ".txt",
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"�ı��ļ�(*.txt)|*.txt||�ı��ļ�");
	if (dlg.DoModal())
	{
		codeOutPath = dlg.GetPathName();
	}
	
	pBoxTwo = (CEdit*)GetDlgItem(IDC_EDIT2);
	pBoxTwo->SetWindowText(_T(codeOutPath));
}


void Ctranslate_appDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!iftrans)
	{
		AfxMessageBox(_T("�������ȷ���ע��"));
		return;
	}
	ofstream out(codeOutPath);
	
	if (!out)
	{
		AfxMessageBox(_T("���ܱ����ļ���" + codeOutPath));
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
