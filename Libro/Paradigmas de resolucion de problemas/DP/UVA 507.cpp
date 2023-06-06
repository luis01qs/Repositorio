// Solución al ejercicio 507 de Online Judge UVA usando Jay Kadane
# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    for(int zz=1;zz<=tt;zz++)
    {
        int n;
        cin>>n;
        n--;

        vector<int> numeros(n);
        for(int i=0;i<n;i++) cin>>numeros[i];

        int suma = 0;
        int maximo = INT_MIN;
        int aux = 1;

        int l1=0, l2, r1, r2;
        for(int i=0;i<n;i++)
        {
            suma += numeros[i];

            r1 = i + 1;

            if(maximo == suma)
            {
                if(r2 - l2 < r1 - l1)
                {
                    r2 = r1;
                    l2 = l1;
                }
            }
            else if(maximo < suma)
            {
                maximo = suma;
                r2 = r1;
                l2 = l1;
            }

            if(suma < 0)
            {
                suma = 0;
                r1 = i+1;
                l1 = i+1;
            }
        }

        if(maximo >= 0) cout << "The nicest part of route "<< zz << " is between stops "<< l2+1 << " and "<< r2 + 1 << endl;
        else cout << "Route " << zz << " has no nice parts" << endl;
    }
    return 0;
}