# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        long long n, k;
        cin>>n>>k;

        k = k*(ceil(double(n)/double(k)));
        
        ll l = 0;
        ll r = 1000000000;

        ll m;
        while (l < r-1)
        {
            m = (l + r)/ 2;
            
            if(n*m < k) l = m;
            else r = m;
        }
        
        cout << l + 1 << endl;
 
    }
    return 0;
}