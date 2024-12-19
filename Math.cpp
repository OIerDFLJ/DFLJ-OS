#include<bits/stdc++.h>
#include<windows.h>
#include<Windows.h>
#include<conio.h>
#include<mmsystem.h> 
#include<fstream>
#pragma comment(lib, "Winmm.lib")

using namespace std;
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
    puts("´íÎó");
    return ; 
} 

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	Math(); 
	system("Pause");
	return 0;
}

