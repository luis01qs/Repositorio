# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    int x, c=0;
    while(cin>>x)
    {
        if(x==0) break;
        if(c++) cout << endl;

        string s = "0123456789";

        bool val = false;
        do
        {
            ll int numero = stoll(s, nullptr, 10);
            ll a = numero/100000;
            ll b = numero%100000;

            if(double(a)/double(b) == x)
            {
                val = true;
                if(a/10000 == 0) cout << 0;
                cout << a << " / ";
                if(b/10000 == 0) cout << 0;
                cout << b << " = " << x << endl;
            }

        } while(next_permutation(s.begin(), s.end()));

        if(!val) cout << "There are no solutions for " << x << "." << endl;
    }
    return 0;
}