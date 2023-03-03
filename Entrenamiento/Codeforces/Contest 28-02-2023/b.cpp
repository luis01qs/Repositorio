# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        string a;
        string b;
        cin>>a>>b;

        int n = a.size();
        int m = b.size();

        if(a[0] == b[0])
        {
            cout << "YES" << endl;
            cout << a[0] << "*" << endl;
            continue;
        }

        if(a[n-1] == b[m-1])
        {
            cout << "YES" << endl;
            cout << "*" << a[n-1] << endl;
            continue;
        }

        if(n == 1 || m == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        string res;
        bool val = false;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(a[i] == b[j] && a[i+1] == b[j+1])
                {
                    cout << "YES" << endl;
                    cout << '*' << a[i] << a[i+1] << '*' << endl;
                    val = true;
                    break;
                }
            }
            if(val) break;
        }

        if(!val)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}