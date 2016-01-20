
// GhostCameraSoftDlg.h : ͷ�ļ�
//

#pragma once

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "NetWorkCtrl.h"

// CGhostCameraSoftDlg �Ի���
class CGhostCameraSoftDlg : public CDialogEx
{
// ����
public:
	CGhostCameraSoftDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CGhostCameraSoftDlg();
// �Ի�������
	enum { IDD = IDD_GHOSTCAMERASOFT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
