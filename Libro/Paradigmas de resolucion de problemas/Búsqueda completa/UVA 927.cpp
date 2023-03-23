# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;

        vector<ll> c(n+1);
        for(int i=0;i<n+1;i++) cin>>c[i];

        ll d, k;
        cin>>d>>k;

        double busqueda = double(k)/double(d);

        ll cont = 0;
        ll i;
        for(i=1;;i++)
        {
            cont += i;
            if(cont >= busqueda) break;
        }

        ll res = 0;
        ll mult = 1;
        for(ll j=0;j<n+1;j++)
        {
            res += mult * c[j];
            mult *= i;
        }

        cout << res << endl;

    }
    return 0;
}