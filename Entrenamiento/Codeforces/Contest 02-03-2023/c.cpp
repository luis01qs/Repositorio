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
        int n;
        cin>>n;
        vector<ll> a(n);
        priority_queue<ll> pq;

        ll res = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] == 0 && pq.size()!=0)
            {
                res += pq.top();
                pq.pop();
            }
            if(a[i] != 0)
            {
                pq.push(a[i]);
            }
        }

        cout << res << endl;
    }
    return 0;
}