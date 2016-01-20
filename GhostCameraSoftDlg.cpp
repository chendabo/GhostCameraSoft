
// GhostCameraSoftDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GhostCameraSoft.h"
#include "GhostCameraSoftDlg.h"
#include "afxdialogex.h"
#include "itemresize.h"
#include "open_drawing.h"
#include "CvvImage.h"
#include "NetWorkCtrl.h"

using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CItemResize m_itemSize;
CvCapture* capture;
IplImage* image;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGhostCameraSoftDlg 对话框



CGhostCameraSoftDlg::CGhostCameraSoftDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGhostCameraSoftDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CGhostCameraSoftDlg::~CGhostCameraSoftDlg()
{
	delete pCNetWorkCtrlDlg;
}


void CGhostCameraSoftDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGhostCameraSoftDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	//ON_WM_CREATE()
	//ON_WM_DESTROY()
	//ON_WM_ICONERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON1, &CGhostCameraSoftDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_CAMERA, &CGhostCameraSoftDlg::OnBnClickedButtonOpenCamera)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_CAMERA, &CGhostCameraSoftDlg::OnBnClickedButtonCloseCamera)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_SUB_WINDOW, &CGhostCameraSoftDlg::OnBnClickedButtonSubWindow)
END_MESSAGE_MAP()


// CGhostCameraSoftDlg 消息处理程序

BOOL CGhostCameraSoftDlg::OnInitDialog()
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

	// TODO: 设定一下空间随主窗口大小改变
	m_itemSize.AddItemRect(IDC_BUTTON1, this);
	m_itemSize.AddItemRect(IDOK, this);
	m_itemSize.AddItemRect(IDCANCEL, this);
	m_itemSize.AddItemRect(IDC_BUTTON_OPEN_CAMERA, this);
	m_itemSize.AddItemRect(IDC_BUTTON_CLOSE_CAMERA, this);
	m_itemSize.AddItemRect(IDC_STATIC_CAMERA, this);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGhostCameraSoftDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGhostCameraSoftDlg::OnPaint()
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
HCURSOR CGhostCameraSoftDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGhostCameraSoftDlg::OnSize(UINT nType, int cx, int cy)
{
	if (0 >= cx || 0 >= cy)
	{
		return;
	}

	m_itemSize.ResizeItem();
}



void CGhostCameraSoftDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	opencv_drawing();
}


void CGhostCameraSoftDlg::OnBnClickedButtonOpenCamera()
{
	// TODO:  在此添加控件通知处理程序代码
	SetTimer(1, 33, NULL);
	return;

	// 取消从摄像头采取数据
	capture = cvCaptureFromCAM(-1);

	if (!capture)
	{
		AfxMessageBox(_T("camera open error!"));
		ExitProcess(0);
	}
	else
	{
		SetTimer(1, 100, NULL);
	}
}


void CGhostCameraSoftDlg::OnBnClickedButtonCloseCamera()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CGhostCameraSoftDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//image = cvQueryFrame(capture);
	image = cvvLoadImage("res/sample_image.jpg");
	if (image->nSize)
	{
		DrawPicToHDC(image, IDC_STATIC_CAMERA);
	}
	else
	{
		AfxMessageBox(_T("OnTimer Error!!"));
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CGhostCameraSoftDlg::DrawPicToHDC(IplImage *img, UINT ID)
{
	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	CvvImage cimg;
	cimg.CopyOf(img); // 复制图片
	cimg.DrawToHDC(hDC, &rect); // 将图片绘制到显示控件的指定区域内
	ReleaseDC(pDC);
}

void CGhostCameraSoftDlg::OnBnClickedButtonSubWindow()
{
	// TODO:  在此添加控件通知处理程序代码
	// CNetWorkCtrl dlg;
	// dlg.DoModal();
	
	pCNetWorkCtrlDlg = new CNetWorkCtrl();
	pCNetWorkCtrlDlg->Create(IDD_DIALOG_SUB);
	pCNetWorkCtrlDlg->ShowWindow(SW_SHOWNORMAL);
}
