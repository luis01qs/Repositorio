# include <bits/stdc++.h>
# define ll long long

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
        vector<string> cadenas;
        for(int i=0;i<2*(n-1);i++)
        {
            string s;
            cin>>s;
            cadenas.push_back(s);
        }

        vector<string> c;
        for(auto &s:cadenas)
        {
            if(s.size() == n-1)
            {
                c.push_back(s);
            }
        }

        bool val = true;
        if(c[0].size() != 1)
        {
            for(int i=0;i<c[0].size()-1;i++)
            {
                if(c[0][i+1] != c[1][i]) val = false;
            }
        }

        //cout << c[0] << " -> " << c[1] << endl;
        if(val == false) swap(c[0], c[1]);
        //cout << c[0] << " -> " << c[1] << endl;

        string s = c[0] + c[1][c[1].size()-1];
        //cout << s << endl;

        val = true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != s[s.size()-i-1]) val = false;
        }

        if(val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}