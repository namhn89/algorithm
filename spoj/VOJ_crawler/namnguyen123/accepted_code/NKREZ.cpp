using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
typedef long long ll;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 1 ;
long long t[MAXN] ;
struct pt
{
    ll x , y ;
} f[MAXN];
int n ;
long long res[MAXN] ;
bool xepkt(const pt & p1,const pt & p2)
{
    return p1.y < p2.y ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;
    for(int i=1; i<=n; i++) cin >> f[i].x >> f[i].y ;
    sort(f + 1, f + n + 1, xepkt );
    for(int i=1; i<=n; i++)
    {
        res[i] = max(res[i - 1], f[i].y  - f[i].x ) ;
        int l = 1 ;
        int r = i - 1 ;
        while(l <= r )
        {
            int mid = (l+r)/2 ;
            if(f[mid].y <= f[i].x)
            {
                res[i] = max(res[mid] + f[i].y - f[i].x, res[i]);
                l = mid + 1 ;
            }
            else r = mid - 1;
        }
    }
    cout << res[n] << endl;
    return 0 ;
}
