//MST con Kruskal y Union_find
# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
# define mp(a,b) make_pair(a,b)
# define mt(x, y, z) make_tuple(x, y, z)

using namespace std;

int findd(int nodo, vector<int> &padres)
{
    if(padres[nodo] != nodo) padres[nodo] = findd(padres[nodo], padres);
    return padres[nodo];
}

bool unionn(int nodo1, int nodo2, vector<int> &padres, vector<int> &altura)
{
    if(findd(nodo1, padres) == findd(nodo2, padres)) return false;
    int padre1 = padres[nodo1];
    int padre2 = padres[nodo2];

    if(altura[padre1] > altura[padre2]) padres[padre2] = padre1;
    else if (altura[padre1] < altura[padre2]) padres[padre1] = padre2;
    else
    {
        altura[padre1]++;
        padres[padre2] = padre1;
    }

    return true;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> conexiones(m);
        vector<int> padres(n+1);
        vector<int> altura(n+1, 0);
        fore(i, 0, n+1) padres[i] = i;

        vector<int> aux(3);
        fore(i, 0, m)
        {
            cin>>aux[2]>>aux[1]>>aux[0];
            conexiones[i] = aux;
        }

        sort(conexiones.begin(), conexiones.end());

        int tam = 0;
        int maximo = 0;
        for(auto e:conexiones)
        {
            if(unionn(e[1], e[2], padres, altura))
            {
                //cout << e[1] << " -> " << e[2] << " : " << e[0] << endl;
                tam++;
                maximo = max(maximo, e[0]);
                if(tam == n-1) break;
            }
        }
        cout << maximo << endl;
    }
    return 0;
}