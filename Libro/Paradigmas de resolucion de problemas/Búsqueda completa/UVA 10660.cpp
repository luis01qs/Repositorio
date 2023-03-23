# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    vector<pair<int, int>> c;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            c.push_back({i, j});
        }
    }

    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt--)
    {
        vector<vector<int>> mapa(5, vector<int>(5, 0));
        int m;
        cin>>m;

        ll a, b, x;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>x;
            mapa[a][b] = x;
        }

        vector<int> res = {0,0,0,0,0};
        ll minimo = 10e17;
        ll suma, suma2;
        ll d;

        for(int i1=0;i1<21;i1++)
        {
            for(int i2=i1+1;i2<22;i2++)
            {
                for(int i3=i2+1;i3<23;i3++)
                {
                    for(int i4=i3+1;i4<24;i4++)
                    {
                        for(int i5=i4+1;i5<25;i5++)
                        {
                            suma = 0;
                            for(int i=0;i<25;i++)
                            {
                                if(mapa[c[i].first][c[i].second] == 0) continue;
                                d = mapa[c[i].first][c[i].second];
                                a = c[i].first;
                                b = c[i].second;

                                suma2 = abs(a-c[i1].first)+abs(b-c[i1].second);
                                suma2 = min(suma2, abs(a-c[i2].first)+abs(b-c[i2].second));
                                suma2 = min(suma2, abs(a-c[i3].first)+abs(b-c[i3].second));
                                suma2 = min(suma2, abs(a-c[i4].first)+abs(b-c[i4].second));
                                suma2 = min(suma2, abs(a-c[i5].first)+abs(b-c[i5].second));

                                suma += d*suma2;
                            }

                            if(suma < minimo)
                            {
                                res = {i1, i2, i3, i4, i5};
                                minimo = suma;
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<5;i++)
        {
            cout << res[i];
            if(i != 4) cout << " "; 
        }
        cout << endl;
    }
    return 0;
}