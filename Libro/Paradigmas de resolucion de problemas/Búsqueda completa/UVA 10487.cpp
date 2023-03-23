# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    //freopen("resultado.txt", "w", stdout);
    int n;
    int cont = 1;
    while(cin>>n, n)
    {
        vector<int> num(n);
        for(int i=0;i<n;i++) cin>>num[i];

        cout << "Case " << cont << ":" << endl;
        cont++;

        sort(num.begin(), num.end());

        int m;
        cin>>m;
        int q;
        for(int p=0;p<m;p++)
        {  
            int suma = 10e8;
            cin>>q;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j && abs(suma - q) > abs(num[i] + num[j] - q)) suma = num[i] + num[j];
                }
            }
            cout << "Closest sum to " << q << " is " << suma << "." << endl;
        }
    }
    return 0;
}