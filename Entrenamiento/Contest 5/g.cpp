# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n, k;
    cin>>n>>k;

    vector<double> p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    sort(p.rbegin(), p.rend());

    vector<vector<double>> dp(n+1);
    dp[0].push_back(1);

    double res = 0;
    for(int i=1;i<n+1;i++)
    {
        dp[i].resize(i+1);
        double prob = 0;
        for(int j=0;j<=i;j++)
        {
            double aux = 0;
            if(j > 0) aux += p[i-1] * dp[i-1][j-1];
            else aux += p[i-1] * dp[i-1][0];
            if(i-1 >= j+1) aux += (1-p[i-1]) * dp[i-1][j+1];
            dp[i][j] = aux;
            if(j>=k) prob += dp[i][j];
        }

        res = max(res, prob);
    }

    for(int i=0;i<n+1;i++)
    {
        for(auto &e:dp[i]) cout << e << " ";
        cout << endl;
    }

    cout << res << endl;

    return 0;
}

