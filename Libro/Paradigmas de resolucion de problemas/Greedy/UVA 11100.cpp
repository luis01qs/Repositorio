# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    int tt = 0;
    int n;
    while(cin>>n, n)
    {

        if(tt>0) cout << endl;

        vector<int> mochilas(n);
        for(int i=0;i<n;i++) cin>>mochilas[i];
        sort(mochilas.begin(), mochilas.end());

        int cant = 1;
        int tam = 1;

        int aux = mochilas[0];
        for(int i=1;i<n;i++)
        {
            if(aux == mochilas[i]) cant++;
            else
            {
                cant = 1;
                aux = mochilas[i];
            }

            tam = max(tam, cant);
        }

        vector<vector<int>> res(tam);

        cout << tam << endl;


        for(int i=0;i<n;i++) res[i%tam].push_back(mochilas[i]);
        
        bool val = false;
        for(auto &vec:res)
        {
            val = false;
            for(auto &e:vec)
            {
                if(val) cout << " ";
                val = true;
                cout << e;
            }
            cout << endl;
        }

        tt++;
    }

    return 0;
}  