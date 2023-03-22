# include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;

        int cont = 0;
        if(m==0)
        {
            cont = 1;
            while(n)
            {
                cont *= n;
                n--;
            }

            cout << cont << endl;
            continue;
        }

        vector<vector<int>> res(m);
        for(int i=0;i<m;i++)
        {
            res[i].resize(3);
            cin>>res[i][0]>>res[i][1]>>res[i][2];
        }

        vector<int> a(n);
        for(int i=0;i<n;i++) a[i] = i;
        vector<int> pos(n);

        bool val;
        do
        {
            for(int i=0;i<n;i++) pos[a[i]] = i;

            val = true;
            for(auto &e:res)
            {
                if(e[2] > 0 && abs(pos[e[0]]-pos[e[1]]) > e[2])
                {
                    val = false;
                    break;
                }

                if(e[2] < 0 && abs(pos[e[0]]-pos[e[1]]) < (-e[2]))
                {
                    val = false;
                    break;
                }
            }

            if(val) cont++;

        }while(next_permutation(a.begin(), a.end()));

        cout << cont << endl;

    }
}