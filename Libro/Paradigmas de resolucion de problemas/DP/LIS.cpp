# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> lis;
    lis.push_back(a[0]);

    for(int i=1;i<n;i++)
    {
        auto k = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();

        if(k == lis.size()) lis.push_back(a[i]);
        else if(a[i] < lis[k]) lis[k] = a[i];
    }

    return 0;
}