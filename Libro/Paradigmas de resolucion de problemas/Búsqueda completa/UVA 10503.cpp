# include <bits/stdc++.h>

using namespace std;

int n, m, inicio, fin;
bool val;

vector<pair<int, int>> domino;
bitset<20> elegidos;


void backtracking(int tt, int numero)
{
    if(tt > n || val) return;

    if(tt==n && numero==fin)
    {
        val = true;
        return;
    }

    for(int i=0;i<m;i++)
    {
        if(!elegidos[i])
        {
            if(domino[i].first == numero)
            {
                elegidos[i] = true;
                backtracking(tt+1, domino[i].second);
                elegidos[i] = false;
            }

            if(domino[i].second == numero)
            {
                elegidos[i] = true;
                backtracking(tt+1, domino[i].first);
                elegidos[i] = false;
            }
        }
    }
}

int main()
{
    int aux;
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    while(cin>>n, n)
    {
        cin>>m;
        cin>>aux>>inicio>>fin>>aux;

        domino.resize(m);
        for(int i=0;i<m;i++) cin>>domino[i].first>>domino[i].second;

        val = false;
        backtracking(0, inicio);

        if(val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}