// Vector de suma de todas las repeticiones con búsqueda binaria
# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define forell(i, a, b) for(ll i=a;i<b;i++)
# define forellm(i, a, b) for(ll i=a;i>b;i--)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
 
using namespace std;
 
vector<ll> valores;

ll binary_search_more_1(ll a, ll b, ll x)
{
    if(a == b) return valores[a] >= x ? a : -1;
    ll k = (b + a) / 2;
    if( x > valores[k] ) return binary_search_more_1(k+1, b, x);
    ll ret = binary_search_more_1(a, k, x);
    return ret == -1 ? k : ret;
}

ll calculo(ll x)
{
    return x*(x+1)/2;
}

ll binary_search_more_2(ll a, ll b, ll x)
{
    if(a == b) return calculo(a) >= x ? a : -1;
    ll k = (b + a) / 2;
    if( x > calculo(k) ) return binary_search_more_2(k+1, b, x);
    ll ret = binary_search_more_2(a, k, x);
    return ret == -1 ? k : ret;
}

ll binary_search_less(ll a, ll b, ll x)
{
    if(a == b) return calculo(a) <= x ? a : -1;
    ll k = (b + a) / 2;
    if(x < calculo(k)) return binary_search_less(a, k, x);
    ll ret = binary_search_less(k+1, b, x);
    return ret == -1 ? k : ret;
}
 
int main()
{
    freopen("army.txt", "r", stdin); //Leer
    ll tt;
    cin>>tt;
 
    valores.pb(1);
    forell(i, 2, 1442251) valores.pb(valores[valores.size()-1]+i*i);
 
    fore(z, 1, tt+1)
    {
        ll n;
        cin>>n;
        cout << "Case " << z << ": ";
 
        ll ptr = binary_search_more_1(0, valores.size()-1, n) + 1;
        
        if(valores[ptr] == n) cout << ptr*ptr << endl;
        else
        {
            ptr--;
            ll dif = n - valores[ptr-1];
            ll res = ptr*ptr;
            ptr++;

            if(dif == calculo(ptr))
            {   
                res += ptr;
            }
            else if(dif < calculo(ptr))
            {
                res += binary_search_more_2(1, ptr, dif);
            }
            else 
            {
                res += ptr;
                dif -= calculo(ptr);
                ptr--;
                dif = calculo(ptr) - dif;
                res += ptr - binary_search_less(0, ptr, dif);
            }
            cout << res << endl;
        }
    }
    return 0;
}