# include <bits/stdc++.h>
# define ll int

ll M = 1000000007;

using namespace std;

ll ajuste(ll a)
{
    while(a < 0) a = (a+M)%M;
    return a % M;
}

ll resta(ll a, ll b)
{
    ll res = (ajuste(a%M) - ajuste(b%M)) % M;
    res = ajuste(res);
    return res;
}

ll producto(ll a, ll b)
{
    ll res = (ajuste(a%M) * ajuste(b%M)) % M;
    return res;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    //freopen("resultado.txt", "w", stdout);

    int n, q;
    cin>>n>>q;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<ll> pre(n+1);
    vector<ll> cuadrados(n+1);
    pre[0] = 0;
    cuadrados[0] = 0;
    for(int i=0;i<n;i++)
    {
        pre[i+1] = (pre[i] + a[i])%M;
        cuadrados[i+1] = (cuadrados[i] + (a[i]%M)*(a[i]%M))%M;
    }

    int l, r;
    while(q--)
    {
        cin>>l>>r;

        if(l == r)
        {
            cout << a[l-1]%M << endl; 
            continue;
        }

        ll res;

        res = (((((pre[r])%M) - ((pre[l-1])%M))%M)+M)%M;
        res = ajuste(res);
        res = ((res%M) * (res%M))%M;
        res = ajuste(res);
        ll aux = (((((cuadrados[r])%M) - ((cuadrados[l-1])%M))%M)+M)%M;
        aux = ajuste(aux);
        res = (((((res)%M) - ((aux)%M))%M)+M)%M;
        res = ajuste(res);
        res = res/2;
        res = ajuste(res);
        cout << res%M << endl;
    }
    return 0;
}