# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    //freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;

        vector<int> numeros(n,0);

        int res = 0;
        cin>>numeros[0];
        for(int i=1;i<n;i++)
        {
            cin>>numeros[i];
            for(int j=0;j<i;j++) if(numeros[i] >= numeros[j]) res++;
        }

        cout << res << endl;
    }
    return 0;
}