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
 
ll binarySearch(int l, int r, ll x)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
        if (valores[mid] == x) return mid;
        if (valores[mid] > x) return binarySearch(l, mid - 1, x);
        return binarySearch(mid + 1, r, x);
    }
    return -1;
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
 
        auto l = lower_bound(valores.begin(), valores.end(), n);
        ll s = *l;
        ll ptr = binarySearch(0, 1442251, s) + 1;
        if(s == n)cout << ptr*ptr << endl;
        else
        {
            s = *(l-1);
            ll dif = n-s;
            ptr--;
            ll res = ptr*ptr;
            ptr++;
            cout << ptr << endl;

            if(dif == ptr*(ptr+1)/2) res += ptr;
            else
            {
                if(dif > ptr*(ptr+1)/2)
                {
                    dif -= ptr*(ptr+1)/2;
                    
                }
                else
                {

                }
            }

            /*ll cont = 0;
            forell(i, 1, ptr+2)
            {
                res++;
                cont += i;
                if(cont>=dif) break;
            }
 
 
            if(cont < dif)forellm(i, ptr, 0)
            {
                res++;
                cont += i;
                if(cont>=dif) break;
            }*/
            
            cout << res << endl;
        }
    }
    return 0;
}