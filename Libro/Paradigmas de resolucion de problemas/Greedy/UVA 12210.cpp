# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int n,m;
    int tt = 1;
    while(cin>>n>>m)
    {
        if(n==0) break;

        vector<int> hombres(n);
        vector<int> mujeres(m);

        int minimo = 100;

        for(int i=0;i<n;i++)
        {
            cin>>hombres[i];
            minimo = min(minimo, hombres[i]);
        }
        for(int i=0;i<m;i++) cin>>mujeres[i];

        cout << "Case " << tt << ": "; 
        if(n<=m) cout << 0 << endl;
        else
        {
            cout << n - m << " " << minimo << endl;
        }
        tt++;
    }
    return 0;
}