# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin); //Leer
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        if(n%2==0)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        ll max = n*2;

        vector<vector<ll>> arreglo(n, vector<ll>(3)); 
        for(ll i=0;i<n;i++)
        {
            arreglo[i][1] = i+1;
            arreglo[i][2] = max;
            arreglo[i][0] = max + i + 1;
            max--;
        }

        for(auto &e:arreglo)
        {
            cout << e[0] << " " << e[1] << " " << e[2] << endl;
        }

        sort(arreglo.rbegin(), arreglo.rend());

        for(auto &e:arreglo)
        {
            cout << e[0] << " " << e[1] << " " << e[2] << endl;
        }
    }

    return 0;
}