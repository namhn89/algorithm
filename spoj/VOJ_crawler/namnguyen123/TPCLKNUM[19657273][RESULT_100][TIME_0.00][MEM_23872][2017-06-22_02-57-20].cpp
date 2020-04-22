using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
long long N , K , S[MAXN] , ans;

int main()
{
    while( ~scanf("%lld %lld", &N, &K) )
    {
        ans = 9;
        for (int i = 2; i <= N; i++) ans = 10LL * ans % MOD;
        S[0] = 1;
        for (int i = 1; i <= N; i++)
        {
            S[i] = (S[i - 1] - (i > K ? S[i - K - 1] : 0) + MOD) * (i == N ? 8LL : 9LL) % MOD;
            if ( (S[i] += S[i - 1] ) >= MOD) S[i] -= MOD;
        }
        ans = (ans - (S[N] - (N >= K ? S[N - K] : 0)) + MOD) % MOD;
        printf("%lld\n", ans);
    }
}
