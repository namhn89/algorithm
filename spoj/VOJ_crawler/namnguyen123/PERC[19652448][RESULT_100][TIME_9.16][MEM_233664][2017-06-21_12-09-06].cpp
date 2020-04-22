using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e6 + 5 ;
vector <int> g[MAXN] ;
int a[MAXN] , n ;
int low[MAXN] , num[MAXN] , vis[MAXN] , id[MAXN] ;
stack <int> S ;
vector <int> f[MAXN] ;
int nscc = 0 , vtime = 0 ;
int DFS (int u)
{
    low[u] = num[u] = ++vtime ;
    vis[u] = 1 ;
    S.push(u) ;
    TR(g[u] , it)
    {
        int v = *it ;
        if (id[v] != -1) continue ; // Cung  cheo
        if (!vis[v])
        {
            low[u] = min(low[u] , DFS(v))  ; // Cung xuoi
        }
        else
        {
            low[u] = min(low[u] , num[v]) ; // Cung nguoc
        }
    }
    if (low[u] == num[u])
    {
        nscc++;
        while(1)
        {
            int v = S.top() ;
            S.pop() ;
            id[v] = nscc ;
            f[nscc].push_back(v) ;
            if (v == u) break ;
        }
    }
    return low[u] ;
}
long long LCM (long long a , long long b) {
  return 1LL * a * b / __gcd(a , b) ;
}
vector <int> fact[MAXN] ;
long long power (long long a , long long n) {
   a %= MOD ;
   long long res = 1 ;
   while(n) {
      if (n & 1) res = (res * a) % MOD ;
      a = (a * a) % MOD ;
      n >>= 1 ;
   }
   return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    nscc = 0 ;
    vtime = 0 ;
    memset(id , -1 , sizeof (id) ) ;
    memset(vis , 0 , sizeof (vis) ) ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i] ;
    for(int i = 1 ; i <= n ; ++i ) {
        int u = a[i] ;
        int v = a[a[i]] ;
        g[u].push_back(v) ;
    }
    for(int i = 1 ; i <= n ; ++i) if (!vis[i]) DFS(i) ;
    for(int i = 1 ; i <= nscc ; ++i ) {
        int v = f[i].size() ;
        for(int p = 2 ; p * p <= v ; ++p) {
            if (v % p == 0) {
                int cnt = 0 ;
                while(v % p == 0) v /= p , cnt++;
                fact[p].push_back(cnt) ;
            }
        }
        if (v > 1) fact[v].push_back(1) ;
    }
    long long ans = 1;
    for(int i = 1 ; i <= n ; ++i) {
        if (fact[i].size() == 0) continue ;
        int Max = 0 ;
        TR(fact[i] , it) Max = max(Max , *it) ;
        ans = (ans * power(i , Max)) % MOD ;
    }
    cout << ans << endl;
    return 0;
}
