# include <bits/stdc++.h>

using namespace std;

int n, m;
bitset<110> blancos;
bitset<110> res;
int maximo;

void imprimir()
{
    bool val = false;
    cout << maximo << endl;
    for(int i=0;i<n;i++)
    {
        if(!res[i])
        {
            if(val) cout << " ";
            cout << i+1;
            val= true;
        }
    }
    cout << endl;
}

void backtracking(vector<vector<int>> &edges, int o, int suma)
{
    if(o == n)
    {
        if(suma > maximo)
        {
            maximo = suma;
            res = blancos;
        }
        return;
    }

    if(!blancos[o])
    {
        vector<int> seleccionados;
        for(auto &e:edges[o])
        {
            if(!blancos[e]) seleccionados.push_back(e);
            blancos[e] = true;
        }

        backtracking(edges, o+1, suma+1);

        for(auto &e:seleccionados)
        {
            blancos[e] = false;
        }
    }

    if(blancos[o])
    {
        backtracking(edges, o+1, suma);
        return;
    }

    blancos[o] = true;
    backtracking(edges, o+1, suma);
    blancos[o] = false;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>m;

        vector<vector<int>> edges(n);

        int u, v;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        maximo = 0;
        backtracking(edges, 0, 0);
        imprimir();
    }

    return 0;
}