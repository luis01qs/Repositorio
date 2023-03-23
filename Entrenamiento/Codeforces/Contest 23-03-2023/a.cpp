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
        string s;
        cin>>s;

        sort(s.begin(), s.end());
        if(s[0] == s[3])
        {
            cout << -1 << endl;
            continue;
        }

        if(s[0] == s[1] && s[1] == s[2] && s[2] != s[3])
        {
            cout << 6 << endl;
            continue;
        }

        if(s[0] != s[1] && s[1] == s[2] && s[2] == s[3])
        {
            cout << 6 << endl;
            continue;
        }

        cout << 4 << endl;

    }
    return 0;
}

