# include <bits/stdc++.h>
# define ll long long

using namespace std;

void dp()
{

}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n, m;
        cin>>n>>m;

        vector<vector<pair<int, int>>> numeros(n, vector<pair<int,int>>(m, {0,0}));

        int p;
        int aux;

        int maximo3 = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>p;
                aux = p;
                while(aux%2==0)
                {
                    numeros[i][j].first++;
                    aux /= 2;
                }

                int cont = 0;
                aux = p;
                while(aux%3==0)
                {
                    numeros[i][j].second++;
                    aux /= 3;
                    cont++;
                }

                maximo3 = max(maximo3, cont);
            }
        }


    }
    return 0;
}