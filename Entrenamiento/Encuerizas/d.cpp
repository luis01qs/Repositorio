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
        int a, b;
        cin>>a>>b;

        a = abs(a);
        b = abs(b);

        if(a > b) swap(a,b);

        if(b - a < 2)
        {
            cout << a + b << endl;
            continue;
        }

        cout << a + b + (b-a-1) << endl;
    }

    return 0;
}