// header files
#include <windows.h>
#include <stdio.h> // for FileIO functions
#include <stdlib.h> // for exit()
#include "OGL.h"

// TODO
//OpenGL Header file
#include <GL/glew.h> // This MUST be above "gl.h"
#include <GL/gl.h>

// TODO
// OpenGL Libraries
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "OpenGL32.lib")

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global variable declarations
HWND ghwnd_gdj = NULL;
BOOL gbFullScreen_gdj = FALSE;
HGLRC ghrc_gdj = NULL;
FILE* gpFile_gdj = NULL;
BOOL gbActiveWindow_gdj = FALSE;
HDC ghdc_gdj = NULL;

// ProgramblePipeline related Global Variables
GLuint shaderProgramObject;

// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// function declarations
	int initialize(void);
	void display(void);
	void update(void);
	void uninitialize(void);

	// variable declarations
	WNDCLASSEX wndclass_gdj;
	HWND hwnd_gdj;
	MSG msg_gdj;
	TCHAR szAppName_gdj[] = TEXT("MyWindow");
	BOOL bDone_gdj = FALSE;
	int xOrg_gdj, yOrg_gdj, x_gdj, y_gdj, width_gdj, height_gdj;
	int iRetVal_gdj = 0;

	// code
	if (fopen_s(&gpFile_gdj, "Log.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Creation of log file failed. Exiting..."), TEXT("FileI/O Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile_gdj, "Log file is successfully created.\n");
	}

	// code
	// Initialization of WNDCLASSEX structure
	wndclass_gdj.cbSize = sizeof(WNDCLASSEX);
	wndclass_gdj.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass_gdj.cbClsExtra = 0;
	wndclass_gdj.cbWndExtra = 0;
	wndclass_gdj.lpfnWndProc = WndProc;
	wndclass_gdj.hInstance = hInstance;
	wndclass_gdj.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass_gdj.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass_gdj.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass_gdj.lpszClassName = szAppName_gdj;
	wndclass_gdj.lpszMenuName = NULL;
	wndclass_gdj.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// Registering above WNDCLASSEX
	RegisterClassEx(&wndclass_gdj);

	x_gdj = (GetSystemMetrics(SM_CXSCREEN) - WIN_WIDTH) / 2;
	y_gdj = (GetSystemMetrics(SM_CYSCREEN) - WIN_HEIGHT) / 2;

	// Create Window
	hwnd_gdj = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName_gdj,
		TEXT("OpenGL Window Gitanjali Dilip Jedhe"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		x_gdj,
		y_gdj,
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ghwnd_gdj = hwnd_gdj;

	// TODO
	// Initialize 


	// Show the window
	ShowWindow(hwnd_gdj, iCmdShow);

	// foregrounding and focusing window
	SetForegroundWindow(hwnd_gdj);
	SetFocus(hwnd_gdj);

	// Game Loop
	while (bDone_gdj == FALSE)
	{
		if (PeekMessage(&msg_gdj, NULL, 0, 0, PM_REMOVE))
		{
			if (msg_gdj.message == WM_QUIT)
				bDone_gdj = TRUE;
			else
			{
				TranslateMessage(&msg_gdj);
				DispatchMessage(&msg_gdj);
			}
		}
		else
		{
			// TODO
		}
	}

	// TODO;

	return((int)msg_gdj.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// function declarations
	void ToggleFullScreen(void);
	void resize(int, int);

	// code
	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActiveWindow_gdj = TRUE;
		break;

	case WM_KILLFOCUS:
		gbActiveWindow_gdj = FALSE;
		break;

	case WM_ERASEBKGND:
		//break;
		return 0;

	case WM_CHAR:
		switch (wParam)
		{
		case 'F':
		case 'f':
			ToggleFullScreen();
			break;

		case 27:
			PostQuitMessage(0);
			//DestroyWindow(hwnd);
			break;

		default:
			break;
		}
		break;

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullScreen(void)
{
	// variable declarations
	static DWORD dwStyle_gdj;
	static WINDOWPLACEMENT wp_gdj;
	MONITORINFO mi_gdj;

	// code
	wp_gdj.length = sizeof(WINDOWPLACEMENT);

	if (gbFullScreen_gdj == FALSE)
	{
		dwStyle_gdj = GetWindowLong(ghwnd_gdj, GWL_STYLE);
		if (dwStyle_gdj & WS_OVERLAPPEDWINDOW)
		{
			mi_gdj.cbSize = sizeof(MONITORINFO);

			if (GetWindowPlacement(ghwnd_gdj, &wp_gdj) && GetMonitorInfo(MonitorFromWindow(ghwnd_gdj, MONITORINFOF_PRIMARY), &mi_gdj))
			{
				SetWindowLong(ghwnd_gdj, GWL_STYLE, dwStyle_gdj & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd_gdj, HWND_TOP, mi_gdj.rcMonitor.left, mi_gdj.rcMonitor.top, mi_gdj.rcMonitor.right - mi_gdj.rcMonitor.left, mi_gdj.rcMonitor.bottom - mi_gdj.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
			ShowCursor(FALSE);
			gbFullScreen_gdj = TRUE;
		}
	}
	else
	{
		SetWindowLong(ghwnd_gdj, GWL_STYLE, dwStyle_gdj | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd_gdj, &wp_gdj);
		SetWindowPos(ghwnd_gdj, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
		gbFullScreen_gdj = FALSE;
	}
}

int initialize(void)
{
	// TODO

	return 0;
}

void PrintGLInfo(void)
{
	// Local Variable Declarations
	GLint NumExtensions_gdj = 0;

	// Code
	fprintf(gpFile_gdj, "OpenGL Vendor   : %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile_gdj, "OpenGL Renderer : %s\n", glGetString(GL_RENDERER));
	fprintf(gpFile_gdj, "OpenGL Version  : %s\n", glGetString(GL_VERSION));
	fprintf(gpFile_gdj, "GLSL Version    : %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	glGetIntegerv(GL_NUM_EXTENSIONS, &NumExtensions_gdj);

	fprintf(gpFile_gdj, "Number of Supported Extensions : %d\n", NumExtensions_gdj);

	for (int i = 0; i < NumExtensions_gdj; i++)
	{
		fprintf(gpFile_gdj, "%s\n", glGetStringi(GL_EXTENSIONS, i));
	}
}

void resize(int width, int height)
{
	// TODO
}

void display(void)
{
	// TODO
}

void update(void)
{
	// TODO
	// code
}

void uninitialize(void)
{
	// TODO
}
