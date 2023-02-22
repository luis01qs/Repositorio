//Greedy, usando un tipo de binaria
# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
int main()
{
    ll n;
    cin>>n;
 
    if(n==1)
    {
        cout << "100.0 0.0" << endl;
        return 0;
    }
 
    if(n==2)
    {
        cout << "0.0 100.0" << endl;
        return 0;
    }
 
    double pi, tao;
 
    cout.precision(15);
 
    n -= 2;
    if(n>=50) n=50;
 
    double a=0, b=100;
    bool val = false;
    for(int i=0;i<n;i++)
    {
        //cout << i+3 << ": ";
        pi = (a+b)/2;
        //cout << a << " " << b << " -> " << medio << endl;
 
        if(val)
        {
            a = pi;
            val = false;
        }
        else
        {
            b = pi;
            val = true;
        }
    }
 
    cout << pi << " " << double(100)-pi << endl;
 
    return 0;
}