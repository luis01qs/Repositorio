# include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(5);
    for(int i=0;i<5;i++) a[i] = i;
    
    do
    {
        for(auto &e:a) cout << e << " ";
        cout << endl;
    } while(next_permutation(a.begin(), a.end()));
    return 0;
}