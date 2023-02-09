# include <bits/stdc++.h>
# define ll long long

using namespace std;

int n, m;
ll p = 0;

ll base_n(ll x, int n)
{
    ll k = 0;
    for(int i=0;x!=0;i++)
    {
        k += (x % n) * pow(10, i);
        x /= n;
    }
    return k;
}

void recorrido(set<ll> &res, int x, int y, ll cont, vector<vector<ll>> &piedras)
{
    cont *= piedras[x][y];
    if(x == n-1 && y == m-1)
    {
         res.insert(cont);
         p++;
         return;
    }

    if(x < n-1) recorrido(res, x+1, y, cont, piedras);
    if(y < m-1) recorrido(res, x, y+1, cont, piedras);
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>m;
        vector<vector<ll>> piedras(n, vector<ll>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin>>piedras[i][j];
        }

        set<ll> res;
        recorrido(res, 0, 0, 1, piedras);
        cout << p << endl;
        //for(auto &e:res) cout << e << endl;
    }
    return 0;
}