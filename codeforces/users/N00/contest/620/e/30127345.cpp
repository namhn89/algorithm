using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 4e5 + 5 ;

vector <int> g[MAXN] ;
int in[MAXN] , out[MAXN] , tick , n , m , c[MAXN] , val[8 * MAXN] ;
long long Tree[MAXN * 8] , add[MAXN * 8] ;
void dfs (int u , int parent ) {
    in[u] = ++tick ;
    val[tick] = u ;
    TR(g[u] , it) {
       if (*it == parent) continue ;
       dfs(*it , u) ;
    }
    out[u] = tick ;
}
void push (int k) {
    if (add[k] == -1) return ;
        Tree[2 * k] = add[2 * k] = add[k] ;
        Tree[2 * k + 1] = add[2 * k + 1] = add[k] ;
        add[k] = -1 ;
}
void build (int k , int l , int r) {
    if (l == r) {
        Tree[k] = 1LL << c[val[l]] ;
        add[k] = -1 ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build(2 * k , l , mid) ;
    build(2 * k + 1 , mid + 1 , r) ;
    Tree[k] = Tree[2 * k] | Tree[2 * k + 1] ;
    add[k] = -1 ;
    return ;
}
void update (int k , int L , int R , int le , int ri , int c) {
    if (L > ri || R < le) return ;
    if (le <= L && R <= ri) {
        Tree[k] = 1LL << c ;
        add[k] =  1LL << c ;
        return ;
    }
    push(k) ;
    int mid = (L + R) / 2 ;
    update(2 * k , L , mid , le , ri , c) ;
    update(2 * k + 1 , mid + 1 , R , le , ri , c) ;
    Tree[k] = (Tree[2 * k] | Tree[2 * k + 1]) ;
}
long long query (int k , int L , int R , int le , int ri) {
    if (L > ri || R < le) return 0 ;
    if (le <= L && R <= ri ) return Tree[k] ;
    push(k) ;
    int mid = (L + R) / 2 ;
    long long ans = 0 ;
    ans = (ans | query(2 * k , L , mid , le , ri)) ;
    ans = (ans | query(2 * k + 1 , mid + 1 , R , le , ri)) ;
    return ans ;
}
int main()
{
#define TASK "620E"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &m) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d", &c[i]) ;
    for(int i = 1 ; i < n ; ++i ) {
        int u , v ;
        scanf("%d %d", &u , &v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    tick = 0 ;
    dfs(1 , -1) ;
    build(1 , 1 , n) ;
    while(m--){
        int type ;
        scanf("%d", &type) ;
        if (type == 1) {
            int u , c ;
            scanf("%d %d", &u , &c) ;
            update(1 , 1 , n , in[u] , out[u] , c) ;
        }
        else {
            int v ;
            scanf("%d", &v) ;
            long long ans = query(1 , 1 , n , in[v] , out[v]) ;
            printf("%d\n", __builtin_popcountll(ans) ) ;
        }
    }
    return 0;
}
