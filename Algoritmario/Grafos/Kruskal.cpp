# include <bits/stdc++.h>

using namespace std;

// ********************************************************************************Union_find
//Nodo a buscar el padre y vector con los padres de cada nodo
int findd(int nodo, vector<int> &padres)
{
    if(padres[nodo] != nodo) padres[nodo] = findd(padres[nodo], padres);
    return padres[nodo];
}

//Se puede hacer también un void cuando no nos interesa si se hizo o no la unión
//Nodos a conectar, vector de padre de cada nodo, altura del árbol de cada nodo
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
// *********************************************************************************Fin Union_find

//Cantidad de nodos, vector de conexiones (peso, nodo1, nodo2)
vector<vector<int>> kruskal(int n, vector<vector<int>> edges)
{
    vector<int> padres(n+1);
    vector<int> altura(n+1,0);
    vector<vector<int>> res(n-1);

    for(int i=0;i<n+1;i++) padres[i] = i;

    int tam = 0;
    for(auto e:edges)
    {
        if(unionn(e[1], e[2], padres, altura))
        {
            res[tam] = e;
            tam++;
            if(tam == n-1) break;
        }
    }
    return res;
}