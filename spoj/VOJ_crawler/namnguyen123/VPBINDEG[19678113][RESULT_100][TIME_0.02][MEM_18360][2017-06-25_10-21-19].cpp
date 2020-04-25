using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int nxt0 [MAXN] ;
int nxt1 [MAXN] ;
int f[MAXN] ;
char s[MAXN] ;
int n, k ;
long long calc (int deg)
{
    vector <int> pos1, pos0 ;
    FORE(i, 1, n) if (s[i] == '1') pos1.push_back(i) ;
    else pos0.push_back(i) ;
    FORE(i , 0 , n + 1) f[i] = nxt0[i] = nxt1[i] = 0 ;
    int cnt0 = 0, cnt1 = 0 ;
    FORE(i, 1, n)
    {
        if(s[i] == '0')
        {
            cnt0++;
            if (pos0.size() - cnt0 >= deg ) nxt0[i] = pos0[cnt0 + deg - 1] ;
        }
        else
        {
            cnt1++;
            if (pos1.size() - cnt1 >= deg ) nxt1[i] = pos1[cnt1 + deg - 1] ;
        }
    }
    long long res = 0 ;
    FORD(i, n, 1 ) if (nxt1[i] == 0) nxt1[i] = nxt1[i + 1] ;
    FORE(i, 1, n ) if (s[i] == '1') f[i] = 1 ;
    FORE(i, 1, n ) f[i] += f[i - 1] ;
    FORE(i, 1, n )
    {
        if (nxt0[i])
        {
            int pos = nxt1[nxt0[i]] ;
            if (pos) res += f[n] - f[pos] + 1 ;
        }
    }
    return res ;
}
int main()
{
#define TASK "BINDEG"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int Test ;
    scanf("%d",&Test) ;
    while(Test --)
    {
        scanf("%d %d", &n, &k ) ;
        scanf("%s", s + 1) ;
        long long ans = calc(k - 1) - calc(k) ;
        printf("%lld\n",ans) ;
    }
    return 0;
}
