// Fórmula de probabilidad
# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define foreld(i, a, b) for(ld i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
# define mp(a,b) make_pair(a,b)
# define ld long double

using namespace std;

ld binpow(ld a, int b) 
{
    if (b == 0) return 1;
    ld res = binpow(a, b / 2);
    if (b % 2) return res * res * a;
    else return res * res;
}

int main()
{
    freopen("prueba.txt", "r", stdin); //Leer
    cout << setprecision(9) << fixed;
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        string copia = s;
        sort(copia.rbegin(), copia.rend());

        //cout << s << endl;
        //cout << copia << endl;
        
        vector<ld> factorial;
        ld aux = 1;
        factorial.pb(1);
        foreld(i, 1, s.size()+4)
        {
            aux *= i;
            factorial.pb(aux);
            //cout << aux << endl;
        }

        int n = 0;
        fore(i, 0, s.size())
        {
            fore(j, 0, s.size())
            {
                if(copia[j] <= s[i]) break;
                n += factorial[s.size()-i-1];
            }

            fore(j, 0, s.size())
            {
                if(copia[j] == s[i])
                {
                    copia[j] = 0;
                    sort(copia.rbegin(), copia.rend());
                    break;
                }
            }
        }

        if(n == 0)
        {
            cout << "0.000000000" << endl;
            continue;
        }

        ld x = 1/(factorial[s.size()]);
        if(n == 1)
        {
            cout << x << endl;
            continue;
        }

        ld res = x*(binpow(x+1,n))/(x+1);
        cout << res << endl;
    }
    return 0;
}