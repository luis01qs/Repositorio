//Greedy con geometría
# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
bool entero(ll a, ll b, ll &c)
{
    c = sqrt(a*a-b*b);
    //cout << a << " " << b << " " << c << endl;
    return c*c == a*a-b*b;
}
 
int main()
{
    ll a, b;
    cin>>a>>b;
    a--;
    b--;
 
    if(a > b) swap(a,b);
 
    ll cont = 0;
    ll x;
    for(int i=0;i<a;i++)
    {
        //cout << entero(a,i,x) << endl;
        if(entero(a,i,x) && (b*x)%a==0 && (b*i)%a==0) cont++;
    }
 
    if(a != b) cont *= 2;
    cout << cont << endl;
 
    return 0;
}