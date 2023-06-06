# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    ll n, m;

    int ite = 1;
    while(cin>>n>>m)
    {
        if(n==0) break;
        vector<vector<char>> mapa(n+2, vector<char>(m+2));

        for(int i=0;i<n+2;i++)
        {
            for(int j=0;j<m+2;j++) mapa[i][j] = '.';
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++) cin>>mapa[i][j];
        }

        if(ite != 1) cout << endl;
        cout << "Field #" << ite << ":" << endl;
        ite++;
        int cont = 0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(mapa[i][j] == '*') cout << mapa[i][j];
                else
                {
                    cont = 0;
                    if(mapa[i-1][j-1] == '*') cont++;
                    if(mapa[i-1][j] == '*') cont++;
                    if(mapa[i-1][j+1] == '*') cont++;
                    if(mapa[i][j-1] == '*') cont++;
                    if(mapa[i][j+1] == '*') cont++;
                    if(mapa[i+1][j-1] == '*') cont++;
                    if(mapa[i+1][j] == '*') cont++;
                    if(mapa[i+1][j+1] == '*') cont++;
                    cout << cont;
                }
            }
            cout << endl;
        }
    }
    return 0;
}