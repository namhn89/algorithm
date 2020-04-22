using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
struct data
{
    int x, gold, material ;
    data () {} ;
    data (int x, int gold, int material ) : x(x), gold (gold), material(material) {}
};
bool cmp (data a, data b )
{
    return a.x < b.x ;
}
long long S[MAXN] ;
long long res[MAXN] ;
data a[MAXN] ;
bool check (int mid , int i)
{
    if (a[mid].x - a[i].x <= S[mid] - S[i - 1]) return true;
    else return false ;
}
int main()
{
#define TASK "BGMINE"
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    FORE(i, 1, n ) cin >> a[i].x >> a[i].gold >> a[i].material ;
    sort(a + 1, a + n + 1, cmp ) ;
    // FORE(i, 1, n ) cout << a[i].x << " " << a[i].gold << " " << a[i].material << endl;
    FORE(i, 1, n ) S[i] = S[i - 1] + a[i].material ;
    FORE(i, 1, n ) res[i] = res[i - 1] + a[i].gold ;
    long long ans = 0 ;
    FORE(i, 1, n )
    {
        int l = i , r = n , ans_i = -1 ;
        while(l <= r)
        {
            int mid = (l + r) / 2 ;
            if (check(mid , i)) ans_i = mid, l = mid + 1 ;
            else r = mid - 1 ;
        }
        ans = max(ans , res[ans_i] - res[i - 1]) ;
    }
    cout << ans << endl;





    return 0;
}
