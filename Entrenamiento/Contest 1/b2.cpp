# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
# define mp(a,b) make_pair(a,b)

using namespace std;

vector<vector<ll>> edges;

// ********************************************************************************Union_find
//Nodo a buscar el padre y vector con los padres de cada nodo
int findd(ll nodo, vector<ll> &padres)
{
    if(padres[nodo] != nodo) padres[nodo] = findd(padres[nodo], padres);
    return padres[nodo];
}

//Se puede hacer también un void cuando no nos interesa si se hizo o no la unión
//Nodos a conectar, vector de padre de cada nodo, altura del árbol de cada nodo
bool unionn(int nodo1, int nodo2, ll costo, vector<ll> &padres, vector<ll> &altura, vector<ll> &distancias, vector<vector<int>> &hijos)
{
    if(findd(nodo1, padres) == findd(nodo2, padres)) return false;
    int padre1 = padres[nodo1];
    int padre2 = padres[nodo2];

    for(auto &e:hijos[padre1]) distancias[e] += costo*hijos[padre2].size();
    for(auto &e:hijos[padre2]) distancias[e] += costo*hijos[padre1].size();

    if(altura[padre1] >= altura[padre2])
    {
        if(altura[padre1] == altura[padre2]) altura[padre1]++;
        padres[padre2] = padre1;
        for(auto &e:hijos[padre2]) hijos[padre1].pb(e);
    }
    else
    {
        padres[padre1] = padre2;
        for(auto &e:hijos[padre1]) hijos[padre2].pb(e);
    }

    return true;
}
// *********************************************************************************Fin Union_find

//Cantidad de nodos, vector de conexiones (peso, nodo1, nodo2)
vector<ll> kruskal(int n, vector<vector<ll>> &edges)
{
    vector<ll> distancias(n+1, 0);
    vector<ll> padres(n+1);
    vector<ll> altura(n+1,0);
    vector<vector<int>> hijos(n+1);

    for(int i=0;i<n+1;i++)
    {
        padres[i] = i;
        hijos[i].pb(i);
    }

    int tam = 0;
    for(auto e:edges)
    {
        if(unionn(e[1], e[2], e[0], padres, altura, distancias, hijos))
        {
            tam++;
            if(tam == n-1) break;
        }
    }
    return distancias;
}

int main()
{
    freopen("road.txt", "r", stdin); //Leer
    IOS;
    int tt;
    cin>>tt;
    fore(z, 1, tt+1)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<ll>> edges(m);

        vector<ll> aux(3);
        fore(i, 0, m)
        {
            cin>>aux[1]>>aux[2]>>aux[0];
            edges[i]=aux;
        }

        sort(edges.begin(), edges.end());

        cout << "Case " << z << ":" << endl;

        vector<ll> distancias = kruskal(n, edges);
        fore(i, 1, n+1) cout << distancias[i] << endl;
    }
    return 0;
}