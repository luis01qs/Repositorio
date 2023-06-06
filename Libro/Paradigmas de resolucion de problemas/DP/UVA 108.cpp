# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int n;
    cin>>n;

    vector<vector<int>> num(n+1, vector<int>(n+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>num[i][j];

            if(i > 1) num[i][j] += num[i-1][j];
            if(j > 1) num[i][j] += num[i][j-1];
            if(i > 1 && j > 1) num[i][j] -= num[i-1][j-1];
        }
    }

    int maximo = INT_MIN;
    int x1, x2, y1, y2;
    for(x1=1;x1<=n;x1++)
    {
        for(y1=1;y1<=n;y1++)
        {
            for(x2=x1;x2<=n;x2++)
            {
                for(y2=y1;y2<=n;y2++)
                {
                    maximo = max(maximo, num[x2][y2] - num[x2][y1-1] - num[x1-1][y2] + num[x1-1][y1-1]);
                }
            }
        }
    }
    
    cout << maximo << endl;

    return 0;
}