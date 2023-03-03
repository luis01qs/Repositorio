# include <bits/stdc++.h>
# define ll long long

using namespace std;

void divmia(int &ai, int &aj)
{
    ai = ceil(double(ai)/double(aj));
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        vector<pair<int, int>> a(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i].first;
            a[i].second = i+1;
        }

        sort(a.begin(), a.end());

        if(n == 1 || a[0].first == a[n-1].first)
        {
            cout << 0 << endl;
            continue;
        }

        if(a[0].first == 1 && a[n-1].first != 1)
        {
            cout << -1 << endl;
            continue;
        }

        cout << "Nuevo" << endl;
        for(int i=1;i<n;i++)
        {
            while(a[i].first >= a[0].first)
            {
                divmia(a[i].first, a[0].first);
                cout << a[i].second << " " << a[0].second << endl;
            }
        }

        for(auto &e:a) cout << e.first << " ";
        cout << endl;
    }
    return 0;
}