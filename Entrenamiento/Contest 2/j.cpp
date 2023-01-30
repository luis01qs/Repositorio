//Greedy
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
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> ninos(20, 0);
        vector<int> dulces(55, 0);

        int aux;
        fore(i, 0, n)
        {
            cin>>aux;
            ninos[aux]++;
        }

        fore(i, 0, m)
        {
            cin>>aux;
            dulces[aux]++;
        }

        int x = 0;
        bool val = true;
        fore(i, 0, 16)
        {
            if(ninos[i] == 0) continue;
            while(x <= 50 && ninos[i]>dulces[x]) ++x;
            if(x == 51)
            {
                val = false;
                break;
            }
            ++x;
        }

        if(val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}