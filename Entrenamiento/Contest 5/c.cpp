//Greedy
# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
int main()
{
    //freopen("prueba.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int> a(n);
    char c; int cups=0, lec=0;
    for(int i=0;i<n;i++){
      cin>>c; 
      if(c=='1') cups=2, lec++;
      else if(cups) lec++, cups--; 
    }     
    cout<<lec<<endl;
    return 0;
}