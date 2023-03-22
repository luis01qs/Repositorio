//BFS para encontrar el ciclo más pequeño y contar cuantos hay
# include <bits/stdc++.h>
# define ll long long
# define M 10e7
 
using namespace std;

pair<int, int> BFS(vector<vector<int>> &adj, pair<int, int> &bloqueado, int o, int f)
{
    vector<bool> visitado(adj.size(), 0);
    vector<int> contador(adj.size(), 0);
    vector<int> distancia(adj.size(), M);

    distancia[o] = 0;
    contador[o] = 1;

    queue<int> q;
    q.push(o);

    int nodo;
    while(!q.empty())
    {
        nodo = q.front();
        q.pop();

        if(visitado[nodo]) continue;
        visitado[nodo] = true;

        for(auto &e:adj[nodo])
        {
            if(nodo == bloqueado.first && e == bloqueado.second) continue;
            if(nodo == bloqueado.second && e == bloqueado.first) continue;

            if(!visitado[e])
            {
                q.push(e);
                if(distancia[e] == distancia[nodo] + 1) contador[e] += contador[nodo];
                if(distancia[e] > distancia[nodo] + 1)
                {
                    distancia[e] = distancia[nodo] + 1;
                    contador[e] = contador[nodo];
                }
            }
        }
    }

    return {distancia[f], contador[f]};
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(n);

    int u, v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        u--, v--;
        edges[i] = {u,v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int tam = M;
    int res = 0;

    pair<int, int> bloqueado;
    for(int i=0;i<m;i++)
    {
        bloqueado = edges[i];
        pair<int, int> actual = BFS(adj, bloqueado, bloqueado.first, bloqueado.second);

        if(actual.first < tam)
        {
            res = 0;
            tam = actual.first;
            res = actual.second;
        }
        else if(actual.first == tam)
        {
            res += actual.second;
        }
    }

    cout << res / (tam + 1) << endl;

    return 0;
}