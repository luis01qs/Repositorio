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
        int n;
        cin>>n;
        vector<ll> monedas(n);
        for(int i=0;i<n;i++) cin>>monedas[i];

        int cont = 0;
        ll total = 0;
        for(int i=0;i<n-1;i++)
        {
            if(total + monedas[i] >= monedas[i+1]) continue;
            cont++;
            total += monedas[i];
        }

        cout << cont + 1 << endl;
    }

    return 0;
}