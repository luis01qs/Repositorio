# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0) break;
        vector<ll> dia(n);
        vector<ll> h(m);

        for(int i=0;i<n;i++) cin>>dia[i];
        for(int i=0;i<m;i++) cin>>h[i];

        sort(dia.begin(), dia.end());
        sort(h.begin(), h.end());


        ll total = 0;

        int j=0;
        for(int i=0;i<m;i++)
        {
            if(j<n && h[i] >= dia[j])
            {
                total += h[i];
                j++;
            }
        }

        if(j==n) cout << total << endl;
        else cout << "Loowater is doomed!" << endl;

    }
    return 0;
}