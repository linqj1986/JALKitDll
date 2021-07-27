
// JALKitDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JALKitDemo.h"
#include "JALKitDemoDlg.h"
#include "afxdialogex.h"
#include <memory>
using namespace std;

// ��̬������Ҫ����lib
#define STATIC_CALL
#ifdef STATIC_CALL
	#pragma comment (lib,"JALKitDll.lib")
#endif


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJALKitDemoDlg �Ի���




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


// CJALKitDemoDlg ��Ϣ�������
void TestSharedPtr(shared_ptr<int> ptr)
{
	int count = ptr.use_count();
	//count=2
}

BOOL CJALKitDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//ShowWindow(SW_MAXIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	
	#ifdef STATIC_CALL
		// ��̬����
		JALHello *hello = new JALHello();
		string string1 = hello->HelloWorld();

		JALBye *bye = new JALBye();
		string string2 = bye->ByeMustStaticCall();
		// delete...
	#else
		// ��̬����
		HMODULE handle = LoadLibraryA("JALKitDll.dll");
		pFunCreateBye createBye = (pFunCreateBye)GetProcAddress(handle,"CreateBye");
		if (createBye)
		{
			JALBye *byebye = createBye();
			string string3 = byebye->Bye();
			// ��Ҫ����lib�����������벻��,��ΪByeMustStaticCall�����麯����û�ж�̬��
			// ����취������lib�����ߣ���������virtual
			//string string4 = byebye->ByeMustStaticCall();

			// delete...
		}
	#endif

	
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CJALKitDemoDlg::OnPaint()
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
HCURSOR CJALKitDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

