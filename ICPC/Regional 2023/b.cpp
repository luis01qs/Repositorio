# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("casos.txt", "r", stdin);
    int n;
    cin>>n; 
    n *= 3;

    map<int, int> mapa;
    set<int> s;

    cout << n << endl;

    int aux;
    for(int i=0;i<n;i++)
    {
        cin>>aux;
        s.insert(aux);

        cout << mapa[aux] << endl;
        mapa[aux]++;
    }

    bool val = true;
    for(auto &e:s)
    {
        cout << mapa[e] << endl;
        if(mapa[e]%3 != 0)
        {
            val = false;
            //break;
        }
    }

    if(val) cout << "Y" << endl;
    else cout << "N" << endl;


    return 0;
}