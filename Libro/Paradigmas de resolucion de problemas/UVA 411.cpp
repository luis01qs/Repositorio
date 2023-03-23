# include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int c=0;
    while(cin>>n, n)
    {
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        if(c++) cout << endl;

        sort(a.begin(), a.end());

        for(int i=0;i<n-5;i++)
        {
            for(int j=i+1;j<n-4;j++)
            {
                for(int k=j+1;k<n-3;k++)
                {
                    for(int l=k+1;l<n-2;l++)
                    {
                        for(int m=l+1;m<n-1;m++)
                        {
                            for(int o=m+1;o<n;o++)
                            {
                                cout << a[i] << " ";
                                cout << a[j] << " ";
                                cout << a[k] << " ";
                                cout << a[l] << " ";
                                cout << a[m] << " ";
                                cout << a[o] << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}