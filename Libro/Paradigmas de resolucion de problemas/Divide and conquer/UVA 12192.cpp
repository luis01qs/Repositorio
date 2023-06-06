# include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> grid;
int u, l;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    while(cin>>n>>m)
    {
        if(n == 0 && m == 0) break;

        grid.resize(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin>>grid[i][j]; 
        }

        int q;
        cin>>q;

        while(q--)
        {
            cin>>u>>l;
        }
    }
    return 0;
}