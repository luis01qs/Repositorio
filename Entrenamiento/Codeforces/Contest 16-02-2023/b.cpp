# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin); //Leer
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n, k;
        cin>>n>>k;
        vector<pair<int, int>> valores(n);


        bool der=false, izq=false;
        for(int i=0;i<n;i++)
        {
            cin>>valores[i].first>>valores[i].second;
            if(valores[i].first == k) izq = true;
            if(valores[i].second == k) der = true;
        }

        if(der && izq) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}