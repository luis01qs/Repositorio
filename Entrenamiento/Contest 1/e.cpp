// Greedy
# include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    freopen("ghanophobia.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char s;
        int a, b;
        cin>>a>>s>>b;
        cout << "Case " << i << ": ";
        if(a == 6 && b == 1) cout << "PENALTIES" << endl;
        else if(a + 1 > b + 6) cout << "YES" << endl;
        else if(a + 1 < b + 6) cout << "NO" << endl;
        else if(a + 1 == b + 6)
        {
            if(a < 6) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
 
    return 0;
}