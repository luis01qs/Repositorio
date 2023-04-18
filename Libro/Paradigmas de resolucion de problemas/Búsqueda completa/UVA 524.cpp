# include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arreglo;
vector<int> primos = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bitset<20> val;

void imprimir()
{
    for(int i=0;i<n-1;i++) cout << arreglo[i] << " ";
    cout << arreglo[n-1] << endl;
}

void backtracking(int o)
{
    if(o == n)
    {
        for(auto &e:primos)
        {
            if(arreglo[0] + arreglo[n-1] == e) imprimir();
        }
        return;
    }

    for(int i=2;i<n+1;i++)
    {
        if(val[i]) continue;
        val[i] = true;
        arreglo[o] = i;
        for(auto &e:primos)
        {
            if(arreglo[o] + arreglo[o-1] == e) backtracking(o+1);
        }
        val[i] = false;
    }
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    int tt = 1;
    while(cin>>n)
    {
        if(tt != 1) cout << endl;
        cout << "Case " << tt << ":";
        cout << endl;
        if(n == 1)
        {
            cout << 1 << endl;
            tt++;
            continue;
        }

        arreglo.resize(n);
        arreglo[0] = 1;

        backtracking(1);
        tt++;
    }

    return 0;
}