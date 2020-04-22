using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 1 ;
vector <int> adj[MAXN] ;
int cost[MAXN] , N , S , dist[MAXN] ;
inline void read(int &x) {
    x = 0; static char c;
    for (; !(c >= '0' && c <= '9'); c = getchar());
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar());
}
long long ans , val ;
bool vis[MAXN] ;
map <long long , int> cnt ;
void DFS (int u) {
    vis[u] = true;
    val += cost[u] ;
    ans += cnt[val - S] ;
    cnt[val]++ ;
    TR(adj[u] , it) {
        if(vis[*it] == false ) DFS(*it) ;
    }
    cnt[val] -- ;
    val -= cost[u] ;
}

int main()
{
#define TASK "SUMTREE"
     // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    memset(vis , false , sizeof(vis)) ;
    read(N) ; read(S) ;
    for(int i = 1 ; i <= N ; ++i ) {
        int par , v ;
        read(par) ; read(v) ;
        cost[i] = v ;
        adj[par].push_back(i) ;
    }
    ans = 0 ; val = 0 ;
    DFS(0) ;
    cout << ans ;

    return 0;
}
using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 1 ;
vector <int> adj[MAXN] ;
int cost[MAXN] , N , S , dist[MAXN] ;
inline void read(int &x) {
    x = 0; static char c;
    for (; !(c >= '0' && c <= '9'); c = getchar());
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar());
}
long long ans , val ;
bool vis[MAXN] ;
map <long long , int> cnt ;
void DFS (int u) {
    vis[u] = true;
    val += cost[u] ;
    ans += cnt[val - S] ;
    cnt[val]++ ;
    TR(adj[u] , it) {
        if(vis[*it] == false ) DFS(*it) ;
    }
    cnt[val] -- ;
    val -= cost[u] ;
}

int main()
{
#define TASK "SUMTREE"
     // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    memset(vis , false , sizeof(vis)) ;
    read(N) ; read(S) ;
    for(int i = 1 ; i <= N ; ++i ) {
        int par , v ;
        read(par) ; read(v) ;
        cost[i] = v ;
        adj[par].push_back(i) ;
    }
    ans = 0 ; val = 0 ;
    DFS(0) ;
    cout << ans ;

    return 0;
}
