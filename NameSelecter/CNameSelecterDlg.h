
// CNameSelecterDlg.h : 头文件
//

#pragma once
#include "CNameChooser.h"

// CNameSelecterDlg 对话框
class CNameSelecterDlg : public CDialogEx
{
// 构造
public:
	CNameSelecterDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_NAMESELECTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

private:
	CString m_sNameSquare[4][3];
	CString m_sFamilyName;
	CString m_sOutinfo;
	CNameChooser m_oNameChooser;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnUpdateEditFnamein();
	afx_msg void OnBnClickedButtonSelect();
private:
	// Fill Name Square
	void FillNameSquare(void);
	void UpdateNameSquare(void);
public:
	afx_msg void OnEnChangeEditFnamein();
};
