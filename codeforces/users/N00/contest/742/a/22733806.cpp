using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long powmod(long long a, long long n, long long mod)
{
    long long r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % mod ;
        a= ( a * a ) % mod ;
        n >>=1 ;
    }
    return r;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n ;
    cin >> n ;
    cout << powmod(1378 , n , 10) << endl;

    return 0;
}
