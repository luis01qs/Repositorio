# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define forell(i, a, b) for(ll i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)

using namespace std;

int array[10];
int funcion(int i)
{
    return (i*(i+1)/2);
}

int binary_search_less(int a, int b, int x)
{
   if(a == b) return funcion(a) <= x ? a : -1;
   int k = (b + a) / 2;
   if( x < funcion(k) ) return binary_search_less(a, k, x);
   int ret = binary_search_less(k+1, b, x);
   return ret == -1 ? k : ret;
}

int binary_search_more(int a, int b, int x)
{
    if(a == b) return funcion(a) >= x ? a : -1;
    int k = (b + a) / 2;
    if( x > funcion(k) ) return binary_search_more(k+1, b, x);
    int ret = binary_search_more(a, k, x);
    return ret == -1 ? k : ret;
}

int binary_search(int a, int b, int x)
{
    if(a >= b) return funcion(b) == x ? a : -1;
    int k = (b + a) / 2;
    if(x > funcion(k)) return binary_search(k+1, b, x);
    if(x < funcion(k)) return binary_search(a, k-1, x);
    return k;
}

int main()
{
    fore(i, 1, 10) cout << funcion(i) << " ";
    cout << endl;
    //cout << "2 " << endl << binary_search_more(0, 9, 2) << endl;
    //fore(i, 0, 57) cout << i << " " << binary_search_less(0, 9, i) << endl;
    fore(i, 1, 57) cout << i << " " << binary_search_more(0, 10, i) << endl;
    return 0;
}