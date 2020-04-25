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
typedef vector<int> VI ;
typedef vector<II> VII;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int par[MAXN];
int anc(int p)
{
    if (par[p]==p) return p;
    par[p] = anc(par[p]);
    return par[p];
}

void join(int p, int q)
{
    par[anc(p)] = anc(q);
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q ;
    cin >> Q ;
    for(int i = 1 ; i <= 100000; ++i )par[i] = i ;
    while(Q--)
    {
        int x, y, z ;
        cin >> x >> y >> z ;
        if(z == 1)
        {
            join(x,y);
        }
        if(z == 2)
        {
            int k = anc(x);
            int t = anc(y);
            if(k == t) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }


    return 0;
}
