# include <bits/stdc++.h>
# define ll long long

using namespace std;

int suma(ll x)
{
    int suma = 0;
    while(x!=0)
    {
        suma += x%10;
        x/=10;
    }
    return suma;
}

void procedimiento(ll x, ll y, ll n)
{
    int sx, sy;
    sx = suma(x);
    sy = suma(y);
    if(sx > sy)
    {
        swap(x,y);
        swap(sy, sx);
    }

    cout << x << " " << y << " " << sx << " " << sy << endl;

    int dy, dx;
    ll pot = 1;
    int dif = sy-sx;
    int cont = 0;
    int minimo;
    while(sy - sx > 1)
    {
        x += (y%pot)%pot;
        y -= (y%pot)*pot;

        pot *= 10;
        sx = suma(x);
        sy = suma(y);
        if(sx > sy)
        {
            swap(x,y);
            swap(sy, sx);
        }
    }

    cout << x << " " << y << endl;
}

void pro(ll x, ll y)
{
    int sx, sy;
    sx = suma(x);
    sy = suma(y);
    if(sx > sy)
    {
        swap(x,y);
        swap(sy, sx);
    }

    ll x2 = x;
    ll y2 = y;
    ll dif;
    int cont = 0;
    while(sy - sx > 1)
    {
        dif = min(9-(x2%10), y2%10);
        x2 /= 10;
        y2 /= 10;

        if(sy - sx > dif)
        {
            x += dif*pow(10,cont);
            y -= dif*pow(10,cont);
        }
        else
        {
            x += (sy-sx)*pow(10, cont);
            y -= (sy-sx)*pow(10,cont);
        }

        sx = suma(x);
        sy = suma(y);
        cont++;
    }
    cout << x << " " << y << endl;
}

int main()
{
    freopen("prueba.txt", "r", stdin); //Leer
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        
        ll x, y;
        x = n/2;
        y = n/2;
        
        if(n%2==0)
        {
            cout << x << " " << y << endl;
            continue;
        }

        x++;
        pro(x, y);
    }

    return 0;
}