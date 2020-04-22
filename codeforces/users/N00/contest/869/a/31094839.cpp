using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e6 + 5 ;
int n ;
int x[MAXN] , y[MAXN] ;
bool cnt[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] , cnt[x[i]] = 1 ;

    for (int i = 1; i <= n; i++) cin >> y[i] , cnt[y[i]] = 1 ;

    int ans = 0;
    FORE(i , 1 , n)
    {
        FORE(j , 1 , n)
        {
            if (cnt[x[i] ^ y[j]])
            {
                ++ans;
            }
        }
    }
    if (ans & 1) cout << "Koyomi" << endl ;
    else cout << "Karen" << endl;

    return 0;
}
