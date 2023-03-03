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
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        vector<ll> hot(k+1), cold(k+1);
        for(int i=1;i<k+1;i++) cin>>cold[i];
        for(int i=1;i<k+1;i++) cin>>hot[i];

        ll res = 0;
        for(int i=0;i<n;i++)
        {
            if(i != 0 && a[i-1] == a[i]) res += hot[a[i]];
            else res += cold[a[i]];
        }
        cout << res << endl;
    }
    return 0;
}