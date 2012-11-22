//====================================================================
//  File: BidiMain.cpp
//
//  Purpose: Main Function for Windows UI for Bidi Demo Sample
//
//  Functions:
//     WinMain      - Application entry point
//
//====================================================================
/*
	 Credits:
	 -------
	 Written by: Asmus Freytag
	 

	 Disclaimer and legal rights:
	 ---------------------------
	 Copyright (C) 1999-2009, ASMUS, Inc. All Rights Reserved. 
	 Distributed under the Terms of Use in http://www.unicode.org/copyright.html.

	 THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
	 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
	 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. 
	 IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE 
	 BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, 
	 OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, 
	 WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, 
	 ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE SOFTWARE.

	 The files bidi.rc, and resource.h are distributed together with this file and are included 
	 in the above definition of software.

	 --------------------------------------------------------------------------

	 Last updated: 04/08/09 - asmusf - finalized
*/

// If no UI mode defined, set it here - default is commandline version
// which ignores this file
#ifndef WINDOWS_UI
#define WINDOWS_UI 0
#endif

// This file only needed for this build option
#if WINDOWS_UI == 1
#pragma message("Standalone Windows Demo")

// Sample dialogs work better if compiled for Unicode
#ifndef _UNICODE
#define _UNICODE
#endif
#ifndef UNICODE
#define UNICODE
#endif

#ifndef UNREFERENCED
#define UNREFERENCED(x) x
#endif

//====================  Header Files  ======================

#include "..\bidi.h"

//====================================================================
//  Function: int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
//
//  Purpose: Application Entry Point
//
//  Comments: Registers window class, creates the dialog, and excecutes message loop.
//====================================================================

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pszCmdLine, int cmdShow )
{
	UNREFERENCED(pszCmdLine);
	UNREFERENCED(hPrevInstance);

	LPTSTR szAppName = TEXT("BidiDemo");
	WNDCLASS wc;
	MSG msg;

	wc.cbClsExtra = 0;
	wc.cbWndExtra = DLGWINDOWEXTRA;
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW );
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.lpszClassName = szAppName;
	wc.lpszMenuName = TEXT("NULL");
	wc.lpfnWndProc = (WNDPROC) BidiWndProc;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	// The IDD_BIDI resource for standalone use must have CLASS BidiDemo
	// in the bid.rc file and should not have an IDCANCEL button

	// Note for use alonside private build:
	// Other than removing the "close" button from the dialog template,
	// the dialog in bidi.rc  must match that used for WINDOWS_UI==2
	// All resource.h constants must agree as well with the private build

	RegisterClass(&wc);

	HWND hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_BIDI), 0, NULL);
	ShowWindow(hwnd, cmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!IsDialogMessage(hwnd, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

#endif
