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
        int n, k;
        cin>>n>>k;
        string s, t;
        cin>>s>>t;

        vector<int> ls(26,0);
        vector<int> lt(26,0);
        for(int i=0;i<n;i++) ls[s[i]-'a']++;
        for(int i=0;i<n;i++) lt[t[i]-'a']++;

        bool val = true;
        for(int i=0;i<26;i++)
        {
            if(ls[i] != lt[i]) val = false;
        }

        for(int i=0;i<n;i++)
        {
            if(s[i] != t[i] && i<k && i>=n-k) val = false;
        }

        if(val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}