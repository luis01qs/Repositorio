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
        long double n;
        cin>>n;
        n--;

        long long res = sqrt(n);
        cout << res << endl;
    }
    return 0;
}

