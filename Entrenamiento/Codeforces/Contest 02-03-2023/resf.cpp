#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
int v[1<<26];
 
int main(){FIN;
freopen("prueba.txt", "r", stdin);
	int n; cin>>n;
	vector<string> a(n);
	vector<int> mk(n),od(n);
	fore(i,0,n){
		string s; cin>>s;
		for(auto x:s) od[i]^=1<<(x-'a'), mk[i]|=1<<(x-'a');
	}
	
	ll ans=0;
	fore(it,0,26)
    {
		int all=((1<<26)-1)^(1<<it);
		fore(i,0,n) if(!(mk[i]&(1<<it))) ans+=v[all^od[i]], v[od[i]]++;
		fore(i,0,n) if(!(mk[i]&(1<<it))) v[od[i]]--;
	}
	
	cout<<ans<<"\n";
}