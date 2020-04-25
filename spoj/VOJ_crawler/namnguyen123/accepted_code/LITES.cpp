using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
II tree[8*MAXN] ;
int res ;
void update (int k, int l, int r, int x, int y)
{
    if(tree[k].nd % 2)
    {
        tree[k].st = (r - l + 1) - tree[k].st;
        tree[2*k].nd++;
        tree[2*k + 1].nd++;
        tree[k].nd = 0 ;
    }
    if(l > y || r < x ) return;
    if(x <= l && y >= r)
    {
        tree[k].st = (r - l + 1) - tree[k].st;
        tree[2*k].nd++;
        tree[2*k + 1].nd++;
        tree[k].nd = 0 ;
        return;
    }
    int mid = ( l + r )/2;
    update(2*k, l, mid, x, y );
    update(2*k + 1, mid + 1, r,x, y );
    tree[k].st = tree[2*k].st + tree[2*k + 1].st;
}
void Query(int k, int l, int r, int x, int y)
{
    if(tree[k].nd % 2 )
    {
        tree[k].st = (r - l + 1) - tree[k].st;
        tree[2*k].nd++;
        tree[2*k + 1].nd++;
        tree[k].nd = 0 ;
    }
    if(l > y || r < x ) return;
    if(x <= l && r <= y )
    {
        res += tree[k].st;
        return;
    }
    int mid = ( l + r) / 2;
    Query(2 * k, l, mid, x, y );
    Query(2 * k + 1, mid + 1, r, x, y);
    tree[k].st = tree[2*k].st + tree[2*k + 1].st;
}
int main()
{
    // freopen("LITES.inp","r",stdin);
    // freopen("LITES.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ;
    cin >> n >> m ;
    while(m--)
    {
        int type, x, y ;
        cin >> type >> x >> y ;
        if (type == 0 )
        {
            update(1, 1, n, x, y);
        }
        else
        {
            res = 0 ;
            Query(1 , 1 , n , x , y );
            cout << res << endl;
        }
    }
    return 0;
}
