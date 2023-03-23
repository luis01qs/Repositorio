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
        int n, k;
        cin>>n>>k;

        vector<int> res(n, -1);

        if(k==0)
        {
            for(int i=0;i<n;i++) cout << res[i] << " ";
            cout << endl;
            continue;
        }

        int cont = 0;
        res[0] = 30;
        int suma;

        for(int i=0;i<n;i++)
        {
            if(cont >= k) break;
            res[i] = 30;
            suma = 0;
            for(int j=i;j<n;j++)
            {
                suma += res[j];
                if(suma > 0) cont++;

                if(cont > k)
                {
                    res[j] = -suma-2;
                    break;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;

    }
    return 0;
}

