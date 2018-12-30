
// translate_appDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include<fstream>
#include <map>
#include <string>
#include"TRANS.h"
using namespace std;
// Ctranslate_appDlg 对话框
class Ctranslate_appDlg : public CDialogEx
{
// 构造
public:
	Ctranslate_appDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRANSLATE_APP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox trans2;
	CString trans2an;
	CString m_PresentFolder;//当前文件夹
	CString codePath;//代码输入文件位置
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
