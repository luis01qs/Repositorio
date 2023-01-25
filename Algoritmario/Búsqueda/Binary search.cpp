# include <bits/stdc++.h>

std::vector<int> array;
int binary_search(int a, int b, int x)
{
    if(a >= b) return array[b] == x ? a : -1;
    int k = (b + a) / 2;
    if(x > array[k]) return binary_search(k+1, b, x);
    if(x < array[k]) return binary_search(a, k-1, x);
    return k;
}