# include <bits/stdc++.h>

std::vector<int> array;
int binary_search_less(int a, int b, int x)
{
    if(a == b) return array[a] <= x ? a : -1;
    int k = (b + a) / 2;
    if(x < array[k]) return binary_search_less(a, k, x);
    int ret = binary_search_less(k+1, b, x);
    return ret == -1 ? k : ret;
}