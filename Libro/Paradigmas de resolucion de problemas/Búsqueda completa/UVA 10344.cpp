# include <bits/stdc++.h>

using namespace std;

vector<int> a(5);

bool procedimiento(int numero, int pos)
{
    if(pos == 5) return numero == 23;

    bool val = procedimiento(numero * a[pos], pos + 1);
    val |= procedimiento(numero + a[pos], pos + 1);
    val |= procedimiento(numero - a[pos], pos + 1);
    
    return val;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);
    while(true)
    {
        for(int i=0;i<5;i++)cin>>a[i];
        sort(a.begin(), a.end());

        if(a[0] == a[4] && a[0] == 0) break;

        bool val = false;
        do
        {
            val = procedimiento(a[0] + a[1], 2);
            val |= procedimiento(a[0] * a[1], 2);
            val |= procedimiento(a[0] - a[1], 2);
            if(val) break;
        } while (next_permutation(a.begin(), a.end()));
        

        if(val) cout << "Possible" << endl;
        else cout << "Impossible" << endl;

    }
    return 0;
}