//MST con prim
# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
# define mp(a,b) make_pair(a,b)
# define mt(x, y, z) make_tuple(x, y, z)

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<pair<int, int>>> conexiones(n+1);

        int u, v, w;
        fore(i, 0, m)
        {
            cin>>u>>v>>w;
            w *= -1;
            conexiones[u].pb(mp(w,v));
            conexiones[v].pb(mp(w,u));
        }

        priority_queue<pair<int, int>> posibles;
        vector<bool> nodos(n+1);
        nodos[1] = true;

        for(auto &e:conexiones[1]) posibles.push(e);

        int maximo = 0;
        int tam = 1;
        pair<int, int> aux;
        while(tam < n)
        {
            aux = posibles.top();
            if(nodos[aux.second] == true) posibles.pop();
            else
            {
                maximo = max(maximo, aux.first*-1);
                nodos[aux.second] = true;
                for(auto &i:conexiones[aux.second]) posibles.push(i);
                tam++;
            }
        }

        cout << maximo << endl;
    }
    return 0;
}