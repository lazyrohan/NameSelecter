
// CNameSelecterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NameSelecter.h"
#include "CNameSelecterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CNameSelecterDlg �Ի���



CNameSelecterDlg::CNameSelecterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNameSelecterDlg::IDD, pParent),
	m_oNameChooser()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNameSelecterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNameSelecterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_UPDATE(IDC_EDIT_FNAMEIN, &CNameSelecterDlg::OnEnUpdateEditFnamein)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CNameSelecterDlg::OnBnClickedButtonSelect)
	ON_EN_CHANGE(IDC_EDIT_FNAMEIN, &CNameSelecterDlg::OnEnChangeEditFnamein)
END_MESSAGE_MAP()


// CNameSelecterDlg ��Ϣ�������

BOOL CNameSelecterDlg::OnInitDialog()
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	//Initialize output info
	//Name square array
	m_sFamilyName = "��";
	for (int i = 0; i < 4;i++)
	{
		m_sNameSquare[i][0] = "��";
		for (int j = 1; j < 3;j++)
		{
			m_sNameSquare[i][j] = "��";
		}
	}
	UpdateNameSquare();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CNameSelecterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNameSelecterDlg::OnPaint()
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
//��ʾ��
HCURSOR CNameSelecterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNameSelecterDlg::OnEnUpdateEditFnamein()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// �������Խ� EM_SETEVENTMASK ��Ϣ���͵��ÿؼ���
	// ͬʱ�� ENM_UPDATE ��־�������㵽 lParam �����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CNameSelecterDlg::OnBnClickedButtonSelect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//Recaculate and fill name square arry first
	FillNameSquare();
	UpdateNameSquare();
}


// Fill Name Square
void CNameSelecterDlg::FillNameSquare(void)
{
	//Generate random name

	//Output name info 
	for (int i = 0; i < 4; i++)
	{
		if (m_sFamilyName=="��")
		{
			m_oNameChooser.GenFamilyName();
			m_sNameSquare[i][0]=m_oNameChooser.m_sFullName[0].c_str();
		}

		m_oNameChooser.GenRandName(2);
		for (int j = 1; j < 3;j++)
		{
			m_sNameSquare[i][j]=m_oNameChooser.m_sFullName[j].c_str();
		}
	}

}


void CNameSelecterDlg::UpdateNameSquare(void)
{
	CString strBuff;
	//Output name info 
	for (int i = 0; i < 4;i++)
	{
		for (int j = 0; j < 3;j++)
		{
			GetDlgItem(IDC_STATIC_FNAME00+i*3+j)->SetWindowTextW(m_sNameSquare[i][j]);
			strBuff.Format(TEXT("Info: \r\nName square item %d updated.\r\n"), IDC_EDIT_FNAMEIN + i * 3 + j);
			m_sOutinfo += strBuff;
		}
	}

	//Update item text
	//GetDlgItem(IDC_EDIT_OUTINFO)->SetWindowTextW(m_sOutinfo);
	UpdateData();
}


void CNameSelecterDlg::OnEnChangeEditFnamein()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	LPTSTR fname=TEXT("");
	//memset(fname,0,8);
	GetDlgItem(IDC_EDIT_FNAMEIN)->GetWindowTextW(fname,8);
	m_sFamilyName = fname;

}
