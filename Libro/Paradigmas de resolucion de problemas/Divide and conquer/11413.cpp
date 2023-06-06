# include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> leche;

bool val(int x)
{
    int cont = 1;
    int suma = 0;
    for(int i=0;i<n;i++)
    {
        if(suma + leche[i] <= x) suma += leche[i];
        else
        {
            if(leche[i] > x) return false;
            cont++;
            suma = leche[i];
        }
    }

    return cont <= m;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    while(cin>>n>>m)
    {
        leche.resize(n);
        for(int i=0;i<n;i++) cin>>leche[i];

        int a = 1, b = 1000000000, k;
        while(a<b)
        {
            k = (a+b)/2;
            if(val(k)) b = k;
            else a = k + 1;
        }
        
        cout << a << endl;
    }
    return 0;
}