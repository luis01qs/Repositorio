//Greedy
# include <bits/stdc++.h>
# define fore(i, a, b) for(int i=a;i<b;i++)
 
using namespace std;
 
int main()
{
    //freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector <int> valores(n);
        int maximo = 0;
        fore(i, 0, n)
        {
            cin>>valores[i];
            maximo = max(valores[i], maximo);
        }
 
        int add=100-maximo;
        fore(i, 0, n) valores[i] += add;
        int cont = 0;
        fore(i, 0, n) if(valores[i] >= 50) cont++;
        cout << cont << endl;
    }
    return 0;
}