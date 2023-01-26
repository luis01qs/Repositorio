# include <bits/stdc++.h>
# define ll long long

using namespace std;

ll gcd(ll x, ll y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}