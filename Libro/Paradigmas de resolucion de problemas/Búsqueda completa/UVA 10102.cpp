# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int n;
    while(cin>>n)
    {
        vector<pair<int, int>> c1;
        vector<pair<int, int>> c3;

        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<s.size();j++)
            {
                if(s[j] == '1') c1.push_back({i,j});
                if(s[j] == '3') c3.push_back({i,j});
            }
        }

        int res = 10e8;
        int res2 = 0;
        for(auto &e:c1)
        {
            res = 10e8;
            for(auto &i:c3)
            {
                res = min(res, abs(e.first-i.first) + abs(e.second-i.second));
            }
            res2 = max(res2, res);
        }

        cout << res2 << endl;

    }
    return 0;
}