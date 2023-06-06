# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    ll aux;
    while(cin>>aux)
    {
        if(aux == -999999) continue;

        vector<ll> num;
        num.push_back(aux);
        while(true)
        {
            cin>>aux;
            if(aux == -999999) break;
            num.push_back(aux);
        }

        int n = num.size();
        ll res = LLONG_MIN;

        ll actual;
        for(int i=0;i<n;i++)
        {
            actual = 1;
            for(int j=i;j<n;j++)
            {
                actual *= num[j];
                res = max(res, actual);
            }
        }

        cout << res << endl;
    }

    return 0;
}