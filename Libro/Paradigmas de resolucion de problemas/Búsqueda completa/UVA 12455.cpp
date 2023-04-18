# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int x, n;
        cin>>x>>n;

        vector<int> barras(n);
        for(int i=0;i<n;i++) cin>>barras[i];

        bool val = false;
        int cont;
        for(int i=0;i<(1<<n);i++)
        {
            cont = 0;
            for(int j=0;j<n;j++)
            {
                if((1<<j)&i) cont += barras[j];
            }

            if(cont == x)
            {
                val = true;
                break;
            }
        }

        if(val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}