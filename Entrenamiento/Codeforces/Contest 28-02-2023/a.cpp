# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);
    int tt;
    cin>>tt;

    string FB = "";
    for(int i=3;i<1000;i++)
    {
        if(i%3 == 0) FB += 'F';
        if(i%5 == 0) FB += 'B';
    }

    while(tt--)
    {
        int k;
        string s;
        cin>>k>>s;

        bool val = true;
        bool val2 = false;
        for(int i=0;i<200;i++)
        {
            val = true;
            for(int j=0;j<s.size();j++)
            {
                if(s[j] != FB[i+j])
                {
                    val = false;
                    break;
                }
            }

            if(val == true)
            {
                val2 = true;
                break;
            }
        }

        if(val2 == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}