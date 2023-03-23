# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector<string> s(n);
        vector<pair<int, int>> limites(n);

        for(int i=0;i<n;i++)
        {
            cin>>s[i]>>limites[i].first>>limites[i].second;
        }

        int q;
        cin>>q;
        while(q--)
        {
            int p;
            cin>>p;

            int res;
            int cont = 0;

            for(int i=0;i<n;i++)
            {
                if(p >= limites[i].first && p <= limites[i].second)
                {
                    cont++;
                    res = i;
                }
            }

            if(cont == 1) cout << s[res] << endl;
            else cout << "UNDETERMINED" << endl;
        }
        if(tt) cout << endl;
    }
    return 0;
}