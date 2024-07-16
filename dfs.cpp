#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include<set>

void dfscall(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component)
{
  component.push_back(node);
  visited[node] = true;

  for (auto i : adj[node])
  {
    if (!visited[i])
    {
      dfscall(i, adj, visited, component);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
  // prepare an adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  vector<vector<int>> ans;
  unordered_map<int, bool> visited;

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      vector<int> component;
      dfscall(i, adj, visited, component);
      ans.push_back(component);
    }
  }
  return ans;
}
