#include <unordered_map>
#include <set>
#include <queue>
#include <list>
void prepareAdjList(unordered_map<int, list<int>> adjlist, vector<vector<int>> &adj)
{

  for (int i = 0; i < adj.size(); i++)
  {
    int u = adj[i].first;
    int v = adj[i].second;

    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }
}
void bfs(unordered_map<int, list<int>> adjlist, unordered_map<int, bool> visited, vector<int> ans, int node)
{
  queue<int> q;
  q.push(node);
  visited[node] = 1; // True

  while (!q.empty())
  {
    int frontNode = q.front();
    q.pop();

    ans.push_back(frontNode); // catch koro

    for (auto i : adjlist[frontNode])
    {
      if (!visited)
      {
        q.push(i);
        visited[i] = 1; // true
      }
    }
  }
} //  edges
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{

  unordered_map<int, list<int>> adjlist;
  vector<int> ans;
  unordered_map<int, bool> visited;

  prepareAdjList(adjlist, adj);

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      bfs(adjlist, visited, ans, i);
    }
  }
  return ans;
}