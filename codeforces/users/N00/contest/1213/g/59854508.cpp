using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

struct Edge {
    int u, v, w ;
    Edge (int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator < (const Edge &other) const {
        return w < other.w ;
    }
};
const int MAXN = 2e5 + 1 ;
const int MAXW = 1e9 + 1;
int n, q;
int par[MAXN], cnt[MAXN];
pair <int, int> query[MAXN];
long long ans[MAXN];
Edge e[MAXN];

int findSet (int u) {
    if (u == par[u]) return u ;
    else return par[u] = findSet(par[u]);
}
void Union (int u, int v, long long &ans){
    int x = findSet(u), y = findSet(v) ;
    if (cnt[x] < cnt[y]) swap(x, y);
    ans -= 1LL * cnt[x] * (cnt[x] - 1)/ 2 ;
    ans -= 1LL * cnt[y] * (cnt[y] - 1)/ 2 ;
    cnt[x] += cnt[y] ;
    ans += 1LL * cnt[x] * (cnt[x] - 1)/ 2 ;
    par[y] = x ;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q ;
    for (int i = 1; i <= n ; ++i) par[i] = i, cnt[i] = 1;
    for (int i = 1; i < n; ++i){
        cin >> e[i].u >> e[i].v >> e[i].w ;
    }
    e[n].w = MAXW;
    for (int i = 1; i <= q; ++i){
        cin >> query[i].first ;
        query[i].second = i;
    }
    sort(e + 1, e + n);
    sort(query + 1, query + q + 1);
    int pos = 1;
    long long res = 0;
    for (int i = 1 ; i <= q ; ++i){
        while(e[pos].w <= query[i].first){
            int x = e[pos].u, y = e[pos].v ;
            Union(x, y, res);
            pos++;
        }
        ans[query[i].second] = res;
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << " ";



    return 0;
}
