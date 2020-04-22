using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const long long oo = 1e15 + 1 ;
long long n, m ;
bool check (int x)
{
    if (x >= oo) return true ;
    if (1LL * x * (x + 1) / 2  >= n) return true ;
    else return false ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    if (n <= m) return cout << n , 0 ;
    n -= m ;
    long long L = 0, R = oo , ans = 0 ;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if ( check(mid) ) ans = mid, R = mid - 1 ;
        else L = mid + 1 ;
    }
    cout << ans + m << endl;
    return 0;
}
