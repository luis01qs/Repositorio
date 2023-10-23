# include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int a;
    char b;

    for(int i=0;i<20;i++)
    {
        a = rand() % 3 + 2;
        b = 'a';
        b += rand() % (119-97);
        cout << a << "." << b << endl;
    }

    return 0;
}