# include <bits/stdc++.h>
# define ll long long
# define fore(i, a, b) for(int i=a;i<b;i++)
# define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
# define ii pair<int, int>

using namespace std;

void procedimiento(int i, int j, int k, vector<vector<vector<int> > > &s)
{
    if(s[k][i][j] >= 0) return;
    s[k][i][j] = 0;

    int i2 = i;
    if(k==2) i2++;
    int k2 = (k+1)%3;

    if(i > 0)
    {
        procedimiento(i2-1, j, k2, s);
        if(s[k2][i2-1][j] == 0) s[k][i][j] = 1;
    }

    if(i > 0)
    {
        procedimiento(i2-1, j+1, k2, s);
        if(s[k2][i2-1][j+1] == 0) s[k][i][j] = 1;
    }

    if(j>0)
    {
        procedimiento(i2, j-1, k2, s);
        if(s[k2][i2][j-1] == 0) s[k][i][j] = 1;
    }
}

int main()
{
    freopen("jenga.txt", "r", stdin);
    int tt = 60;
    cin>>tt;
    fore(z, 1, tt+1)
    {
        int n;
        cin>>n;
        cout << "Case " << z << ": ";

        n = (n+8)%3 + 6;

        vector<vector<vector<int> > > s(3); 
        s[0].resize(100, vector<int>(100, -1));
        s[1].resize(100, vector<int>(100, -1));
        s[2].resize(100, vector<int>(100, -1));

        procedimiento(n, 0, 0, s);
        if(s[0][n][0] == 1) cout << "Bakkar" << endl;
        else cout << "Wahdan" << endl;
    }
    return 0;
}