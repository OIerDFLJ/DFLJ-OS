#include<bits/stdc++.h>
#include<windows.h>
#include<Windows.h>
#include<conio.h>
#include<mmsystem.h> 
#include<fstream>
#pragma comment(lib, "Winmm.lib")

using namespace std; 
//����⣺������system("cls"); 
//�ȴ���Sleep(); 
//������Beep(Ƶ��,ʱ��); 
string s;
string key="wzybxxaql";
//������Դ����С��ƽ̨�ĸ߾��ȼ��㺯�������������ã�ΪDFLJ���˱�д 
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
//�˴����� 
void Prints(string s,int speed)//�Զ����� 
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
    puts("����");
    puts("CPU��CNQXZ-C9000S 3.2THZ");
    puts("GPU��CNQXZ-G9000S 128GB�洢 2.33THZ  30.2�� ͼ����Ⱦ/��");
    puts("RAM: 64GB  ROM: 12TB");
    puts("64λ DOSʽϵͳ     DFLJ-OS V0.14.1");
    puts("״̬");
    cout<<"CPU "<<rand()%15<<"%"<<endl;
    cout<<"GPU "<<rand()%15<<"%"<<endl;
    cout<<"RAM "<<rand()%10<<"%"<<endl;
    cout<<"ROM 1%"<<endl;
    return ;
}
void update()
{
    puts("������־��");
    puts("2023-12-23 V0.0.1 �ο�ʼ�ĵط�");
    puts("2023-12-24 V0.1.1 �����˿��������������˽���������ʼд�˵�һ������");
    puts("2023-12-28 V0.2.1 д�˸��������ͳ���");
    puts("2023-12-30 V0.3.1 ������������ɣ�J1.0��");
    puts("2023-12-31 V0.4.1 �޸��˼�������Bug��J1.1��");
    puts("2023-12-31 V0.5.1 ����������ϵͳ��M1.0��");
    puts("2024-1-23 V0.5.2  �޸�������ϵͳBug��M1.1��");
    puts("2024-1-23 V0.6.1  �����˿�������");
    puts("2024-1-24 V0.7.1  ��ʼ׼���ı��༭");
    puts("2024-2-6 V0.8.1  ����ϵͳ��ɲ�����");
    puts("2024-2-7 V0.9.1  ������һ����������");
    puts("2024-2-7 V0.10.1  ���Դ򿪰ٶȣ���ҳ��");
    puts("2024-2-13 V0.11.1  ����������ϵͳ����ʾ��M1.2��");
    puts("2024-2-24 V0.12.1  ����������߾���ʱ����1000λ����J1.2��");
    puts("2024-4-7 V0.13.1  ������������Ϊ��Dream Aria��");
    puts("2024-4-19 V0.14.1  ����ı��༭��Բ���Լ�0.7.1�汾��Ը");
    puts("2024-6-23 V0.15.1Beta  ����title�Ϳ�������׼��д�¼ܹ���Ԥ�ƻ�������ǰ���ߣ�550W�ĵ�һ��ҲҪ�ʹ��˵�ټ��ˣ������һ��0.0.1-0.13.1��Դ�뷢������ϡ�");
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
    puts("����");
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
    puts("������");
    puts("1.д");
    puts("2.��");
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
    puts("ָ���"); 
    puts("state  ���鿴�������豸״̬");
    puts("update  ��������־");
    puts("Math  ��������");
    puts("clear  ������");
    puts("chrome  ���������");
    puts("help  ������");
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
    puts("�û���DFLJ-QXDJ");
    puts("����������");
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
            puts("��֤ͨ��"); 
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
                cout<<" "<<s<<" ���ǿ����еĳ��������\n";
            }
            Prints("made with DFLJ",75);
            Prints("              ",50);
            Prints("���ڹػ�",50);
            Sleep(300);
            return 0;
        }
        system("cls");
        puts("�������,���������롣");
    } 
    system("cls");
    puts("ϵͳ��⵽��Ǳ����в");
    Prints("���ڹػ�",100);
    Sleep(1000);
    system("cls"); 
    return 0;
}

