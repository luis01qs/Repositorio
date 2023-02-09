# include <bits/stdc++.h>

// x = número en base 10, n = nueva base
int base_n(int x, int n)
{
    int k = 0;
    for(int i=0;x!=0;i++)
    {
        k += (x % n) * pow(10, i);
        x /= n;
    }
    return k;
}
