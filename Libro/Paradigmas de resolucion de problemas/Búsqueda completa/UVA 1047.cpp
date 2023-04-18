# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n, k, m;

    int tt = 1;
    while(cin>>n>>k)
    {
        if(n==0) break;

        cout << "Case number " << tt << endl;
        tt++;
    
        vector<int> torres(n);
        for(int i=0;i<n;i++) cin>>torres[i];

        cin>>m;

        vector<vector<int>> compartidas(n);
        vector<int> valor_compartidas(m);
        int t, aux;

        for(int i=0;i<m;i++)
        {
            cin>>t;
            while(t--)
            {
                cin>>aux;
                aux--;
                compartidas[aux].push_back(i);
            }
            cin>>valor_compartidas[i];
        }

        string s = "";
        for(int i=0;i<n;i++)
        {
            if(i<k) s += "1";
            else s+= "0";
        }

        int cont = 0;
        int res = 0;
        set<int> finales;
        do
        {
            set<int> actuales;
            cont = 0;
            for(int i=0;i<n;i++)
            {
                if(s[i] == '1')
                {
                    cont += torres[i];
                    for(auto &e:compartidas[i]) actuales.insert(e);

                }
            }

            for(auto &e:actuales) cont -= valor_compartidas[e];
            res = max(res, cont);
            cout << s << " -> " << cont << endl;

        } while (prev_permutation(s.begin(), s.end()));
        
        cout << res << endl;
    }
    return 0;
}