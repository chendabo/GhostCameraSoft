#ifndef ITEMRESIZE_H
#define ITMERESIZE_H

#include "afxwin.h"
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct _RESIZEINFO
{
	UINT nID;
	CWnd* pParent;
	float fLeft;
	float fRight;
	float fTop;
	float fBottom;
}RESIZEINFO;

class CItemResize
{
	CRect m_rectDlg;

	//�ڴ��ڴ���ʱ�������Ҫ�Զ�������������С�Ŀؼ�ID��
	vector<RESIZEINFO> m_vResizeID;
public:
	CItemResize(void);
	~CItemResize(void);

	void AddItemRect(UINT nID, CWnd* pParent);
	void ResizeItem();

};

#endif
