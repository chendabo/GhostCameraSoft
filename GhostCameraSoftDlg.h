
// GhostCameraSoftDlg.h : 头文件
//

#pragma once

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "NetWorkCtrl.h"

// CGhostCameraSoftDlg 对话框
class CGhostCameraSoftDlg : public CDialogEx
{
// 构造
public:
	CGhostCameraSoftDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CGhostCameraSoftDlg();
// 对话框数据
	enum { IDD = IDD_GHOSTCAMERASOFT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

	CNetWorkCtrl *pCNetWorkCtrlDlg;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonOpenCamera();
	afx_msg void OnBnClickedButtonCloseCamera();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void DrawPicToHDC(IplImage *img, UINT ID);

	afx_msg void OnBnClickedButtonSubWindow();
};
