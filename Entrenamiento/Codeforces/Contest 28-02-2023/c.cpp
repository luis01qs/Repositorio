# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
ll binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
 
int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll l, r;
        cin>>l>>r;
 
        ll a = l;
        ll cont = 1;
        while(true)
        {
            if(a*2 > r) break; 
            a *= 2;
            cont++;
        }
 
        cout << cont << " ";
        ll res = 1;
 
        bool val=false;
        if(3*a/2 <= r)
        {
            val = true;
            res += cont-1;
        }
 
        ll l2 = l+1;
        ll pot = binpow(2,cont-1);
        while(true)
        {
            a += pot;
            if(a > r) break;
            res = (res+1)%998244353;
            if(val && 3*a/2 <= r) res = (res+cont-1)%998244353;
            else val = false;
        }
 
        cout << res << endl;
    }
    return 0;
}