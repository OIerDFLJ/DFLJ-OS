#include<bits/stdc++.h>
#include<windows.h>
#include<Windows.h>
#include<conio.h>
#include<mmsystem.h> 
#include<fstream>
#pragma comment(lib, "Winmm.lib")

using namespace std; 
//命令库：清屏：system("cls"); 
//等待：Sleep(); 
//声音：Beep(频率,时间); 
string s;
string key="wzybxxaql";
//以下是源自于小猴平台的高精度计算函数，无其他作用，为DFLJ本人编写 
int A[1010], B[1010], ans[1010], x;
string a, b;

void s2BIG(string s, int a[])
{
    int l = s.length();
    for (int i = 1; i <= l; i++)
    {
        a[i] = s[l - i] - '0';
    }
    a[0] = l; 
}

void addBIG(int x[], int y[], int z[])
{
    z[0] = max(x[0], y[0]);
    for (int i = 1; i <= z[0]; i++)
    {
        z[i] = x[i] + y[i];
    }
    for (int i = 1; i <= z[0]; i++)
    {
        z[i+1] += z[i] / 10;
        z[i] %= 10;
        
        if (z[z[0]+1] > 0) z[0]++;
    }
}

void printBIG(int a[])
{
    int l = a[0]; 
    for (int i = l; i >= 1; i--) 
    {
        cout << a[i];
    }
    cout << endl; 
}

bool cmpBIG(int x[], int y[])
{
    int lx = x[0], ly = y[0];
    if (lx != ly) return lx < ly;
    for (int i = lx; i >= 1; i--)
    {
        if (x[i] != y[i]) return x[i] < y[i];
    }
    return false; 
}

void mulBIG(int x[], int y, int z[])
{
    z[0] = x[0];
    for (int i = 1; i <= z[0]; i++) 
    z[i] = x[i] * y;
    for (int i = 1; i <= z[0]; i++) 
    {
        z[i + 1] += z[i] / 10;
        z[i] %= 10;
        if (z[z[0]+1] > 0)
        {
            z[0]++;
        }
    }
}

void subBIG(int x[], int y[], int z[])
{
    z[0] = max(x[0], y[0]);
    for (int i = 1; i <= z[0]; i++) 
    z[i] = x[i] - y[i];
    for (int i = 1; i <= z[0]; i++)
    {
        if (z[i] < 0)
        {
        z[i] += 10;
        z[i+1]--;
    }
}

while (z[z[0]] == 0 && z[0] > 1) z[0]--;
}

void divBIG(int x[], int y, int z[])
{
    z[0] = x[0];
    int r = 0; 
    for (int i = z[0]; i >= 1; i--)
    {
        int t = r * 10 + x[i];
        z[i] = t / y;
        r = t % y;
    }
    while (z[z[0]] == 0 && z[0] > 1) z[0]--; 
}
//此处结束 
void Prints(string s,int speed)//自动换行 
{
    for(int i=0; i<s.size(); i++)
    {
        cout<<s[i];
        Sleep(speed);
    }
    cout<<endl;
    return ;
}

