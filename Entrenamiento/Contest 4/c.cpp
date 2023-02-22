# include <bits/stdc++.h>
# define ll long long
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
 
int main()
{
    IOS;
    freopen("prueba.txt", "r", stdin);
    int n, q, x, a, b;
    cin>>n>>q;
 
    set<int> cerrado;
    cerrado.insert(0);
    cerrado.insert(n+2);
 
    set<int>::iterator izquierda, derecha, izqizq;
    while(q--)
    {
        char c;
        cin>>c;
 
        if(c == '?')
        {
            cin>>a>>b;
 
            if(a > b) swap(a,b);
 
            izquierda = cerrado.lower_bound(a);
            derecha = cerrado.lower_bound(b);
 
            if(*izquierda == a || *derecha == b)
            {
                cout << "impossible" << endl;
            }
            else
            {
                izqizq = izquierda;
                izqizq--;
 
                if((*izquierda > b ) || (*izqizq == 0 && *derecha == n+2)) cout << "possible" << endl;
                else cout << "impossible" << endl;
            }
        }
        else if(c == '+')
        {
            cin>>x;
            cerrado.erase(x);
        }
        else
        {
            cin>>x;
            cerrado.insert(x);
        }
    }
    return 0;
}
 