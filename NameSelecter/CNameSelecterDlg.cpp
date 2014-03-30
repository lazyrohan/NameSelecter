
// CNameSelecterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "NameSelecter.h"
#include "CNameSelecterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CNameSelecterDlg 对话框



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


// CNameSelecterDlg 消息处理程序

BOOL CNameSelecterDlg::OnInitDialog()
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

	// TODO:  在此添加额外的初始化代码
	//Initialize output info
	//Name square array
	m_sFamilyName = "姓";
	for (int i = 0; i < 4;i++)
	{
		m_sNameSquare[i][0] = "姓";
		for (int j = 1; j < 3;j++)
		{
			m_sNameSquare[i][j] = "名";
		}
	}
	UpdateNameSquare();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNameSelecterDlg::OnPaint()
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
//显示。
HCURSOR CNameSelecterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNameSelecterDlg::OnEnUpdateEditFnamein()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CNameSelecterDlg::OnBnClickedButtonSelect()
{
	// TODO:  在此添加控件通知处理程序代码
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
		if (m_sFamilyName=="姓")
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	LPTSTR fname=TEXT("");
	//memset(fname,0,8);
	GetDlgItem(IDC_EDIT_FNAMEIN)->GetWindowTextW(fname,8);
	m_sFamilyName = fname;

}
