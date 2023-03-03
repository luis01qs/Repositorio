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

        ll res = n-1;
        for(int i=2;i<n;i++)
        {
            if(i==2)
            {
                if(s[i] == s[i-2]) res--;
            }
            else
            {
                if(s[i] == s[i-2]) res--;
            }
        }
        cout << res << endl;
    }
    return 0;
}