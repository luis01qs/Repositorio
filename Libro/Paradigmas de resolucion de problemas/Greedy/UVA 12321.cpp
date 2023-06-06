# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    ll l, n;
    while(cin>>l>>n)
    {
        if(l == 0) break;

        ll x, r;
        vector<pair<ll,ll>> gas(n);
        for(int i=0;i<n;i++)
        {
            cin>>x>>r;
            gas[i].first = x - r;
            gas[i].second = x + r;
        }   

        sort(gas.begin(), gas.end());

        ll res = n;
        ll pos = 0;
        ll aux;

        ll i = 0;
        while(pos < l)
        {
            aux = pos;

            while(i < gas.size() && gas[i].first <= pos)
            {
                aux = max(aux, gas[i].second);
                i++;
            }

            if(pos == aux)
            {
                res = -1;
                break;
            }

            pos = aux;
            res--;
        }

        cout << res << endl;

    }
    return 0;
}