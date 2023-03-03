# include <bits/stdc++.h>
# define ll long long

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
        //cout << n << endl;

        vector<int> res(n, -1);

        int p;
        set<int> nuevos;
        int cont = 0;
        int tam;
        bool val = true;
        for(int k=0;k<m;k++)
        {
            cin>>p;
            tam = nuevos.size();
            nuevos.insert(p);
            if(val && tam != nuevos.size())
            {
                nuevos.insert(p);
                res[cont] = k+1;
                cont++;
                if(cont == n) val = false;
            }
        }

        for(int i=n-1;i>=0;i--) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}