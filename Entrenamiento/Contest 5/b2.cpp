# include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> edges;

pair<int, int> BFS(int o)
{
    vector<bool> vis(n+1,false);
    queue<pair<int, int>> q;
    q.push({o,0});

    pair<int, int> nodo;
    while(!q.empty())
    {
        nodo = q.front();
        q.pop();
        //cout << nodo.first << endl;

        if(vis[nodo.first]) continue;
        vis[nodo.first] = true;

        for(auto &e:edges[nodo.first])
        {
            if(vis[e] == 0) q.push({e, nodo.second+1});
        }
    }
    nodo.second++;

    //cout << nodo.first << " " << nodo.second << endl;
    return nodo;
}

int main()
{
    freopen("prueba.txt", "r", stdin);
    int n;
    cin>>n;

    edges.resize(n+1);

    int u, v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if(BFS(BFS(1).first).second <= 3)
    {
        cout << "NO" << endl;
        return 0;
    }

    

    return 0;
}