# include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Dame los datos" << endl;
    int n, h;
    cin>>n;
    cin>>h;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int cont = 0;

    for(int i=0;i<n;i++) cont++, cont++;

    cout << cont << endl;

    return 0;
}