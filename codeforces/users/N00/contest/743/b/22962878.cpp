using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k  ;
    cin >> n >> k;
        if (k & 1)
    {
        cout << 1 << endl;
        return 0 ;
    }
    FORE(i, 1, n)
    {
        if (k % (1LL << i) == (1LL << (i - 1)) )
        {
            cout << i << endl;
            return 0 ;
        }
    }

    return 0;
}
