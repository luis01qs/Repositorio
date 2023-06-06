# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n, d, r;
    while(cin>>n>>d>>r)
    {
        if(n==0) break;
        vector<int> ruta1(n);
        vector<int> ruta2(n);

        for(int i=0;i<n;i++) cin>>ruta1[i];
        for(int i=0;i<n;i++) cin>>ruta2[i];

        sort(ruta1.begin(), ruta1.end());
        sort(ruta2.rbegin(), ruta2.rend());

        ll total = 0;

        for(int i=0;i<n;i++)
        {
            if(ruta1[i] + ruta2[i] > d) total += ruta1[i] + ruta2[i] - d;
        }

        cout << total * r << endl;
    }



    return 0;
}