# include<iostream>
# include<bits/stdc++.h>
using namespace std;

void graph_coloring(vector<int> adj[], int V, vector<int> &color)
{
    // color first node
    color[0] = 0;
    vector<bool> available;
    for(int i=0;i<V;i++)
        available.push_back(true);
    // color from 2nd node
    for(int u=1;u<V;u++)
    {
        for(auto itr = adj[u].begin();itr!=adj[u].end();itr++)
            if(color[*itr] != -1)
                available[color[*itr]] = false;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == true)
                break;

        color[u] = cr;
        for(auto itr = adj[u].begin();itr!=adj[u].end();itr++)
            if(color[*itr] != -1)
                available[color[*itr]] = true;
    }
}
int main()
{
    int V = 8;
    vector<int> adj[V];
    // vector<pair<int,int>> edges { {0,1},{0,5},{0,6},{2,1},{2,3},{4,3},{4,5},{6,7},{5,7}};  // even length cycle still bipartite
    vector<pair<int,int>> edges { {0,1},{0,5},{0,6},{0,7},{2,1},{2,3},{4,3},{4,5},{6,7}};   // odd length cycle requires more than 2 colors
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color;
    for(int i=0;i<V;i++)
        color.push_back(-1);
    graph_coloring(adj, V, color);
    for(int i=0;i<V;i++)
        cout<<i<<"->"<<color[i]<<endl;
    return 0;
}