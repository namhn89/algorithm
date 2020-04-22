#include <bits/stdc++.h>

int minimalCost(std::vector<int> c, std::vector<int> a)
{
  int n = c.size();
  std::vector<int> gc[n + 1], gr[n + 1];
  int idComponent[n + 1];
  bool used[n + 1];
  std::vector<int> order;
  std::vector<int> component[n + 1];
  bool out[n + 1];
  
  for (int i = 0; i < n; ++ i)
  {
    gc[i + 1].push_back(a[i]);
    gr[a[i]].push_back(i + 1);
  }

  for (int i = 1; i <= n; ++ i) used[i] = false;
  std::function<void(int)> dfs1 = [&](int u) {
    used[u] = true;
    for (int v : gc[u])
    {
      if (!used[v]) dfs1(v);
    }
    order.push_back(u);
  };

  for (int i = 1; i <= n; ++ i) used[i] = false;

  std::function<void(int, int)> dfs2 = [&](int u, int nComponent)
  {
    used[u] = true;
    component[nComponent].push_back(u);
    idComponent[u] = nComponent;
    for (int v : gr[u])
    {
      if (!used[v]) dfs2(v, nComponent);
    }
  };

  for (int u = 1; u <= n; ++ u) used[u] = false;

  for (int i = 1; i <= n; ++ i)
  {
    if (!used[i]) dfs1(i);
  }

  int nComponent = 0;

  for (int u = 1; u <= n; ++ u) used[u] = false;

  for (int i = n - 1; i >= 0; -- i)
  {
    int u = order[i];
    if (!used[u]) dfs2(u, ++ nComponent);
  } 

  for (int i = 1; i <= n; ++ i) out[i] = false;

  for (int i = 0; i < n; ++ i)
  {
    if (idComponent[i + 1] == idComponent[a[i]]) continue;
    out[idComponent[i + 1]] = true;
  } 

  int ans = 0;

  for (int i = 1; i <= nComponent; ++ i)
  {
    if (out[i]) continue;
    int foo = (int)1e9;
    for (int u : component[i]) foo = std::min(foo, c[u - 1]);
    ans += foo; 
  }

  return ans;
}