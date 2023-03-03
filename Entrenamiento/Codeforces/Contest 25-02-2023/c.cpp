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
        vector<int> a(n);
        vector<int> numeros(n+m+2,0);

        int cont = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            numeros[a[i]]++;
            if(numeros[a[i]] == 1) cont++;
        }

        vector<pair<int, int>> dif(m);
        for(int i=0;i<m;i++) cin>>dif[i].first>>dif[i].second;

        
    }
    return 0;
}