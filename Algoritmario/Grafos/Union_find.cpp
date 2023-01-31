# include<bits/stdc++.h>

using namespace std;

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