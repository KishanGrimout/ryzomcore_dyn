// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#if !defined(AFX_CUSTOM_SNAPSHOT_H__FED230C3_4E53_4AA6_95A5_6B0F887FF7AB__INCLUDED_)
#define AFX_CUSTOM_SNAPSHOT_H__FED230C3_4E53_4AA6_95A5_6B0F887FF7AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// custom_snapshot.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CCustomSnapshot dialog

class CCustomSnapshot : public CDialog
{
// Construction
public:
	CCustomSnapshot(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCustomSnapshot)
	enum { IDD = IDD_CUSTOM_SNAPSHOT };
	CButton	KeepRatioCtrl;
	CEdit	HeightCtrl;
	CEdit	WidthCtrl;
	UINT	Height;
	UINT	Width;
	BOOL	KeepRatio;
	int		FixedSize;
	int		OutputRGB;
	//}}AFX_DATA
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomSnapshot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	void updateData();

	// Generated message map functions
	//{{AFX_MSG(CCustomSnapshot)
	afx_msg void OnKeepratio();
	afx_msg void OnFixedSize();
	afx_msg void OnGrayScale2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOM_SNAPSHOT_H__FED230C3_4E53_4AA6_95A5_6B0F887FF7AB__INCLUDED_)
