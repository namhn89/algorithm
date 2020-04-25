using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair < long long,int> LI ;
const int MOD = 1e9 + 7 ;
const int MAXN = 20 ;
const int MAXP = (1 << 18) ;
long long x[MAXN], y[MAXN] ;
long long a[2 * MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    a[1] = 2 ;
    a[2] = 3 ;
    a[3] = 5 ;
    FORE(i, 4, 34 ) a[i] = a[i - 1] + a[i - 2] + a[i - 3] ;
    FORE(i, 1, 17 ) x[i] = a[i] ;
    FORE(i, 1, 17 ) y[i] = a[i + 17] ;
    int n1 = 17, n2 = 17 ;
    vector <LI> T ;
    for(int mask = 0 ; mask < (1 << n1) ; ++mask)
    {
        long long sum = 0 ;
        for(int j = 0 ; j < n1 ; ++ j) if ( ((1 << j) & mask) != 0 ) sum += x[j + 1] ;
        T.push_back(make_pair(sum, mask)) ;
    }
    sort(T.begin(),T.end()) ;
    int Test ;
    int nTest = 0 ;
    scanf("%d",&Test);
    while(Test--)
    {
        nTest++;
        long long X ;
        scanf("%lld",&X) ;
        int ans = -1 ;
        for(int mask = 0 ; mask < (1 << n2) ; ++mask )
        {
            long long sum = 0 ;
            for(int j = 0 ; j < n2 ; ++j ) if ( ( (1 << j) & mask ) != 0 ) sum += y[j + 1] ;
            if (sum > X) break;
            long long check = X - sum ;
            int l = 0, r = T.size(), res = -1 ;
            while(l <= r )
            {
                int mid = (l + r ) / 2 ;
                if(T[mid].st == check )
                {
                    res = mid ;
                    break ;
                }
                else if( T[mid].st > check ) r = mid - 1 ;
                else l = mid + 1 ;
            }
            if (res == -1 ) continue ;
            int mask2 = T[res].nd ;
            ans = max(ans, __builtin_popcount(mask) + __builtin_popcount(mask2)) ;
        }
        printf("Case #%d: %d\n", nTest , ans) ;
    }
    return 0;
}
