# include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 14235;
    cout << bitset<31>(a) << endl;
    
    if(a&(1<<11)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}