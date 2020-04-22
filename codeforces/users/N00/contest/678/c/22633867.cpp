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
long long lcm (long long a , long long b ){ return (a * b) / __gcd(a , b) ;}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, a, b, p, q ;
    cin >> n >> a >> b >> p >> q ;
    long long ans = 0;
    ans += (n / a) * p;
    ans += (n / b) * q;
    ans -= (n / lcm (a, b) ) * min(p, q);
    cout << ans << endl;

    return 0;
}
