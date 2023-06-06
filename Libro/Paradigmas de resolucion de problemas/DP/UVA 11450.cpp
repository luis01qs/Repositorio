# include <bits/stdc++.h>

using namespace std;

int m, n;
vector<vector<int>> precios;
vector<vector<int>> memo(210, vector<int>(30));

int shop(int dinero, int g)
{
    if(dinero < 0) return -1000000000;
    if(g == n) return m - dinero;
    if(memo[dinero][g] != -1) return memo[dinero][g];

    int res = -1;
    for(int i=0;i<precios[g].size();i++)
    {
        res = max(res, shop(dinero - precios[g][i], g+1));
    }

    memo[dinero][g] = res;
    return res;
}

int main()
 {
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>m>>n;
        precios.resize(n);

        int tam;
        for(int i=0;i<n;i++)
        {
            cin>>tam;
            precios[i].resize(tam);
            for(int j=0;j<tam;j++) cin>>precios[i][j];
        }

        for(int i=0;i<memo.size();i++)
        {
            for(int j=0;j<memo[i].size();j++) memo[i][j] = -1;
        }

        int res = shop(m, 0);
        
        if(res < 0) cout << "no solution" << endl;
        else cout << res << endl;
    }
    return 0;
 }