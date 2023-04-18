# include <bits/stdc++.h>

using namespace std;

vector<string> numeros = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
vector<string> cadena;
bitset<15> quemados;
bool val;
int n;

void backtracking(int actual, int suma)
{
    if(suma == n)
    {
        val = true;
        return;
    }

    for(int i=0;i<7;i++)
    {
        if(cadena[suma][i] == 'Y' && (quemados[i] == true || numeros[actual][i] == 'N')) return;
        if(numeros[actual][i] == 'Y' && cadena[suma][i] == 'N') quemados[i] = true;
    }

    backtracking(actual - 1, suma + 1);
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    while(cin>>n,n)
    {
        cadena.resize(n);
        for(int i=0;i<n;i++) cin>>cadena[i];

        val = false;
        for(int i=9;i>=n-1;i--)
        {
            quemados.reset();
            backtracking(i, 0);
        }

        if(val) cout << "MATCH" << endl;
        else cout << "MISMATCH" << endl;
    }
    return 0;
}