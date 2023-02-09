// Greedy
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
        int q, m;
        cin>>q>>m;
        vector<vector<pair<char, char>>> respuestas(m, vector<pair<char,char>>(q));

        fore(i, 0, m)
        {
            fore(j, 0, q) cin>>respuestas[i][j].first>>respuestas[i][j].second;
        }

        vector<char> letras = {'A', 'B', 'C', 'D'};
        bool val = false;
        fore(j, 0, q)
        {
            val = false;
            set<char> existentes;
            fore(i, 0, m)
            {
                if(respuestas[i][j].second == 'T')
                {
                    cout << respuestas[i][j].first;
                    val = true;
                    break;
                }
                existentes.insert(respuestas[i][j].first);
            }

            if(!val)
            {
                if(existentes.size() <= 2) cout << "?";
                else
                {
                    for(auto &e:letras)
                    {
                        if(existentes.find(e) == existentes.end()) cout << e;
                    }
                }
            }

            if(j < q-1) cout << " ";
        }
        cout << endl;

    }
    return 0;
}