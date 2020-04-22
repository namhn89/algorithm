using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
int parent[MAXN] ;
long long d[MAXN] ;
int sum[MAXN] ;
int ans[MAXN] ;
long long dist[MAXN] ;
int w[MAXN] ;
int a[MAXN] ;
vector <int> g[MAXN];
int N, M ;
int len = 0 ;
void make_tree (int u)
{
    if (len >= 0 )
    {
        int it = lower_bound(dist + 1 , dist + len + 1 , d[u] - a[u] ) - dist ;
        if(it <= len)
        {
            sum[len]++;
            if(it > 0) sum[it - 1]--;
        }
    }
    dist[++len] = d[u] ;
    sum[len] = 0 ;
    TR(g[u], it)
    {
        int v = *it ;
        d[v] = d[u] + w[v] ;
        make_tree(v) ;
    }
    ans[u] = sum[len] ;
    if (len > 0 ) sum[len - 1] += sum[len] ;
    len--;
}
int main()
{
#define TASK "739B"
     //freopen(TASK".inp","r",stdin);
     //freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N ;
    FORE(i, 1, N ) cin >> a[i] ;
    FORE(i, 2, N )
    {
        cin >> parent[i] >> w[i] ;
        g[parent[i]].push_back(i) ;
    }
    make_tree(1) ;
    FORE(i, 1 ,N) cout << ans[i] << " " ;


    return 0;
}
