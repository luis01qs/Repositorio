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
        vector<int> precios(n);
        int media = 0;
        int res = 0;
        int rem;

        int t1, t2;
        for(int i=0;i<n;i++)
        {
            scanf("%d.%d", &t1, &t2);
            precios[i] = t1*100 + t2;
            media += precios[i];
        }

        rem = media%n;
        media = media / n;
        sort(precios.rbegin(), precios.rend());

        for(int i=0;i<rem;i++) res += abs(precios[i]-media-1);
        for(int i=rem;i<n;i++) res += abs(precios[i]-media);

        printf("$%.2lf\n", res/200.0);

    }
    return 0;
}