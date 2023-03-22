# include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int x;
        cin>>x;
        int n;
        cin>>n;

        vector<int> largo(n);
        for(int i=0;i<n;i++) cin>>largo[i];

        bool val = false;

        int suma = 0;
        for(int i=0;i<(1<<n);i++)
        {
            suma = 0;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j)) suma += largo[j];
            }

            if(suma == x)
            {
                val = true;
                break;
            }
        }

        if(val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}