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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<int> minuscula(26,0);
        vector<int> mayuscula(26,0);

        int cont = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] < 91)
            {
                if(minuscula[s[i]+32-'a'] != 0)
                {
                    minuscula[s[i]+32-'a']--;
                    cont++;
                }
                else
                {
                    mayuscula[s[i]-'A']++;
                }
            }
            else
            {
                if(mayuscula[s[i]-32-'A'] != 0)
                {
                    mayuscula[s[i]-32-'A']--;
                    cont++;
                }
                else
                {
                    minuscula[s[i]-'a']++;
                }
            }
        }

        int extra=0;
        for(auto &e:minuscula) extra += e/2;
        for(auto &e:mayuscula) extra += e/2;

        cout << cont + min(extra, k) << endl;
    }
    return 0;
}