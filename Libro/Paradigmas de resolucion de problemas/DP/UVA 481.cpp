# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    vector<ll> a;

    ll aux;
    while(cin>>aux) a.push_back(aux);
    ll n = a.size();

    if(n == 1)
    {
        cout << 1 << endl << "-" << endl << a[0] << endl;
        return 0;
    }

    reverse(a.begin(), a.end());
    for(int i=0;i<n;i++) a[i] = -a[i]; 

    vector<ll> lis;
    lis.push_back(a[0]);

    for(ll i=1;i<n;i++)
    {
        auto k = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();

        if(k == lis.size()) lis.push_back(a[i]);
        else if(a[i] < lis[k]) lis[k] = a[i];
    }

    reverse(lis.begin(), lis.end());

    cout << lis.size() << endl <<  "-" << endl;
    for(auto &e:lis) cout << (-1)*e << endl;

    return 0;
}