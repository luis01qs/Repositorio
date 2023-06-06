# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int n;
    while(cin>>n, n)
    {
        vector<int> num(n);
        for(int i=0;i<n;i++) cin>>num[i];

        int maximo = INT_MIN;
        int suma = 0;
        for(int i=0;i<n;i++)
        {
            suma += num[i];
            maximo = max(maximo, suma);
            if(suma < 0) suma = 0;
        }

        if(suma <= 0) cout << "Losing streak." << endl;
        else cout << "The maximum winning streak is " << maximo << "." << endl;
    }
    return 0;
}