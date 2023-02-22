# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin); //Leer
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n, m;
        cin>>n>>m;
        string s1, s2;
        cin>>s1>>s2;

        reverse(s2.begin(), s2.end());

        string s = s1 + s2;
        int iguales = 0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i] == s[i+1])iguales++;
        }

        if(iguales>1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}