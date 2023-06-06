# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int x;
    while(cin>>x)
    {
        int n;
        cin>>n;
        vector<int> papas(n);

        for(int i=0;i<n;i++) cin>>papas[i];

        int maximo = 0;
        int primero, ultimo;
        primero = papas[0], ultimo = papas[0];

        int a, b, k;
        int actual;
        for(int i=0;i<n;i++)
        {
            a = i;
            b = n;
            actual = papas[i];
            while(a < b-1)
            {
                k = (a+b)/2;
                if(papas[k]-actual >= x)
                {
                    b = k;
                }
                else
                {
                    a = k;
                }
            }

            if((a-i+1)>maximo)
            {
                maximo = a-i+1;
                ultimo = papas[a];
                primero = papas[i];
            }
            
        }
        cout << maximo << " " << primero << " " << ultimo << endl;
    }
    return 0;
}