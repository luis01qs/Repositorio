# include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> edges;

pair<int, int> BFS(int o)
{
    vector<bool> vis(n+1,0);
    queue<pair<int, int>> q;
    q.push({o,0});

    vis[o] = true;

    pair<int, int> nodo;
    while(!q.empty())
    {
        nodo = q.front();
        q.pop();

        if(vis[nodo.first]) continue;
        vis[nodo.first] = true;

        for(auto &e:edges[nodo.first])
        {
            if(!vis[e]) q.push({e, nodo.second+1});
        }
    }

    cout << nodo.first << " " << nodo.second << endl;
    return nodo;
}

int msin()
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

    BFS(1);

    return 0;
}