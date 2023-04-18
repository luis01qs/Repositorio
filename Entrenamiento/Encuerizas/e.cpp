# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("prueba.txt", "r", stdin);

    int n;
    cin>>n;

    string s;
    cin>>s;

    int cont = 0;

    bool val = false;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'R')
        {
            val = true;
            for(int j=i;j<n;j++)
            {
                if(s[j] == 'L')
                {
                    if((j-i)%2==0) cont++;
                    i = j;
                    break;
                }
            }
        }

        if(s[i] == 'L')
        {
            val = true;
            for(int j=i;j<n;j++)
            {
                if(s[j] == 'R')
                {
                    cont += j-i-1;
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(s[i] == 'L') break;
        if(s[i] == 'R')
        {
            cont += i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == 'R') break;
        if(s[i] == 'L')
        {
            cont += n-1-i;
            break;
        }
    }

    if(!val) cont = n;
    
    cout << cont << endl;

    return 0;
}