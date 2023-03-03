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

        string c = s;
        int i=0;
        for(int p=0;p<s.size();p++)
        {
            if(p==0) c[s.size()-1] = s[0];
            else
            {
                c[i] = s[p];
                i++;
            }
        }
        cout << c << endl;
        string c1 = c;
        reverse(c1.begin(), c1.end());
        string res = min(c, c1);
        
    }
    return 0;
}