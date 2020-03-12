#include <windows.h>
#include <tchar.h>
HINSTANCE g_hInstance;
LRESULT CALLBACK WndProc(
	HWND hWnd, //���ڵľ��
	UINT nMsg, //��Ϣ��ID��
	WPARAM wParam, //��Ϣ����Ӧ�Ĳ���
	LPARAM lParam //��Ϣ����Ӧ�Ĳ���
)
{
	switch (nMsg)
	{
	case WM_DESTROY: //�������ٵ���Ϣ
		PostQuitMessage(0); //�����˳���Ϣ
		return 0;
		break;
	}


	//����ȱʡ����Ϣ������
	return DefWindowProc(hWnd, nMsg, wParam, lParam);
}
//ע�ᴰ����
BOOL MyRegister(LPSTR pszClassName)
{
	ATOM nAtom;
	WNDCLASS wc = { 0 };
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = g_hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = pszClassName;


	nAtom = RegisterClass(&wc);
	if (0 == nAtom)
	{
		MessageBox(NULL, "Register Failed", "Error", MB_OK | MB_ICONWARNING);
		return FALSE;
	}
	else
	{
		MessageBox(NULL, "Register Successed", "Successed", MB_OK);
	}

	return TRUE;
}

HWND MyCreate(LPSTR pszClassName)
{
	HWND hWnd = CreateWindow(pszClassName,
		"HelloWnd",
		WS_OVERLAPPEDWINDOW,
		100, 100, 300, 500, NULL, NULL,
		g_hInstance, NULL
	);
	if (NULL == hWnd)
	{
		MessageBox(NULL, "Create Window Failed", "Error", MB_OK | MB_ICONWARNING);
		return NULL;
	}
	else
	{
		MessageBox(NULL, "Create Window Successed", "Successed", MB_OK);
	}
	return hWnd;
}

void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}

void Message()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0)) //����Ϣ���л�ȡ��Ϣ
	{
		DispatchMessage(&msg); //�ɷ���Ϣ
	}
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,//     hInstance -  Ӧ�ó����ʵ�����     
	LPSTR pszCmdLine,
	int nCmdShow
)
{
	HWND hWnd = NULL;
	BOOL bRet = FALSE;
	bRet = MyRegister(LPSTR("MyWnd")); // ע��Ĵ���������ʲô��Ӧ�ô�ʲô
	if (FALSE == bRet)
	{
		MessageBox(NULL, "Register Window Failed", "Failed", MB_OK);
		return -1;
	}
	else
	{
		MessageBox(NULL, "Register Window Success", "Success", MB_OK);
	}
	g_hInstance = hInstance;

	hWnd = MyCreate(LPSTR("MyWnd"));

	if (NULL == hWnd)
	{
		MessageBox(NULL, "Create Window Failed", "Failed", MB_OK);
	}

	DisplayWnd(hWnd);

	Message();

	return 0;
}