# include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, e;
    cin>>n>>k>>e;
    
    int der = n - e - k;
    int izq = e;

    vector<bool> val(n+10, 0);
    val[k] = true;
    val[0] = true;

    for(int p=n;p>=0;p--)
    {
        if(izq-p>=0 && val[p]==0)
        {
            izq -= p;
            val[p] = true;
        }
    }

    for(int p=n;p>=0;p--)
    {
        if(der-p>=0 && val[p]==0)
        {
            der -= p;
            val[p] = true;
        }
    }

    int res1 = der + izq;

    izq = e;
    der = n - e - k;
    for(int p=0;p<n+5;p++) val[p] = false;

    val[k] = true;
    val[0] = true;

    for(int p=n;p>=0;p--)
    {
        if(der-p>=0 && val[p]==0)
        {
            der -= p;
            val[p] = true;
        }
    }

    for(int p=n;p>=0;p--)
    {
        if(izq-p>=0 && val[p]==0)
        {
            izq -= p;
            val[p] = true;
        }
    }

    int res2 = der + izq;
    cout << min(res1, res2) << endl;

    return 0;
}