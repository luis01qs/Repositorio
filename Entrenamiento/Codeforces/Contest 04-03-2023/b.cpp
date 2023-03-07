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
        vector<ll> a(n);
        int cont = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] == 1) a[i]++, cont++;
        }

        if(n == 1)
        {
            cout << a[0] << endl;
            continue;
        }

        cout << a[0] << " ";
        for(int i=1;i<n;i++)
        {
            while(a[i] % a[i-1] == 0)
            {
                a[i]++;
                cont++;
            }
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}