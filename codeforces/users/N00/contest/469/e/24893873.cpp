using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
// f(x + 10^{18}) = f(x) + 1
// [x, x + 10^{18} - 1] + 1= [x + 1, x + 10^{18}]
// g[0, 10^x] = 45 * x * 10 ^{x -1}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    long long a ;
    cin >> a ;
    long long p10 = 1 ;
    for(int i = 1 ; i <= 18 ; ++i) p10 = p10 * 10  ;
    long long x = 9 * ( (9 * p10) % a ) % a ;
    cout << a - x <<  " " << a - x + p10 - 1 << endl;
    return 0;
}
