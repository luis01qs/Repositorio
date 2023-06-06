# include <bits/stdc++.h>

using namespace std;

double p, q, r, s, t, u;
double operacion(double x)
{
    return p*exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t *x*x + u;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    freopen("resultado.txt", "w", stdout);

    while(cin>>p>>q>>r>>s>>t>>u)
    {
        double a, b, k;
        double fk;
        a = -0.000001;
        b = 1.000001;
        while(a < b - 0.000001)
        {
            k = (a+b)/2;
            fk = operacion(k);

            if(abs(fk) < 0.0001) break;
            if(fk < 0) b = k;
            if(fk > 0) a = k;
        }

        if(k > 1 || k < 0) cout << "No solution" << endl;
        else printf("%.4f\n", k);
    }

    return 0;
}