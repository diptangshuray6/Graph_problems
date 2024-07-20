#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
#include <list>
void topologicalDfs(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{

  visited[node] = 1;

  for (auto neighbour : adj[node])
  {
    if (!visited[neighbour])
    {
      topologicalDfs(neighbour, visited, s, adj);
    }
    s.push(node);
  }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
  // Write your code here

  // check foer adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][0];

    adj[u].push_back(v);
  }

  // finding topological sort
  vector<bool> visited(v);
  stack<int> s;
  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
      topologicalDfs(i, visited, s, adj);
  }
  vector<int> ans;
  while (!s.empty())
  {
    ans.push_back(s.top());
    s.pop();
  }
  return ans;
}