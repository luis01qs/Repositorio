# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n, k, d, w;
        cin>>n>>k>>d>>w;

        vector<ll> paciente(n);
        for(int i=0;i<n;i++) cin>>paciente[i];

        ll cont = 0;
        ll abierto = 0;
        ll tiempo = 0;

        for(int i=0;i<n;i++)
        {
            if(paciente[i] - tiempo >= w) abierto = 0;

            if(abierto == 0)
            {
                cont++;
                abierto = k-1;
                tiempo = paciente[i];
            }
            else
            {
                abierto--;
            }
        }

        cout << cont << endl;
    }

    return 0;
}