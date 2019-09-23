// dgDlg.h : header file
//

#if !defined(AFX_DGDLG_H__5AE6E60E_9FD1_49D8_BB2B_1D64F12CEBEC__INCLUDED_)
#define AFX_DGDLG_H__5AE6E60E_9FD1_49D8_BB2B_1D64F12CEBEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDgDlg dialog

class CDgDlg : public CDialog
{
// Construction
public:
	CDgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDgDlg)
	enum { IDD = IDD_DG_DIALOG };
	int		m_a1;
	int		m_a2;
	int		m_a3;
	int		m_a4;
	int		m_a5;
	int		m_c2;
	int		m_c3;
	int		m_c4;
	int		m_c5;
	int		m_c1;
	CString	m_Show1;
	CString	m_Show2;
	CString	m_Show3;
	CString	m_Show4;
	CString	m_Show5;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DGDLG_H__5AE6E60E_9FD1_49D8_BB2B_1D64F12CEBEC__INCLUDED_)
