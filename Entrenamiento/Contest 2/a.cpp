//Greedy
# include <bits/stdc++.h>
# define fore(i, a, b) for(int i=a;i<b;i++)
# define ll long long
 
using namespace std;
 
int main()
{
    //freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll k, n;
        cin>>n>>k;
        vector <ll> v(n);
        fore(i, 0, n) cin>>v[i];
 
        sort(v.begin(), v.end());
        bool val = false;
        ll r1, r2;
        fore(i, 0, n-1)
        {
            fore(j, i+1, n)
            {
                if(v[i]*v[j] > k) break;
                if(v[i]*v[j] == k)
                {
                    val = true;
                    r1 = v[i];
                    r2 = v[j];
                    break;
 
                }
            }
            if(val) break;
        }
 
        if(val) cout << r1 << " " << r2 << endl;
        else cout << "-1" << endl;
 
    }
    return 0;
}