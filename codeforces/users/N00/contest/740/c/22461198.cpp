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
const int oo = 1e9 + 100 ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ;
    cin >> n >> m ;
    int len = n ;
    FORE(i, 1, m)
    {
        int l, r ;
        cin >> l >> r ;
        len = min(len, r - l + 1) ;
    }
    cout << len << endl;
    for(int i = 0 ; i < n ; ++i )
    cout << i % len << " ";


    return 0;
}
