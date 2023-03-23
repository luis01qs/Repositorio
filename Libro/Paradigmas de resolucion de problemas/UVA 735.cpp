# include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n;

    set<int> val;
    val.insert(0);
    val.insert(50);

    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<4;j++)
        {
            val.insert(i*j);
        }
    }

    while(cin>>n)
    {
        if(n<=0)break;
        set<set<int>> s;
        set<vector<int>> v;
        int res = 0;
        for(auto &e:val)
        {
            for(auto &i:val)
            {
                for(auto &o:val)
                {
                    if(e+i+o==n)
                    {
                        s.insert({e,i,o});
                        v.insert({e,i,o});
                    }
                }
            }
        }

        if(s.size() == 0)
        {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        else
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << s.size() << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << v.size() << "." << endl;
        }

        cout << "**********************************************************************" << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}