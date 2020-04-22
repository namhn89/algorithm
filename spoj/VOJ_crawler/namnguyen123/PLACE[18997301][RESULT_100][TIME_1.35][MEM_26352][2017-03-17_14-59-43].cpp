using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 5e5 + 5 ;
int in[MAXN], out[MAXN], tick = 0, n, q, dad[MAXN], a[MAXN] ;
long long BIT[MAXN] ;
vector <int> g[MAXN] ;
int Max = 0 ;
void update (int pos , int value )
{
    for(int node = pos ; node <= Max ; node += node & -node) BIT[node] += value ;
}
long long get (int pos )
{
    long long res = 0 ;
    for(int node = pos ; node > 0 ; node -= node & -node) res += BIT[node] ;
    return res ;
}
void DFS (int u, int parent )
{
    in[u] = ++tick ;
    dad[u] = parent ;
    TR(g[u], it)
    {
        if (*it == parent) continue ;
        DFS(*it , u) ;
    }
    out[u] = tick ;
    Max = max(Max , out[u]) ;
}
int main()
{
#define TASK "PLACE"
   // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false) ; cin.tie(NULL);
    memset(BIT , 0 , sizeof(BIT)) ;
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; ++i )
    {
        if (i == 1) cin >> a[i] ;
        else
        {
            cin >> a[i] >> dad[i] ;
            g[dad[i]].push_back(i) ;
        }
    }
    DFS(1 , -1);
    //for(int i = 1 ; i <= n ; ++i ) cout << in[i] << " " << out[i] << endl;
    while(q--)
    {
        char c ;
        cin >> c ;
        if (c == 'p')
        {
            int u , X ;
            cin >> u >> X ;
            update(in[u] + 1, X ) ;
            update(out[u] + 1 , -X ) ;
        }
        if (c == 'u')
        {
            int u ;
            cin >> u ;
            cout << get(in[u]) + a[u] << endl;
        }
    }
    return 0;
}
