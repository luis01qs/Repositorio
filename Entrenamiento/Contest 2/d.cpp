# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>
# define pb(x) push_back(x)
# define mp(a,b) make_pair(a,b)

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

        vector<int> dp(n+1);
        for(int i=0;i<n+1;i++) dp[i] = 1e9; 

        string s;
        cin>>s;

        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            bool val = false;
            for(int j=i; j-i<k && j<n;j++)
            {
                if(j>i && s[j]==s[j-1]) val = true;
                if(i==j || val) dp[i] = min(dp[i], dp[j+1]+1);
            }
        }

        cout << dp[0] - 1 <<endl;

    }
    return 0;
}