# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    ll x = 0;
    ll a = pow(7,5);
    ll m = pow(2,31)-1;
    ll c = 0;

    set<ll> random;
    int i = 10000;
    int tam;

    while(i--)
    {
        x = (a*x+c)%m;
        random.insert(x);
        if(tam == random.size())
        {
            cout << "Repetido: " << x << endl;
        }
        cout << x << endl;
        tam = random.size();
    }

    return 0;
}