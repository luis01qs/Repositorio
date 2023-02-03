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
bool unionn(int nodo1, int nodo2, ll peso, vector<ll> &padres, vector<ll> &altura, vector<ll> &distancias)
{
    if(findd(nodo1, padres) == findd(nodo2, padres)) return false;
    int padre1 = padres[nodo1];
    int padre2 = padres[nodo2];

    ll tam1=0, tam2=0;
    fore(i, 0, padres.size())
    {
        if(padres[i] == padre1) {tam1++; cout << "Team 1 : " << i << endl;}
        if(padres[i] == padre2) {tam2++; cout << "Team 2 : " << i << endl;}
    }
    cout << "Costo " << peso << endl;

    fore(i, 0, padres.size())
    {
        if(padres[i] == padre1) {distancias[i] += peso*tam2; cout << "1: " << distancias[i] << endl;}
        if(padres[i] == padre2) {distancias[i] += peso*tam1; cout << "2: " << distancias[i] << endl;}
    }

    if(altura[padre1] > altura[padre2]) padres[padre2] = padre1;
    else if (altura[padre1] < altura[padre2]) padres[padre1] = padre2;
    else
    {
        altura[padre1]++;
        padres[padre2] = padre1;
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

    for(int i=0;i<n+1;i++) padres[i] = i;

    int tam = 0;
    for(auto e:edges)
    {
        if(unionn(e[1], e[2], e[0], padres, altura, distancias))
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
        cout << endl;
        fore(i, 1, n+1) cout << distancias[i] << endl;
        cout << endl;
    }
    return 0;
}