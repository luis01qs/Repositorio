# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int x, n;
    while(cin>>x>>n)
    {
        vector<int> canciones(n);
        for(int i=0;i<n;i++) cin>>canciones[i];

        int cont;
        int res = 0;
        int bits;
        for(int i=1;i<(1<<n);i++)
        {
            cont = 0;
            for(int j=0;j<n;j++)
            {
                if((1<<j)&i) cont += canciones[j];
                if(cont > x) break;
            }

            if(cont > res && cont <= x) res = cont, bits = i;
        }

        for(int i=0;i<n;i++)
        {
            if(bits&(1<<i)) cout << canciones[i] << " ";
        }

        cout << "sum:" << res << endl;

    }
    return 0;
}