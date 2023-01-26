// Hacer todas las combinaciones posibles con las monedas usando bfs, 
// encontrar la respuesta más cercana de cada querry
# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
# define mp() make_pair()

using namespace std;

ll gcd(ll x, ll y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}

struct fraccion
{
    ll a, b;
    fraccion() {}
    fraccion(ll a, ll b)
    {
        this -> a = a;
        this -> b = b;
    }

    bool operator<(const fraccion &A) const
    {
        return a*A.b < b*A.a;
    }
};

int main()
{
    freopen("zanzibar.txt", "r", stdin); //Leer

    set<fraccion> combinaciones;
    queue<fraccion> q;
    combinaciones.insert(fraccion(0,1));
    combinaciones.insert(fraccion(1,1));
    q.push(fraccion(0,1));

    fraccion aux;
    ll c, d, e;
    while(!q.empty())
    {
        aux = q.front();
        fore(b, 2, 14)
        {
            fore(a, 1, b)
            {
                c = aux.a*b + aux.b*a;
                d = aux.b*b;
                e  = gcd(d, c);
                c /= e;
                d /= e;
                if(c >= d) continue;

                if(combinaciones.find(fraccion(c, d)) == combinaciones.end()) q.push(fraccion(c,d)); // Si no está en el set, mételo a la cola
                combinaciones.insert(fraccion(c,d));
            }
        }
        q.pop();
    } 

    //for(auto i:combinaciones) cout << i.a << "/" << i.b << endl;
    
    int tt;
    cin>>tt;

    fraccion dif1, dif2, cercano;

    fore(z, 1, tt+1)
    {
        cin>>aux.a>>aux.b;
        cout << "Case " << z <<": ";
        if(aux.a == 0)
        {
            cout << "0/1" << endl;
            continue;
        }

        cercano = *combinaciones.lower_bound(aux);
        c = abs(aux.a*cercano.b-aux.b*cercano.a);
        d = aux.b*cercano.b;
        e = gcd(c, d);
        c /= e;
        d /= e;
        dif1 = fraccion(c, d);

        cercano = *(--combinaciones.lower_bound(aux));
        c = abs(aux.a*cercano.b-aux.b*cercano.a);
        d = aux.b*cercano.b;
        e = gcd(c, d);
        c /= e;
        d /= e;
        dif2 = fraccion(c, d);

        if(dif1 < dif2) cout << dif1.a << "/" << dif1.b << endl;
        else cout << dif2.a << "/" << dif2.b << endl;
    }

    return 0;
}