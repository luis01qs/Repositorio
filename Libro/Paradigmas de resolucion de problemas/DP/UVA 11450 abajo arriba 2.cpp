# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int m, n;
        cin>>m>>n;

        vector<vector<int>> precios(n);

        int t;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            precios[i].resize(t);
            for(int j=0;j<t;j++) cin>>precios[i][j];
        }

        vector<vector<bool>> dp(n+3, vector<bool>(m+10, 0));

        

    }
    return 0;
}