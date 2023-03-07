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
        vector<int> x(n);
        for(int i=0;i<n;i++) cin>>x[i];

        int res = 1;
        int a = 0, b = 1;

        while(b != n+1)
        {
            while(x[a]<b-a)
            {
                a++;
            }
            cout << b - a << " ";
            b++;
        }
        cout << endl;
    }

    return 0;
}