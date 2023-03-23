# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n;

    set<int> val;
    val.insert(0);
    val.insert(50);

    for(int i=1;i<21;i++)
    {
        for(int j=1;j<4;j++) val.insert(i*j);
    }

    vector<set<vector<int>>> s(181);

    vector<int> aux;
    for(auto &e:val)
    {
        for(auto &i:val)
        {
            for(auto &o:val)
            {
                aux = {e, i, o};
                sort(aux.begin(), aux.end());
                s[e+i+o].insert(aux);
            }
        }
    }

    while(cin>>n)
    {
        if(n < 1) break;
        
        if(n > 180 || (n <= 180 && s[n].size() == 0))
        {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        else
        {
            int res = 0;
            
            for(auto &a:s[n])
            {
                if(a[0] != a[1] && a[1] != a[2]) res += 6;
                else if((a[0] == a[1] && a[1] != a[2]) || (a[0] != a[1] && a[1] == a[2])) res += 3;
                else res++;
            }

            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << s[n].size() << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << res << "." << endl;
        }

        cout << "**********************************************************************" << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}