
// CNameSelecterDlg.h : ͷ�ļ�
//

#pragma once
#include "CNameChooser.h"

// CNameSelecterDlg �Ի���
class CNameSelecterDlg : public CDialogEx
{
// ����
public:
	CNameSelecterDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NAMESELECTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

private:
	CString m_sNameSquare[4][3];
	CString m_sFamilyName;
	CString m_sOutinfo;
	CNameChooser m_oNameChooser;

	// ���ɵ���Ϣӳ�亯��
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
