# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int n;
    while(cin>>n, n)
    {
        vector<int> numeros(n);
        for(int i=0;i<n;i++) cin>>numeros[i];

        bool val = false;
        for(int i=0;i<n;i++)
        {
            if(numeros[i] != 0)
            {
                if(val) cout << " ";
                cout << numeros[i];
                val = true;
            }
        }

        if(!val) cout << 0;

        cout << endl;
    }
    return 0;
}