#include <bits/stdc++.h>
#define num 10000000
 using namespace std;
 
 
int main(){
long long val=1, res;
bool sat=true;
while(sat){
    cout<<"?"<<" "<<val<<endl<<flush;
    cin>>res;
    if(res!=val){
        cout<<"!"<<" "<<val-res<<endl<<flush;
        sat=false;
        break;
    }
    else{
        val*=2;
    }
}
 return 0;
 }