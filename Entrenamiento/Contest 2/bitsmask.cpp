# include <bits/stdc++.h>

using namespace std;

int main()
{   
    int a = 34;
    cout << a << endl;
    a = a << 1;
    cout << a << endl;
    a = a >> 2;
    cout << a << endl;
    for(int i=0;i<32;i++)
    {
        cout << (a < i);
    }
    cout << endl;
    return 0;
}