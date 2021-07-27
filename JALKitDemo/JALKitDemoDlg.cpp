
// JALKitDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JALKitDemo.h"
#include "JALKitDemoDlg.h"
#include "afxdialogex.h"
#include <memory>
using namespace std;

// 静态调用需要加载lib
#define STATIC_CALL
#ifdef STATIC_CALL
	#pragma comment (lib,"JALKitDll.lib")
#endif


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJALKitDemoDlg 对话框




CJALKitDemoDlg::CJALKitDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJALKitDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJALKitDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CJALKitDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CJALKitDemoDlg 消息处理程序
void TestSharedPtr(shared_ptr<int> ptr)
{
	int count = ptr.use_count();
	//count=2
}

BOOL CJALKitDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码

	
	#ifdef STATIC_CALL
		// 静态调用
		JALHello *hello = new JALHello();
		string string1 = hello->HelloWorld();

		JALBye *bye = new JALBye();
		string string2 = bye->ByeMustStaticCall();
		// delete...
	#else
		// 动态调用
		HMODULE handle = LoadLibraryA("JALKitDll.dll");
		pFunCreateBye createBye = (pFunCreateBye)GetProcAddress(handle,"CreateBye");
		if (createBye)
		{
			JALBye *byebye = createBye();
			string string3 = byebye->Bye();
			// 需要加载lib，否则这句编译不过,因为ByeMustStaticCall不是虚函数，没有动态绑定
			// 解决办法：加载lib，或者，函数加上virtual
			//string string4 = byebye->ByeMustStaticCall();

			// delete...
		}
	#endif

	
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CJALKitDemoDlg::OnPaint()
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
HCURSOR CJALKitDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

