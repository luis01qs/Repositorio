# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int n;
    while(cin>>n)
    {
        vector<int> libros(n);
        for(int i=0;i<n;i++) cin>>libros[i];
        sort(libros.begin(), libros.end());

        int m;
        cin>>m;

        int libro1 = 0, libro2 = 0;

        bool val;
        int a, b, k;
        for(int i=0;i<n;i++)
        {
            if(libros[i] > m/2) break;

            a = i;
            b = n;
            val = false;

            while(a < b-1)
            {
                k = (a+b)/2;
                if(k != i && libros[i] + libros[k] == m)
                {
                    val = true;
                    break;
                }

                if(libros[i] + libros[k] > m) b = k;
                else a = k;
            }

            if(val)
            {
                libro1 = libros[i];
                libro2 = libros[k];
            }
        }

        cout << "Peter should buy books whose prices are " << libro1  << " and " << libro2 << "." << endl << endl;
    }
    return 0;
}