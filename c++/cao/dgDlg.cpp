// dgDlg.cpp : implementation file
//
#include<iostream.h>
#include "stdafx.h"
#include "dg.h"
#include "dgDlg.h"
#define   N   5
#define   THINKING   0
#define   HUNGRY     1
#define   EATING     2
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static int state[N]={0,0,0,0,0};
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDgDlg dialog

CDgDlg::CDgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDgDlg)
	m_a1 = 0;
	m_a2 = 0;
	m_a3 = 0;
	m_a4 = 0;
	m_a5 = 0;
	m_c2 = 0;
	m_c3 = 0;
	m_c4 = 0;
	m_c5 = 0;
	m_c1 = 0;
	m_Show1 = _T("");
	m_Show2 = _T("");
	m_Show3 = _T("");
	m_Show4 = _T("");
	m_Show5 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDgDlg)
	DDX_Text(pDX, IDC_EDIT1, m_a1);
	DDV_MinMaxInt(pDX, m_a1, 0, 2);
	DDX_Text(pDX, IDC_EDIT2, m_a2);
	DDV_MinMaxInt(pDX, m_a2, 0, 2);
	DDX_Text(pDX, IDC_EDIT3, m_a3);
	DDV_MinMaxInt(pDX, m_a3, 0, 2);
	DDX_Text(pDX, IDC_EDIT4, m_a4);
	DDV_MinMaxInt(pDX, m_a4, 0, 2);
	DDX_Text(pDX, IDC_EDIT5, m_a5);
	DDV_MinMaxInt(pDX, m_a5, 0, 2);
	DDX_Text(pDX, IDC_EDIT7, m_c2);
	DDX_Text(pDX, IDC_EDIT8, m_c3);
	DDX_Text(pDX, IDC_EDIT9, m_c4);
	DDX_Text(pDX, IDC_EDIT10, m_c5);
	DDX_Text(pDX, IDC_EDIT6, m_c1);
	DDX_Text(pDX, IDC_TEXT, m_Show1);
	DDX_Text(pDX, IDC_TEXT2, m_Show2);
	DDX_Text(pDX, IDC_TEXT3, m_Show3);
	DDX_Text(pDX, IDC_TEXT4, m_Show4);
	DDX_Text(pDX, IDC_TEXT5, m_Show5);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDgDlg, CDialog)
	//{{AFX_MSG_MAP(CDgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDgDlg message handlers

BOOL CDgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDgDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
char* test(int i)
{
     char*r;    
	if ((state[ i ] == HUNGRY) && (state [ (i-1+N) % N] != EATING) && (state [ (i+1) % N] != EATING))
           {
                state[ i] = EATING;
				r="可以吃饭。";
            }
	   else r="位哲学家请等待……";
	   return r;
}
#include<iostream.h>
void CDgDlg::OnOK() 
{
    UpdateData(true);
	int*p[N]={&m_a1,&m_a2,&m_a3,&m_a4,&m_a5};	
	int*q[N]={&m_c1,&m_c2,&m_c3,&m_c4,&m_c5};
		for(int j=0;j<N;j++)
		{
			char*v;
			if(*p[j]==0)
			{
              v="正在思考。"; 
			}
			if(*p[j]==1)
			{
              state[j]=HUNGRY; 
			  v=test(j); 
			}
			else if(*p[j]==2)	
			{
			   state[j]=THINKING;
			   v="已经吃饱，开始思考了。";
			}
	         *q[j]=j+1;	
			 switch(j)
			 {
			 case 0: m_Show1=v;break;
			 case 1: m_Show2=v;break;
			 case 2: m_Show3=v;break;
			 case 3: m_Show4=v;break;
			 case 4: m_Show5=v;break;
			 
			 }
			 UpdateData(false);
		}


	//CDialog::OnOK();
}
