//Greedy
# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
int main()
{
    //freopen("prueba.txt","r",stdin);
    int n, k;
    cin>>n>>k;
 
    string s;
    cin>>s;
 
    s = "R" + s;
 
    int cont = 0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i] == s[i+1]) cont++;
    }
 
    if(cont >= k) cont = k;
 
    cout << k-cont << endl;
 
    return 0;
}