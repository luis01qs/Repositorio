# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    
    vector<ll> a(m+1);
    a[0] = 1;
    for(ll i=1;i<=m;i++) cin>>a[i];

    ll cont = 0;
    for(ll i=0;i<m;i++)
    {
        if(a[i] <= a[i+1]) cont += a[i+1] - a[i];
        else cont += n - (a[i] - a[i+1]);
    }

    cout << cont << endl;

    return 0;
}