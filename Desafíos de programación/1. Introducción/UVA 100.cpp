# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    ll a, b;
    while(cin>>a>>b)
    {
        cout << a << " " << b << " ";
        if(a > b) swap(a,b);


        ll res = 1;
        ll actual = 1;
        ll n;
        for(ll i=a;i<=b;i++)
        {
            n = i;
            actual = 1;
            while(true)
            {
                if(n == 1) break;

                if(n%2==0) n = n/2;
                else n = 3*n + 1;

                actual++;
            }

            res = max(res, actual);
        }

        cout << res << endl;
    }
    return 0;
}