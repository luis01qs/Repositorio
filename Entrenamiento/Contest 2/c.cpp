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
        vector<int> v(n, 0);
        char aux;
        fore(i, 0, n)
        {
            cin>>aux;
            if(aux=='*')
            {
                v[i] = 1;
                if(i > 0) v[i-1]=1;
                if(i < n-1) v[i+1]=1;
            }
        }
 
        int cont = 0;
        fore(i, 0, n)
        {
            if(v[i] == 0)
            {
                cont++;
                v[i] = 1;
                if(i < n-1) v[i+1]=1;
                if(i < n-2) v[i+2]=1;
            }
        }
        cout << cont << endl;
    }
    return 0;
}