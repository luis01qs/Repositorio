// Fuerza bruta
# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
ll procedimiento(ll &r, ll &x)
{
	ll y = sqrt(r*r-x*x);
	y++;
	return y;
}
 
int main()
{
    //freopen("prueba.txt", "r", stdin);
	ll r;
	cin>>r;
	
	pair<ll,ll> res;
	ll minimo = 10e17;
	for(ll x=0;x<=r;x++)
	{
		ll y = procedimiento(r, x);
		if(x*x+y*y<minimo)
		{
			res.first = x;
			res.second = y;
			minimo = x*x + y*y;
		}
	}
	
	cout << res.first << " " << res.second << endl;
	
    return 0;
}