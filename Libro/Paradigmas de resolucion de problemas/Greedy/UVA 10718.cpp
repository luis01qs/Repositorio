# include <bits/stdc++.h>
# define ll long long

using namespace std;

typedef unsigned int num;

int main()
{
    freopen("prueba.txt", "r", stdin);
    //freopen("resultado.txt", "w", stdout);
    num n, l, u, m;
    while(cin>>n>>l>>u)
    {
        if(l == u)
        {
            cout << l << endl;
            continue;
        }

        m = 0;
        for(int i=31;i>=0;i--)
        {
            if((n >> i) & 1) m |= 0;
            else m |= (1 << i);

            if(m > u) m ^= (1 << i);
            else if(m < l) m |= (l & (1 << i));
        }

        cout << m << endl;
    }
    return 0;
}