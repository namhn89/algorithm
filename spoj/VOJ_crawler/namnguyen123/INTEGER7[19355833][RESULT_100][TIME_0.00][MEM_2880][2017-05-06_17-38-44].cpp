using namespace std;
#include<bits/stdc++.h>
#define X first
#define Y second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
typedef pair <long long, long long > LL ;

LL  extended_gcd(long long a, long long b)
{
    LL  qr, st;
    if (!b ) return LL (1, 0);
    else
    {
        qr = LL (a / b, a % b );
        st = extended_gcd(b, qr.Y);
        return LL (st.Y, st.X - qr.X * st.Y );
    }
}
long long a, b, c, x ;
long long calc (long long a, long long b)
{
    if (a >= 0) return a / b ;
    else return -calc(-a, b) - 1;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> x >> b >> c ; c -= x ;
    if (a == 0 && b == 0)
    {
        cout << "0 0" << endl ;
    }
    if (a == 0)
    {
        cout << 0 << ' ' << -c / b << endl ;
        return 0;
    }
    if (b == 0)
    {
        cout << c / a << ' ' << 0 << endl ;
        return 0 ;
    }
    long long d = __gcd(a, b) ;
    a /= d , b /= d , c /= d ;
    LL ans = extended_gcd(a, -b) ;
    if (ans.X * a - ans.Y * b == -1 ) c = -c;
    ans.X *= c, ans.Y *= c;
    long long k = min(calc(ans.X, b), calc(ans.Y, a) );
    ans.X -= b * k, ans.Y -= a * k;
    cout << ans.X << ' ' << ans.Y << endl;
    return 0;
}
