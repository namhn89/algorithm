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
int n ;
pair <int,int>  p[MAXN] ;
int dp[MAXN] ;
int pre[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d", &n);
    FORE(i, 1, n)
    {
        scanf("%d", &p[i].st);
        p[i].nd = i;
    }
    sort(p + 1 , p + n + 1 );
    int ans = 0;
    FORE(D , 1 , 100 )
    {
        FORE(i , 1 , n) dp[i] = pre[i] = 0;
        int i = 1;
        FORE(j , 1 , n)
        {
            while (i <= n && p[i].st < p[j].st - D) i++;
            if (i > n || p[i].st > p[j].st - D) continue;
            while (i < n && p[i+1].st == p[j].st - D  && p[i+1].nd < p[j].nd ) i++;
            if (p[i].nd < p[j].nd) pre[p[j].nd] = p[i].nd;
        }
        FORE(j , 1 , n )
        {
            dp[j] = dp[pre[j]]+1;
            ans = max(ans, dp[j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
