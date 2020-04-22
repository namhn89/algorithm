#include <bits/stdc++.h>
using namespace std ;

int n, id ;
char s[10010] ;
vector <vector<int> > g ;
int vis[10010], q[10010] ;

void dfs(int u)
{
  vis[u] = 1 ;
  for(int i = 0; i < g[u].size(); ++i)
   if(!vis[g[u][i]]) dfs(g[u][i]) ;
  id++ ;
  q[id] = u ;
}

int main()
{
  scanf("%d", &n) ;
  g.resize(n + 5) ;
  for(int i = 1; i <= n; ++i)
  {
  	scanf("%s", s + 1) ;
  	for(int j = 1; j <= n; ++j)
	 if(s[j] == '1') g[i].push_back(j) ;
  }
  for(int i = 1; i <= n; ++i)
   if(!vis[i]) dfs(i);
  for(int i = n; i >= 1; --i) printf("%d ", q[i]) ;
  return 0 ;
}
