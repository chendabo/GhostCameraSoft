// NetWorkCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GhostCameraSoft.h"
#include "NetWorkCtrl.h"
#include "afxdialogex.h"


// CNetWorkCtrl �Ի���

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


// CNetWorkCtrl ��Ϣ�������
