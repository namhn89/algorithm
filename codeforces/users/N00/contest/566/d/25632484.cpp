using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e5 + 5 ;
int par[MAXN], n, q , L[MAXN] ;
struct DSU
{
    int par[MAXN] ;
    void refine (int n)
    {
        for(int i = 1 ; i <= n ; ++i ) par[i] = i ;
    }
    int findSet (int p)
    {
        if (par[p] == p) return p ;
        else return par[p] = findSet(par[p]) ;
    }
    void Union (int u, int v)
    {
        int x = findSet(u), y = findSet(v) ;
        if (x > y) swap(x, y) ;
        par[y] = x ;
    }
};
int next (int p) {
   if (p == L[p]) return p ;
   else return L[p] = next(L[p]) ;
}
int main()
{
#define TASK "test"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    DSU a ;
    scanf("%d %d",&n ,&q) ;
    a.refine(n) ;
    for(int i = 1 ; i <= n ; ++i ) L[i] = i ;
    for(int i = 1 ; i <= q ; ++i )
    {
        int type , u , v ;
        scanf("%d %d %d", &type , &u , &v) ;
        if (type == 1) a.Union(u , v) ;
        else if (type == 2)
        {
            while(u < v)
            {
               //
               // cout << u << " ";
                u = next(u);
               // cout << u << " ";
                if (u < v)
                {
                    a.Union(u , v) ;
                    L[u] = L[u] + 1 ;
                }
            }
            //cout << endl ;
        }
        else
        {
            if (a.findSet(u) == a.findSet(v)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
