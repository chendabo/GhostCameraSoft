#pragma once


// CNetWorkCtrl �Ի���

class CNetWorkCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CNetWorkCtrl)

public:
	CNetWorkCtrl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNetWorkCtrl();

// �Ի�������
	enum { IDD = IDD_DIALOG_SUB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
