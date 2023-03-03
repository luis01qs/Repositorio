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

        vector<bool> dif(n, 1);
        for(int i=0;i<n;i++)
        {
            if(s[i] != s[n-i-1])
            {
                s[n-i-1] = s[i];
                dif[i] = false;
            }
        }

        int cont = 0;
        for(int i=0;i<n-1;i++)
        {
            if(dif[i] == 0 && dif[i+1] == 1) cont++;
        }
        
        if(cont >= 2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}