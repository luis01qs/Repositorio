# include <bits/stdc++.h>
# define ll long long

using namespace std;

void dfs(vector<vector<pair<ll,ll>>> &arbol, vector<ll> &res, ll total, ll padre)
{
    if(arbol[padre].size()==0)
    {
        res.push_back(total);
        return;
    }

    for(auto e:arbol[padre])
    {
        ll total2 = total + arbol[padre][0].first + 2*(e.first-arbol[padre][0].first);
        dfs(arbol,res,total2,e.second);
    }
}  

int binary_search_less(int a, int b, ll x, vector<ll> &res)
{
    if(a == b) return res[a] <= x ? a : -1;
    int k = (b + a) / 2;
    if(x < res[k]) return binary_search_less(a, k, x, res);
    int ret = binary_search_less(k+1, b, x, res);
    return ret == -1 ? k : ret;
}

int main()
{
    freopen("prueba.txt", "r", stdin); //Leer
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<vector<pair<ll,ll>>> arbol(n+1);

        pair<ll, ll> a;
        ll padre;
        for(int i=2;i<=n;i++)
        {
            cin>>padre;
            cin>>a.first;
            a.second = i;
            arbol[padre].push_back(a);
        }

        for(int i=0;i<=n;i++)
        {
            sort(arbol[i].begin(), arbol[i].end());
        }

        vector<ll> res;
        dfs(arbol, res, 0, 1);
        //for(auto &e:res) cout << e << " ";
        //cout << endl;

        /*for(int i=1;i<=n;i++)
        {
            cout << i << endl;
            for(auto &e:arbol[i]) cout << e.first << " " << e.second << endl;
            cout << endl << endl;
        }*/

        sort(res.begin(), res.end());

        ll q;
        cin>>q;
        while(q--)
        {
            ll a;
            cin>>a;
            ll izq=0;
            ll der=res.size();
            while(der-1>izq){
                ll mitad=(izq+der)/2;
                if(res[mitad]>a){
                    der=mitad;
                }else{
                    izq=mitad;
                }
            }
            if(res[izq]>a){
                cout<<0<<'\n';
            }else{
                cout<<izq+1<<'\n';
            }
        }
    }
    return 0;
}