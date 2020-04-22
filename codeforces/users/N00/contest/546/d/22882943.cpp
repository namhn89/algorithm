using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int N =  5e6 + 1 ;
bitset <N + 1> bits ;
int primes[N + 1] ;
long long F[N + 1] ;
long long S[N + 1] ;
void precomputation()
{
    for(int i = 2; i < N; i += 2)	primes[i] = 2 ;
    int sq = sqrt(N - 1);
    for(int i = 3; i < N; i += 2)
        if (!bits[i])
        {
            primes[i] = i   ;
            if(i <= sq )
                for(int j = i * i ; j < N; j += 2 * i)
                    if (!bits[j])
                    {
                        primes[j] = i ;
                        bits[j] = 1 ;
                    }
        }
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    precomputation();
    FORE(i , 2 , N - 1 ) F[i] = F[i / primes[i]] + 1 ;
    FORE(i , 2 , N - 1 ) S[i] = S[i - 1] + F[i] ;
    int Test ;
    scanf("%d", &Test) ;
    while(Test--)
    {
        int a, b ;
        scanf("%d %d",&a, &b) ;
        printf("%lld\n", S[a] - S[b]) ;
    }

    return 0;
}
