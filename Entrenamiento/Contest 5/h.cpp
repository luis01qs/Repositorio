//Vectores auxiliares
# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n;
    cin>>n;
    vector<ll> alturas(n);
    for(int i=0;i<n;i++) cin>>alturas[i];

    vector<ll> derecha(n,0);
    vector<ll> izquierda(n,0);

    derecha[0] = alturas[0];
    derecha[n-1] = alturas[n-1];
    for(int i=1;i<n-1;i++)
    {
        derecha[i] = alturas[i];
        if(alturas[i] >= alturas[i-1]) derecha[i] = derecha[i-1];
    }

    izquierda[0] = alturas[0];
    izquierda[n-1] = alturas[n-1];
    for(int i=n-2;i>0;i--)
    {
        izquierda[i] = alturas[i];
        if(alturas[i] >= alturas[i+1]) izquierda[i] = izquierda[i+1];
    }

    ll res = 0;
    for(int i=1;i<n-1;i++) res = max(res, alturas[i]-max(derecha[i], izquierda[i]));

    cout << res << endl;

    return 0;
}

