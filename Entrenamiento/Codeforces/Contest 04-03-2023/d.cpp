# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    // Criba
    vector<bool> val(10e3+5, 0);
    set<ll> primos;
 
    for(ll i=2;i<1001;i++)
    {
        if(!val[i])
        {
            primos.insert(i);
        }
        for(ll j=2;j<=i && i*j<1001;j++)
        {
            val[i*j] = true;
        }
    }

    freopen("prueba.txt", "r", stdin);

    int n;
    cin>>n;
    vector<ll> a(2*n);

    set<ll> p;

    vector<int> numeros((10e6)+3, 0);

    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
        numeros[a[i]]++;
        if(primos.find(a[i]) != primos.end()) p.insert(a[i]);
    }

    for(auto &e:p) cout << e << endl;

    return 0;
}