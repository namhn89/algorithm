using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const ll INF = 1e9 + 7 ;
typedef long long ll;
const int MAXN = 1e5 + 1 ;
ll MOD = 1e15 , r1 = 0 , r2 = 0 ;
struct x
{
    int le;
    int ri;
    int id ;
};
x a[MAXN];
bool SAPXEP (x c , x b)
{
    return db(c.ri)/c.le < db(b.ri)/b.le;
}
int main()
{
    // freopen("SCHEDULE.inp","r",stdin);
    //  freopen("SCHEDULE.out","w",stdout);
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i].le ;
        a[i].id = i + 1 ;
    }
    for(int i = 0 ; i < n ; ++i)cin >> a[i].ri;
    sort(a , a + n, SAPXEP);
    ll tg = 0 , s = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        tg += a[i].ri ;
        s += tg * a[i].le ;
        r2 += s;
        r1 += r2/MOD;
        r2 %= MOD;
    }
    cout << s << endl ;
    for(int i = 0 ; i < n ; ++i)cout << a[i].id << " " ;
    return 0;
}
