
// GhostCameraSoftDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGhostCameraSoftDlg �Ի���



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


// CGhostCameraSoftDlg ��Ϣ��������

BOOL CGhostCameraSoftDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

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

	// TODO:  �ڴ����Ӷ���ĳ�ʼ������

	// TODO: �趨һ�¿ռ��������ڴ�С�ı�
	m_itemSize.AddItemRect(IDC_BUTTON1, this);
	m_itemSize.AddItemRect(IDOK, this);
	m_itemSize.AddItemRect(IDCANCEL, this);
	m_itemSize.AddItemRect(IDC_BUTTON_OPEN_CAMERA, this);
	m_itemSize.AddItemRect(IDC_BUTTON_CLOSE_CAMERA, this);
	m_itemSize.AddItemRect(IDC_STATIC_CAMERA, this);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGhostCameraSoftDlg::OnPaint()
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
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	opencv_drawing();
}


void CGhostCameraSoftDlg::OnBnClickedButtonOpenCamera()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	SetTimer(1, 33, NULL);
	return;

	// ȡ��������ͷ��ȡ����
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
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
}


void CGhostCameraSoftDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ
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
	cimg.CopyOf(img); // ����ͼƬ
	cimg.DrawToHDC(hDC, &rect); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC(pDC);
}

void CGhostCameraSoftDlg::OnBnClickedButtonSubWindow()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	// CNetWorkCtrl dlg;
	// dlg.DoModal();
	
	pCNetWorkCtrlDlg = new CNetWorkCtrl();
	pCNetWorkCtrlDlg->Create(IDD_DIALOG_SUB);
	pCNetWorkCtrlDlg->ShowWindow(SW_SHOWNORMAL);
}