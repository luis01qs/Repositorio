# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    int k;
    while(cin>>k)
    {
        vector<pair<int, int>> res;
        int cont = 0;
        for(int y=k+1;y<100000;y++)
        {
            double x = double(k*y)/double(y-k);
            //cout << x << endl;
            if(x == floor(x) && x >= y)
            {
                cont++;
                res.push_back({int(x), y});
            }
        }

        cout << cont << endl;
        for(auto &e:res)
        {
            cout << "1/" << k << " = 1/" << e.first << " + 1/" << e.second << endl; 
        }
    }
    return 0;
}