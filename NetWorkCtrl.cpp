// NetWorkCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "GhostCameraSoft.h"
#include "NetWorkCtrl.h"
#include "afxdialogex.h"


// CNetWorkCtrl 对话框

IMPLEMENT_DYNAMIC(CNetWorkCtrl, CDialogEx)

CNetWorkCtrl::CNetWorkCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNetWorkCtrl::IDD, pParent)
{

}

CNetWorkCtrl::~CNetWorkCtrl()
{
}

void CNetWorkCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNetWorkCtrl, CDialogEx)
END_MESSAGE_MAP()


// CNetWorkCtrl 消息处理程序
