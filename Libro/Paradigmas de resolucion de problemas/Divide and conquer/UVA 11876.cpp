# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    int n = 1000005;
    vector<int> divisores(n+5, 0);
    for(int i=1;i<n;++i)
    {
        for(int j=i;j<n;j+=i) divisores[j]++;
    }

    vector<int> sucesion(n+5, 0);
    sucesion[0] = 1;
    sucesion[1] = 2;
    for(int i=2;i<n;++i)
    {
        sucesion[i] = sucesion[i-1] + divisores[sucesion[i-1]];
    }

    int tt;
    cin>>tt;
    int l, r;
    for(int zz=1;zz<=tt;zz++)
    {   
        cin>>l>>r;
        auto L = lower_bound(sucesion.begin(), sucesion.end(), l) - sucesion.begin();
        auto R = upper_bound(sucesion.begin(), sucesion.end(), r) - sucesion.begin();
        cout << "Case " << zz << ": " << R-L << endl;
    }

    return 0;
}