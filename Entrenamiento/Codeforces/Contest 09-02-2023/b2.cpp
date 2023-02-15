#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int get_sum_diggits(int a){
    int aux=0;
    while(a){
        aux+=(a%10);
        a/=10;
    }
    return aux;
}
 
void get_numbers(int a, int b){
    int sum_a=get_sum_diggits(a);
    int sum_b=get_sum_diggits(b);
    if(abs(sum_a-sum_b)==1){
        cout<<a<<" "<<b<<'\n';
        return;
    }
    int copia_a=a;
    int copia_b=b;
 
    if(sum_a>sum_b){
        int mult = 1;
        while(sum_a-sum_b>1){
            int aux = a%10;
            if(aux+sum_b<=sum_a-aux){
                sum_a-=aux;
                sum_b+=aux;
                copia_a-=(aux*mult);
                copia_b+=(aux*mult);
            }else{
                aux=(sum_a-sum_b)-2;
                sum_a-=aux;
                sum_b+=aux;
                copia_a-=(aux*mult);
                copia_b+=(aux*mult);
            }
            a/=10;
            mult*=10;
        }
        cout<<copia_a<<" "<<copia_b<<'\n';
        return;
    }else{
        int mult = 1;
        while(sum_b-sum_a>1){
            int aux = b%10;
            if(aux+sum_a<=sum_b-aux){
                sum_b-=aux;
                sum_a+=aux;
                copia_b-=(aux*mult);
                copia_a+=(aux*mult);
            }else{
                aux=(sum_b-sum_a)/2;
                sum_b-=aux;
                sum_a+=aux;
                copia_b-=(aux*mult);
                copia_a+=(aux*mult);
            }
            a/=10;
            mult*=10;
        }
        cout<<copia_a<<" "<<copia_b<<'\n';
    }
}
 
int main() {
    int tt;
    cin>>tt;
    while(tt--){
        int N;
        cin>>N;
        if(N==1){
            cout<<1<<" "<<0<<'\n';
        }else if(N&1){
            int num1=N/2+1;
            int num2=N/2;
            get_numbers(num1,num2);
 
        }else{
            cout<<N/2<<" "<<N/2<<'\n';
        }
    }
    return 0;
}