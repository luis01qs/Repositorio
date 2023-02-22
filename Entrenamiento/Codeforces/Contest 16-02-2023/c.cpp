#include <bits/stdc++.h>
# define ll long long

using namespace std;

int main() 
{
    freopen("prueba.txt", "r", stdin); //Leer
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;

        vector<ll> a(n);
        vector<ll> b(n);

        for(int i=0; i<n; i++)cin>>a[i];
        for(int i=0; i<n; i++)cin>>b[i];

        vector<ll> res(n+10,0);
        vector<ll> total(n+10,0);
        vector<ll> suma(n+10,0);

        suma[1]=b[0];
        for(int i=1; i<n; i++) suma[i+1]=suma[i]+b[i];

        for(int i=0; i<n; i++)
        {
            ll busqueda=a[i];
            ll x=i+1;
            ll y=n+1;

            while(y-1>x)
            {
                ll mitad=(x+y)/2;
                ll actual=suma[mitad]-suma[i];
                if(actual>busqueda) y=mitad;
                else x=mitad;
            }

            if(b[i]<=busqueda)
            {
                res[i]++;
                res[x]--;
                ll residuo = busqueda-(suma[x]-suma[i]);
                total[x]+=residuo;
            }
            else total[i]+=busqueda;
        }

        ll cont = 0;
        for(int i=0; i<n; i++)
        {
            cont+=res[i];
            cout<<cont*b[i]+total[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}