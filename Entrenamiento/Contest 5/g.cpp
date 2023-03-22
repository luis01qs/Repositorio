# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("pruebasaludos.txt", "r", stdin);
    int n, k;
    cin>>n>>k;

    vector<double> p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    if(k <= 0)
    {
        cout << 1 << endl;
        return 0;
    }

    sort(p.rbegin(), p.rend());


    
    return 0;
}

