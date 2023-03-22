# include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int A, B, C;
        cin>>A>>B>>C;

        bool val = false;

        for(int x=-100;x<=100;x++)
        {
            for(int y=-100;y<=100;y++)
            {  
               if(y == x) continue;
               int z = A - y - x; 
               if(z == x || z == y) continue;

               if(x*y*z==B && x*x+y*y+z*z==C)
               {
                    val = true;
                    cout << x << " " << y << " " << z << endl;
                    break;
               }
            }

            if(val) break;
        }

        if(!val) cout << "No solution." << endl;
    }
    return 0;
}