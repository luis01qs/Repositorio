# include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<bool>> dp(30, vector<bool>(210));
vector<vector<int>> precios;

void solucion(int g, int dinero)
{
    if(g == n+1) return;
    if(dp[g][dinero]) return;
    dp[g][dinero] = true;

    for(int i=0;i<precios[g].size();i++)
    {
        if(dinero - precios[g][i] >= 0) solucion(g+1, dinero - precios[g][i]);
    }
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
            for(int j=0;j<dp[i].size();j++) dp[i][j] = false;
        }

        solucion(0, m);

        int res = m+1;
        for(int i=0;i<dp[n].size();i++)
        {
            if(dp[n][i])
            {
                res = m - i;
                break;
            } 
        }

        if(res == m+1) cout << "no solution" << endl;
        else cout << res << endl;
    }
    return 0;
}