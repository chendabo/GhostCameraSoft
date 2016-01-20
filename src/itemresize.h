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

	//在窗口创建时，添加需要自动按比例调整大小的控件ID。
	vector<RESIZEINFO> m_vResizeID;
public:
	CItemResize(void);
	~CItemResize(void);

	void AddItemRect(UINT nID, CWnd* pParent);
	void ResizeItem();

};

#endif
