# include <bits/stdc++.h>

using namespace std;

int n, res;
vector<string> s;
bitset<32> d1, d2, col;

void backtracking(int c)
{
    if(c == n)
    {
        res++;
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(col[i] || d1[i+c] || d2[c-i+n-1] || s[c][i] == '*') continue;

        d1[i+c] = col[i] = d2[c-i+n-1] = 1;
        backtracking(c+1);
        d1[i+c] = col[i] =  d2[c-i+n-1] = 0;
    }
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    for(int i=0;i<30;i++)
    {
        d1[i] = d2[i] = col[i] = 0;
    }

    int tt = 1;
    while(cin>>n, n)
    {
        s.resize(n);
        for(int i=0;i<n;i++) cin>>s[i];

        res = 0;
        backtracking(0);

        cout << "Case " << tt << ": ";
        cout << res << endl;
        tt++;
    }
    return 0;
}