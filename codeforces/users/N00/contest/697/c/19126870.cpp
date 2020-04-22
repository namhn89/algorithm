using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef pair<LL,ll> LLL;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
map<LL,ll> g;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int m ;
    cin >> m ;
    while(m--)
    {
        int k;
        cin >> k ;
        if(k==1)
        {
            ll u, v, w, cost;
            cin >> u >> v >> w ;
            while (u!=v)
            {
                if(u > v) swap(u, v);
                cost = v/2;
                if(g.find(LL(cost, v))==g.end() ) g[LL(cost, v)]=w;
                else g[LL(cost, v)]+=w;
                v = cost;
            }
        }
        else
        {
            ll u,v,cost;
            cin >> u >> v ;
            ll ans=0;
            while (u!=v)
            {
                if(u > v) swap(u, v);
                cost = v/2 ;
                if( !(g.find(LL(cost,v)) == g.end()) ) ans += g[LL(cost, v)];
                v = cost;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
