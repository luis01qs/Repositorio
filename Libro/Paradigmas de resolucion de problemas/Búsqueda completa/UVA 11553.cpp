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
        
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cin>>grid[i][j];
        }

        vector<int> per;
        for(int i=0;i<n;i++) per.push_back(i);

        int cont = 0;
        int minimo = INT_MAX;
        do
        {
            cont = 0;
            for(int i=0;i<n;i++)
            {
                cont += grid[i][per[i]];
            }
            minimo = min(minimo, cont);
        } while (next_permutation(per.begin(), per.end()));
        

        cout << minimo << endl;
    }
    return 0;
}