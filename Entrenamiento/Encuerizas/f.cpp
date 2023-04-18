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
        ll a, b, c, d;
        cin>>a>>b>>c>>d;

        ll bajar = d-b;

        if(bajar < 0 || c-bajar > a)
        {
            cout << -1 << endl;
            continue;
        }

        ll res = bajar + a - (c - bajar);
        cout << res << endl;
    }

    return 0;
}