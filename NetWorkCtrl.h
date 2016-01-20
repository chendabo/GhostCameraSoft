#pragma once


// CNetWorkCtrl 对话框

class CNetWorkCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CNetWorkCtrl)

public:
	CNetWorkCtrl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNetWorkCtrl();

// 对话框数据
	enum { IDD = IDD_DIALOG_SUB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
