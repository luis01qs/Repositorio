# include <bits/stdc++.h>
# define ll long long
# define INF 10e17
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
 
void Bellman_Ford(vector<vector<ll>> &edges, int src, vector<ll> &distancias, int m)
{
    distancias[src] = 0;
 
    ll u, v, w;
    for(int k=1;k<m+1;k++)
    {
        for(auto &e:edges)
        {
            u = e[0];
            v = e[1];
            w = e[2];
            distancias[v] = min(distancias[v], distancias[u] + w);
        }
    }
    return;
}
 
int main()
{
    IOS;
    //freopen("prueba.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
 
    vector<vector<ll>> datos(n+1);
    vector<vector<ll>> edges;
    vector<ll> distancias(n+1, INF);
    vector<ll> costos(n+1);
 
    int tam;
    int cont = 0;
    for(int i=0;i<n;i++)
    {
        tam = min(m, n-i);
        datos[i].resize(tam+1);
        for(int j=0;j<tam+1;j++)
        {
            cin>>datos[i][j];
        }
        cont += tam;
    }
 
    datos[n].push_back(0);
    edges.resize(cont);
    vector<ll> a(3);
 
    cont = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<datos[i].size();j++)
        {
            a[0] = i;
            a[1] = i + j;
            a[2] = datos[a[1]][0] - datos[a[0]][j];
            edges[cont]= a;
            cont++; 
            //cout << a[0] << " " << a[1] << " -> " << a[2] << endl;
        }
    }
 
    Bellman_Ford(edges, 0, distancias, m);
    cout << datos[0][0] + distancias[n] << endl;
 
    return 0;
}