void state()
{
    puts("配置");
    puts("CPU：CNQXZ-C9000S 3.2THZ");
    puts("GPU：CNQXZ-G9000S 128GB存储 2.33THZ  30.2兆 图形渲染/秒");
    puts("RAM: 64GB  ROM: 12TB");
    puts("64位 DOS式系统     DFLJ-OS V0.14.1");
    puts("状态");
    cout<<"CPU "<<rand()%15<<"%"<<endl;
    cout<<"GPU "<<rand()%15<<"%"<<endl;
    cout<<"RAM "<<rand()%10<<"%"<<endl;
    cout<<"ROM 1%"<<endl;
    return ;
}
void update()
{
    puts("更新日志：");
    puts("2023-12-23 V0.0.1 梦开始的地方");
    puts("2023-12-24 V0.1.1 更改了开场动画，增加了进度条，开始写了第一条命令");
    puts("2023-12-28 V0.2.1 写了更多的命令和程序");
    puts("2023-12-30 V0.3.1 计算器程序完成（J1.0）");
    puts("2023-12-31 V0.4.1 修复了计算器的Bug（J1.1）");
    puts("2023-12-31 V0.5.1 增加了密码系统（M1.0）");
    puts("2024-1-23 V0.5.2  修复了密码系统Bug（M1.1）");
    puts("2024-1-23 V0.6.1  更改了开场音乐");
    puts("2024-1-24 V0.7.1  开始准备文本编辑");
    puts("2024-2-6 V0.8.1  密码系统完成不回显");
    puts("2024-2-7 V0.9.1  增加了一键清屏功能");
    puts("2024-2-7 V0.10.1  可以打开百度（网页）");
    puts("2024-2-13 V0.11.1  更新了密码系统的显示（M1.2）");
    puts("2024-2-24 V0.12.1  计算器进入高精度时代（1000位）（J1.2）");
    puts("2024-4-7 V0.13.1  更换开机音乐为《Dream Aria》");
    puts("2024-4-19 V0.14.1  完成文本编辑，圆了自己0.7.1版本的愿");
    puts("2024-6-23 V0.15.1Beta  更新title和开机音，准备写新架构，预计会在中秋前上线，550W的第一代也要和大家说再见了，后续我会把0.0.1-0.13.1的源码发在洛谷上。");
    return ;
}
void Math()
{
    char op;
    cin >> op;
    if (op == '+')
    {
        cin >> a >> b;
        s2BIG(a, A);
        s2BIG(b, B);
        addBIG(A, B, ans);
        printBIG(ans);
        return ; 
    }
    if (op == '-')
    {
        cin >> a >> b;
        s2BIG(a, A);
        s2BIG(b, B);
        if (cmpBIG(A, B))
        {
            subBIG(B, A, ans);
            printBIG(ans);
        }
        else
        {
            subBIG(A, B, ans);
            cout<<"-";
            printBIG(ans);
        }
        
        return ; 
    }
    if (op == '*')
    {
        cin >> a >> x;
        s2BIG(a, A);
        mulBIG(A, x, ans);
        printBIG(ans);
        return ; 
    }
    if (op == '/')
    {
        cin >> a >> x;
        s2BIG(a, A);
        divBIG(A, x, ans);
        printBIG(ans);
        return ; 
    }
    puts("错误");
    return ; 
} 

void clear()
{
    system("cls");
    return ;    
} 
void chrome()
{
    system("explorer https://baidu.com");
    return ;
}
void test()
{
    puts("操作：");
    puts("1.写");
    puts("2.读");
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
void help()
{
    puts("指令表："); 
    puts("state  ：查看设置与设备状态");
    puts("update  ：更新日志");
    puts("Math  ：计算器");
    puts("clear  ：清屏");
    puts("chrome  ：打开浏览器");
    puts("help  ：帮助");
 } 
void startmusic()
{
    Beep(260,1000);
    Beep(520,1000);
} 
int main()
{
    int cnt=0;
    srand(time(0));
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("                                       _______________________ _______________________                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       |_____________________| |_____________________|                                     ");
	puts("                                       DFLJ-OS V1.0.0 Beta                                                                 ");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
    Sleep(2000);
    system("cls"); 
	Sleep(500); 
    puts("用户：DFLJ-QXDJ");
    puts("请输入密码");
    for(int i=1; i<=3; i++)
    {
        s="";
        char ch;
        ch = _getch();
        cout<<"*";
        while (ch != '\n' && ch != '\r')
        {
            s=s+ch;
            ch = _getch();
            cout<<"*";
        }
        if(s==key)
        {
            cout<<endl;
            puts("验证通过"); 
            system("PAUSE"); 
            system("cls");
            Sleep(1);
            s="";
            startmusic();
            s="loading......";
            Prints(s,180);
            Sleep(500);
            for(int i=1; i<=100; i+=1)
            {
                system("CLS");
                for(int j=1; j<=i; j++)
                {
                    cout<<"-";
                }
                cout<<endl;
                cout<<i;
                puts("%");
                Sleep(rand()%100);
             }
             system("cls"); 
            while(1)
            {
                cout<<"<550W>";
                cin>>s;
                if(s=="shut")
                {
                    system("cls");
                    break;
                }
                if(s=="state")
                {
                    state();
                    continue;
                } ;
                if(s=="update")
                {
                    update(); 
                    continue;
                } 
                if(s=="Math")
                {
                    system("start Math.exe");
                    continue;
                }
                if(s=="clear")
                {
                    clear();
                    continue;
                }
                if(s=="exp")
                {
                    system("start exp.exe");
                    continue;
                }
                if(s=="help")
                {
                    help();
                    continue;
                }
                if(s=="test")
                {
                    system("start test.exe");
                    continue;
                }
                cout<<" "<<s<<" 不是可运行的程序或命令\n";
            }
            Prints("made with DFLJ",75);
            Prints("              ",50);
            Prints("正在关机",50);
            Sleep(300);
            return 0;
        }
        system("cls");
        puts("密码错误,请重新输入。");
    } 
    system("cls");
    puts("系统检测到有潜在威胁");
    Prints("正在关机",100);
    Sleep(1000);
    system("cls"); 
    return 0;
}

