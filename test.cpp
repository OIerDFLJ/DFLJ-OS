#include<bits/stdc++.h>
#include<windows.h>
#include<Windows.h>
#include<conio.h>
#include<mmsystem.h> 
#include<fstream>
#pragma comment(lib, "Winmm.lib")
using namespace std;
void test()
{
    puts("²Ù×÷£º");
    puts("1.Ð´");
    puts("2.¶Á");
    int a;
    cin>>a; 
    switch(a)
    {
        case 1:
        {
            ofstream ofs;
            ofs.open("test.txt", ios::out);
            string sf;
            getline(cin,sf);
            while(sf!="exit")
            {
                ofs<<sf<<endl;
                getline(cin,sf);
            }
            ofs.close();
        }
        case 2:
        {
            ifstream ifs;
            ifs.open("test.txt", ios::in);
            string sf="";
            while(getline(ifs,sf))
            {
                cout<<sf<<endl;
            }
        } 
     } 
} 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	test();
	system("Pause");
	return 0;
}

