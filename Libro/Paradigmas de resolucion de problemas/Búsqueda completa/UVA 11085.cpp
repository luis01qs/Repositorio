# include <bits/stdc++.h>

using namespace std;

vector<vector<int>> soluciones;
vector<int> res(8, 0);

bool colocar(int r, int c)
{
    for(int i=0;i<c;i++)
    {
        if(res[i] == r || abs(res[i]-r) == abs(i-c)) return false;
    }
    return true;
}

void backtracking(int c)
{
    if(c==8)
    {
        soluciones.push_back(res);
        return;
    }

    for(int i=0;i<8;i++)
    {
        if(colocar(i, c))
        {
            res[c] = i;
            backtracking(c+1);
        }
    }
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    backtracking(0);

    int tt = 1;
    vector<int> a(8);
    while(cin>>a[0])
    {
        for(int i=1;i<8;i++) cin>>a[i];

        int minimo = 8;
        int cont;

        for(auto &e:soluciones)
        {
            cont = 0;
            for(int i=0;i<8;i++)
            {
                if(a[i] != e[i] + 1) cont++;
            }
            minimo = min(minimo, cont);
        }

        cout << "Case " << tt << ": " << minimo << endl;
        tt++;
    }

    return 0;
}