# include <bits/stdc++.h>
# define INF 10e8

using namespace std;

// edges[i] (u,v,w) de u -> v peso w (w puede ser negativo)
// n = cantidad de nodos
void Bellman_Ford(vector<vector<int>> &edges, vector<int> &distancias, int src, int n)
{
    for(int i=0;i<distancias.size();i++) distancias[i] = INF;
    distancias[src] = 0;

    int u, v, w;
    for(int k=0;k<n;k++)
    {
        for(auto &e:edges)
        {
            u = e[0];
            v = e[1];
            w = e[2];
            distancias[v] = min(distancias[v], distancias[u] + w);
        }
    }
}
