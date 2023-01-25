# include <bits/stdc++.h>

std::vector<int> array;
int binary_search_more(int a, int b, int x)
{
    if(a == b) return array[a] >= x ? a : -1;
    int k = (b + a) / 2;
    if( x > array[k] ) return binary_search_more(k+1, b, x);
    int ret = binary_search_more(a, k, x);
    return ret == -1 ? k : ret;
}