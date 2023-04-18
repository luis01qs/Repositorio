# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    freopen("resultado.txt", "w", stdout);
    
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    for(ll p1=1;p1<2000;p1++)
    {
        if(pow(p1,4) > 2*10e9) break;
        for(ll p2=p1;p2<2000-p1;p2++)
        {
            if(p1*pow(p2,3) > 2*10e9) break;
            for(ll p3=p2;p3<2000-p1-p2;p3++)
            {
                if(p1*p2*p3*p3 > 2*10e9) break;

                ll b = p1*p2*p3;
                ll c = 1000000;

                if(b==c) continue;

                ll a = p1+p2+p3;
                ll d = c*a;
                ll e = b - c;

                if(d%e != 0) continue;

                ll p4 = d/e;
                if(p3 > p4 || a+p4 > 2000 || b*p4 > 2*10e9) continue;   

                cout << double(p1)/100 << " " << double(p2)/100 << " " << double(p3)/100 << " " << double(p4)/100 << endl;
 
            }
        }
    }

    return 0;
}