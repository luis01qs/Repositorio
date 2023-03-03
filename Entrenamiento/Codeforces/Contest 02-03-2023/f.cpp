# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n;
    cin>>n;

    vector<string> cadenas(n);
    vector<int> mb(n, 0), tl(n, 0);

    for(int i=0;i<n;i++)
    {
        cin>>cadenas[i];
        for(char x:cadenas[i])
        {
            mb[i] ^= 1<<(x-'a');
            tl[i] |= 1<<(x-'a');
        }
    }

    ll res = 0;




    return 0;
}