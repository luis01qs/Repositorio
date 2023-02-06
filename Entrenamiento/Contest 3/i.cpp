# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
# define mp(a,b) make_pair(a,b)

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin); //Leer
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        fore(i, 0, n) cin>>a[i];

        int maximo = 0;
        int cont = 0;
        for(auto &i:a)
        {
            for(auto &e:a)
            {
                if(e == i) continue;
                cont = 0;
                int aux = i xor e;
                fore(j, 0, 16)
                {
                    if(aux & 1) cont++;
                    aux >>= 1;
                }
                maximo = max(maximo, cont);
            }
        }
        cout << maximo << endl;
    }
    return 0;
}