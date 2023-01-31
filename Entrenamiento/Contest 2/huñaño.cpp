#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int N,S;
        cin>>N>>S;
        vector<int> A(N);
        for(int i=0; i<N; i++)cin>>A[i];
        int ans = 0;
        for(int i=0; i<(1<<N); i++){
            int aux = i;
            int menor=10000;
            int cantidad=0;
            int total=0;
            for(int j=0; j<N; j++){
                if(aux&1){
                    cantidad++;
                    menor=min(menor,A[j]);
                    total+=A[j];
                }
                aux>>=1;
            }
            if(total>=S && total-menor<S){
                ans=max(ans,cantidad);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}