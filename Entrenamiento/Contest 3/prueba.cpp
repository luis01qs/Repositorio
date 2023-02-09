# include <bits/stdc++.h>
# define ll long long

using namespace std;

ll base_n(ll x, int n)
{
    int k = 0;
    int cont = 0;
    for(int i=0;x!=0;i++)
    {
        k += (x % n) * pow(10, i);
        x /= n;
    }
    return k;
}

int main()
{
    int x = 180;
    string s = base(x);
    cout << base6(x) << endl; 
    return 0;
}