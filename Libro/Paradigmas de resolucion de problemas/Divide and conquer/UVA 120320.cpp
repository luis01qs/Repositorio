# include <bits/stdc++.h>

using namespace std;

int n;
vector<int> saltos;

bool procedimiento(int k)
{
    int anterior = 0;
    for(int i=0;i<n;i++)
    {
        if(saltos[i] - anterior > k) return false;
        if(saltos[i] - anterior == k) k--;
        anterior = saltos[i];
    }
    return true;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;

    for(int zz=0;zz<tt;zz++)
    {
        cin>>n;
        saltos.resize(n);
        for(int i=0;i<n;i++) cin>>saltos[i];

        int k;
        int a = 0, b = 10e8;

        while(a < b)
        {
            k = (a+b)/2;
            if(procedimiento(k)) b = k;
            else a = k + 1;
        }
        
        cout << "Case " << zz+1 << ": " << a << endl;
    }
    return 0;
}