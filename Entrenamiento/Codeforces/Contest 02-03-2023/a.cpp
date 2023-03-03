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
        string s;
        cin>>s;
        char c[4] = {'m', 'e', 'o', 'w'};

        bool val = true;

        s[0] = tolower(s[0]);
        if(s[0] != c[0]) val = false;
        if(n<4) val = false;

        int j = 0;
        for(int i=0;i<s.size();i++)
        {
            s[i] = tolower(s[i]);
            if(s[i] != c[j])
            {
                if(j == 3)
                {
                    val = false;
                    break;
                }
                if(s[i] == c[j+1])j++;
                else
                {
                    val = false;
                    break;
                }
            }
        }

        if(val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}