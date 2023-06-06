# include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int procedimiento(int disponibles, int turno)
{
    if(turno >= disponibles) return 1;
    if(dp[disponibles][turno] != -1) return dp[disponibles][turno];

    bool val = false;
    for(int i=1;i<=turno;i++)
    {
        if(procedimiento(disponibles - i, turno + 1) == 0) val = true;
    }

    if(val) return dp[disponibles][turno] = 1;
    return dp[disponibles][turno] = 0;
}

int main()
{
    int n;
    cin>>n;

    dp.resize(n+10, vector<int>(n+10, -1));

    int res = procedimiento(n, 1);

    if(res == 1) cout << "Jane" << endl;
    else cout << "John" << endl;

    return 0;
}