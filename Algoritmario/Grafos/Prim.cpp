# include <bits/stdc++.h>
# define mt(a,b,c) make_tuple(a,b,c)
# define pb(x) push_back(x)

using namespace std;

// tuple.0 = nodo inicial
// tuple.1 = nodo de llegada
// tuple.2 = peso de la arista
vector<tuple<int, int, int>> Prim(vector<vector<tuple<int, int, int>>> edges, int n) //Conexiones del grafo y número de nodos
{
    vector<bool> nodos(n+1, 0);
    nodos[1] = true;
    priority_queue<tuple<int, int, int>> posibles;
    for(auto &e:edges[1])posibles.push(mt(-1*get<2>(e), get<1>(e), get<0>(e)));
    int tam = 1;
    vector<tuple<int, int, int>> res;

    tuple<int, int, int> aux;
    while(tam < n)
    {
        aux=posibles.top();
        if(nodos[get<1>(aux)])
        {
            posibles.pop();
            continue;
        }

        res.pb(mt(get<2>(aux), get<1>(aux), -1*get<0>(aux)));
        for(auto &e:edges[get<1>(aux)]) posibles.push(mt(-1*get<2>(e), get<1>(e), get<0>(e)));
        nodos[get<1>(aux)] = true;
        tam++;
        posibles.pop();
    }
    return res;
}