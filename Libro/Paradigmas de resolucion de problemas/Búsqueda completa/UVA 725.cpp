# include <bits/stdc++.h>
# define ll long long

using namespace std;

int main()
{
    int n, c=0;
    while(cin>>n)
    {
        bool val = false;
        if(!n)break;

        if(c++) cout << endl;

        for(int b=1234;b<=98765/n;b++)
        {
            int a = b * n;
            int tmp, used = (b < 10000);

            tmp = a; 
            while(tmp)
            {
                used |= 1 << (tmp%10);
                tmp /= 10;
            }

            tmp = b;
            while(tmp)
            {
                used |= 1 << (tmp%10);
                tmp /= 10;
            }

            if(used == (1<<10)-1)
            {
                val = true;
                printf("%0.5d / %0.5d = %d\n", a, b, n);
            }
        }

            // nuevas cosas
        if(!val) cout << "There are no solutions for " << n << "." << endl;
    }
    return 0;
}