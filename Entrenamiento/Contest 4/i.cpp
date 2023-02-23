# include <bits/stdc++.h>
# define ll long long
# define INF 10e17
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
 
void Bellman_Ford(vector<vector<ll>> &edges, vector<ll> &costos, int src, vector<ll> &distancias, int m, int n)
{
    distancias[src] = 0;
 
    ll u, v, w;
    for(int k=0;k<10;k++)
    {
        for(auto &e:edges)
        {
            u = e[0];
            v = e[1];
            w = e[2];
            distancias[v] = min(distancias[v], distancias[u] - w + costos[v]);
        }
    }
    return;
}
 
int main()
{
    IOS;
    freopen("prueba.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
 
    vector<vector<ll>> datos(n+1);
    vector<vector<ll>> edges;
    vector<ll> distancias(n+1, INF);
    vector<ll> costos(n+1);
 
    int tam;
    vector<ll> a(3);
    for(int i=0;i<n;i++)
    {
        cin>>costos[i];
        tam = min(m, n-i);
        for(int j=0;j<tam;j++)
        {
            cin>>a[2];
            a[0] = i;
            a[1] = i + j + 1;
            //cout << a[0] << " " << a[1] << " " << a[2] << endl;
            edges.push_back(a);
        }
    }

    costos[n] = 0;
    Bellman_Ford(edges, costos, 0, distancias, m, n);
    cout << costos[0] + distancias[n] << endl;
 
    return 0;
}