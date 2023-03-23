# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int d, n;
        cin>>d>>n;
        vector<vector<int>> ratas(1030, vector<int>(1030, 0));

        int a, b, p;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>p;
            for(int i=-d;i<=d;i++)
            {
                if(a+i>1024 || a+i<0) continue;
                for(int j=-d;j<=d;j++)
                {
                    if(b+j>1024 || b+j<0) continue;
                    ratas[a+i][b+j] += p;
                }
            }
        }

        int maximo = 0;
        int x, y;
        for(int i=0;i<=1024;i++)
        {
            for(int j=0;j<1024;j++)
            {
                if(ratas[i][j] > maximo)
                {
                    maximo = ratas[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        cout << x << " " << y << " " << maximo << endl;
    }
    return 0;
}