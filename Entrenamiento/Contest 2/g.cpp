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
        int n, s;
        cin>>n>>s;
        vector<int> monedas(n);
        fore(i, 0, n) cin>>monedas[i];

        int res = 0;
        fore(i, 0, (1<<n))
        {
            int i2=i;
            int minimo = 100;
            int cont = 0;
            int total = 0;
            fore(j, 0, n)
            {
                if(i2 & 1)
                {
                    cont++;
                    minimo = min(minimo, monedas[j]);
                    total += monedas[j];
                }
                i2 >>= 1;
            }

            if(total >= s && total - minimo < s) res = max(res, cont);
        }
        cout << res << endl;
    }
    return 0;
}