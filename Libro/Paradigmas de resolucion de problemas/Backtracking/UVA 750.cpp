# include <bits/stdc++.h>

using namespace std;

int a, b, cont;
vector<int> res(8, 0);

bool colocar(int r, int c)
{
    for(int i=0;i<c;i++)
    {
        if(res[i] == r || abs(res[i]-r) == abs(i-c)) return false;
    }
    return true;
}

void backtracking(int c)
{
    if(c==8 && res[b] == a)
    {
        cont++;
        cout << cont << " -> ";
        for(auto &e:res) cout << e+1 << " ";
        cout << endl;
        return;
    }

    for(int i=0;i<8;i++)
    {
        if(colocar(i, c))
        {
            res[c] = i;
            backtracking(c+1);
        }
    }
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>a>>b;
        a--, b--; 
        for(int i=0;i<8;i++) res[i] = 0;

        cont = 0;
        backtracking(0);
    }
    return 0;
}