
// translate_appDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include<fstream>
#include <map>
#include <string>
#include"TRANS.h"
using namespace std;
// Ctranslate_appDlg �Ի���
class Ctranslate_appDlg : public CDialogEx
{
// ����
public:
	Ctranslate_appDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRANSLATE_APP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox trans2;
	CString trans2an;
	CString m_PresentFolder;//��ǰ�ļ���
	CString codePath;//���������ļ�λ��
	CString codeOutPath;
	CString translatedCode;
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	bool iftrans = FALSE;
	int temp;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	string transed_code;
	afx_msg void OnBnClickedButton4();
};
