# include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> precios;
vector<vector<int>> dp(210, vector<int>(30));

int compras(int dinero, int g)
{
    if(dinero > m) return -1000000000;
    if(g == n) return dinero;
    if(dp[dinero][g] != -1) return dp[dinero][g];

    int res = -1;
    for(int i=0;i<precios[g].size();i++)
    {
        res = max(res, compras(dinero + precios[g][i], g+1));
    }

    dp[dinero][g] = res;
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
        
        int t;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            precios[i].resize(t);
            for(int j=0;j<t;j++) cin>>precios[i][j];
        }

        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[i].size();j++) dp[i][j] = -1;
        }

        int res = compras(0,0);

        if(res < 0) cout << "no solution" << endl;
        else cout << res << endl;

    }

    return 0;
}