# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        
        int cont = 0;
        bool val = true;
        for(int i=0;i<s.size();i++)
        {
            if(i&2 xor val)
            {
                if(i == s.size()-1) cont++;
                else
                {
                    if(s[i] != s[i+1])
                    {
                        cont++;
                        val = (val + 1)%2;
                    }
                }
            }
        }
        cout << cont << endl;
    }
    return 0;
}