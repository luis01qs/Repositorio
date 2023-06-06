# include <bits/stdc++.h>
# define ll long long

using namespace std;

bool cambio(bool val)
{
    if(val) return false;
    return true;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    for(int zz=1;zz<=tt;zz++)
    {
        ll n, d;
        cin>>n>>d;

        vector<ll> piedras(n+2);
        vector<char> tipo(n+2);
        vector<bool> usar(n+2);

        piedras[0] = 0;
        tipo[0] = 'B';
        usar[0] = true;
        piedras[n+1] = d;
        tipo[n+1] = 'B';
        usar[n+2] = true;
 
        char aux;
        for(int i=1;i<n+1;i++) cin>>tipo[i]>>aux>>piedras[i];

        ll res = 0;


        // IDA

        res = 0;

        for(int i=0;i<n+2;i++) usar[i] = true;

        bool val = false;
        for(int i=0;i<n+2;i++)
        {
            if(tipo[i] == 'S')
            {
                usar[i] = val;
                val = cambio(val);
            }
        }

        ll anterior = 0;
        for(int i=0;i<n+2;i++)
        {
            if(usar[i])
            {
                res = max(res, piedras[i] - anterior);
                anterior = piedras[i];
            }
        }

        // VUELTA

        for(int i=0;i<n+2;i++) usar[i] = true;

        val = true;
        for(int i=0;i<n+2;i++)
        {
            if(tipo[i] == 'S')
            {
                usar[i] = val;
                val = cambio(val);
            }
        }

        anterior = 0;
        for(int i=0;i<n+2;i++)
        {
            if(usar[i])
            {
                res = max(res, piedras[i] - anterior);
                anterior = piedras[i];
            }
        }

        cout << "Case "  << zz << ": ";
        cout << res << endl;

    }

    return 0;
}