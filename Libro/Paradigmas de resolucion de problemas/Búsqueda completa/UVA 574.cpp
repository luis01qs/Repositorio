# include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> numeros;
bitset<15> elegidos;
bool existente;

void imprimir()
{
    bool val = false;
    for(int i=0;i<15;i++)
    {
        if(elegidos[i])
        {
            if(val) cout << "+";
            val = true;
            cout << numeros[i];
        }
    }
    cout << endl;
}

void backtracking(int o, int suma)
{
    if(o == n+1 || suma > t) return;
    if(suma == t)
    {
        existente = true;
        imprimir();
        return;
    }

    if(o>0 && numeros[o-1] == numeros[o] && elegidos[o-1]==false)
    {
        backtracking(o+1, suma);
        return;
    }

    elegidos[o] = true;
    backtracking(o+1, suma+numeros[o]);
    elegidos[o] = false;

    backtracking(o+1, suma);
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    while(cin>>t)
    {
        cin>>n;
        if(n==0) break;

        existente = false;
        numeros.resize(n);
        for(int i=0;i<n;i++) cin>>numeros[i];

        cout << "Sums of " << t << ":" << endl;

        backtracking(0, 0);

        if(!existente) cout << "NONE" << endl;
    }
    return 0;
}