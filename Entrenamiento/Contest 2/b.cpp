// Prefix sum
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
        string s;
        cin>>s;

        vector<pair<int, int>> R(n+2,(pair<int, int> (0,0)));
        vector<pair<int, int>> P(n+2,(pair<int, int> (0,0)));
        vector<pair<int, int>> S(n+2,(pair<int, int> (0,0)));

        fore(i, 0, n+1)
        {
            P[i+1] = P[i];
            S[i+1] = S[i];
            R[i+1] = R[i];
            if(s[i] == 'R')
            {
                P[i+1].first++;
                S[i+1].second++;
            }
            else if(s[i] == 'P')
            {
                S[i+1].first++;
                R[i+1].second++;
            }
            else
            {
                R[i+1].first++;
                P[i+1].second++;
            }
        }


        ll res = 0;
        for(int x=0;x<=n;x++)
        {
            for(int i=0;i+x<=n;i++)
            {
                int y = i+x;
                int z = n;
                int ganadas = R[x].first;
                ganadas -= R[x].second;
                if(y-x>0)
                {
                    ganadas += (P[y].first - P[x].first);
                    ganadas -= (P[y].second - P[x].second);
                }
                if(z-y>0)
                {
                    ganadas += (S[z].first - S[y].first);
                    ganadas -= (S[z].second - S[y].second);
                }
                if(ganadas > 0) res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}