# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(ll i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
# define ii pair<int, int>
# define pb(x) push_back(x)

using namespace std;

string palabra(char inicial, ll l, ll m, ll a)
{
    string s = "";
    s += inicial;

    fore(i, 1, l)
    {
        inicial = 'a' + ((inicial-'a') * m + i * a)%26;
        s += inicial;
    }

    return s;
}

//vector<vector<ll>> letras(26); 

ll binary_search_more(ll a, ll b, ll x, vector<ll> &letras)
{
    if(a == b) return letras[a] >= x ? letras[a] : -1;
    int k = (b + a) / 2;
    if( x > letras[k] ) return binary_search_more(k+1, b, x, letras);
    int ret = binary_search_more(a, k, x, letras);
    return ret == -1 ? letras[k] : ret;
}

int main()
{
    IOS;
    freopen("mahdi.txt", "r", stdin); //Leer
    ll tt;
    cin>>tt;
    fore(z, 1, tt+1)
    {
        char inicial;
        ll l, m, a;
        cin>>inicial>>l>>m>>a;

        vector<vector<ll> > letras(26);

        string s1 = palabra(inicial, l, m, a);
        fore(i, 0, s1.size()) letras[s1[i]-'a'].pb(i);

        /*
        fore(i, 0, letras.size())
        {
            cout << char('a'+i) << " -> ";
            for(auto j:letras[i]) cout << j << " ";
            cout << endl;
        }*/

        //cout << s1 << endl;

        cout << "Case " << z << ":" << endl;
        ll t;
        cin>>t;
        while(t--)
        {
            cin>>inicial>>l>>m>>a;
            string s2 = palabra(inicial, l, m, a);
            //cout << s2 << endl;

            ll p = 0;
            bool val = true;
            fore(i, 0, s2.size())
            {
                //cout << s2[i] << " ";
                ll letra = s2[i]-'a';
                //cout << letra << " " << letras[letra].size() << " ";
                if(letras[letra].size() == 0)
                {
                    val = false;
                    break;
                }

                if(i != 0 && s2[i]==s2[i-1])p++;
                p = binary_search_more(0, letras[letra].size()-1, p, letras[letra]);

                //cout << p << endl;
                if(p == -1)
                {
                    val = false;
                    break;
                }
            }

            if(val) cout << "BRAVO" << endl;
            else cout << "REPEAT" << endl;
        }
    }

    return 0;
}

