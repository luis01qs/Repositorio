# include <bits/stdc++.h>

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
        vector<vector<int>> num(n+1, vector<int>(n+1, 0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>num[i][j];
                num[i][j] += num[i-1][j] + num[i][j-1] - num[i-1][j-1];
            }
        }

        for(int x1=1;x1<=n;x1++)
        {
            
        }
    }
    return 0;
}