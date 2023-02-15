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
        int n;
        cin>>n;
        vector<int> a(n);
        int cont=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] == 2) cont++;
        }

        if(cont % 2 != 0)
        {
            cout << "-1" << endl;
            continue;
        }

        int res = 0;
        int cont2 = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == 2)
            {
                cont2++;
                if(cont2 == cont/2)
                {
                    res = i;
                    break;
                }
            }
        }
        cout << res + 1 << endl;
    }

    return 0;
}