// Greedy
# include <bits/stdc++.h>
# define fore(i, a, b) for(int i=a;i<b;i++)
 
using namespace std;
 
int main()
{
    freopen("cubes.txt","r",stdin);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        fore(i, 0, n) cin>>a[i];
        cout << "Case " << z << ":" << endl;
        sort(a.rbegin(), a.rend());
        vector<int> res(n);
 
        int j=0, k=0;
        fore(e, 0, n)
        {
            if(e%2==0)
            {
                res[n-1-j] = a[e];
                j++;
            }
            else
            {
                res[k] = a[e];
                k++;
            }
        }
 
        fore(i, 0, n)
        {
            cout << res[i];
            if(i!=n-1) cout << " ";
        }
        cout << endl;
    }
 
    return 0;
}