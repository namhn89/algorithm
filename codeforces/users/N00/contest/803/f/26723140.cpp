using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

#define maxn 100000 + 5

int n , maxai , i , ai , a[maxn], p[maxn], dp[maxn], j;
long long ret , kol ;
long long invfact[MAXN] , fact[MAXN] ;

long long power (long long a , long long n)
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1)  res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long nCr (int n, int r)
{
    if (r > n) return 0 ;
    return ( (fact[n] * invfact[n - r] % MOD ) * invfact[r] ) % MOD ;
}

int main () {
    fact[0] = invfact[0] = 1 ;
    for(i = 1 ; i < MAXN ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for(i = 1 ; i < MAXN ; ++i ) invfact[i] = power(fact[i], MOD - 2) ;

	// Input reading

	scanf("%d", &n);
	maxai = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d", &ai);
        a[ai]++ ;
		maxai = max(maxai , ai);
	}

	// Mobius function calculation

	for(i = 2 ; i <= maxai ; i++) if (!p[i]) {
		j = i;
		while (j <= maxai) {
			if (!p[j]) p[j] = i;
			j += i;
		}
	}

	// Calculation M(X) * C(D(X), 3), for all X where this expression is nonzero

	for(i = 1 ; i <= maxai ; i++) {

		// Mobuis function

		if (i == 1) dp[i] = 1; else {
			if (p[i / p[i]] == p[i]) dp[i] = 0; else // Checking for non square-free
			dp[i] = -1 * dp[i / p[i]];
		}
		if (!dp[i]) continue;

		// Calculating D(X). Can be done naively, because [N/1] + [N/2] + [N/3] + ... + [N/N] -> N log N

		j = i ; kol = 0;
		while (j <= maxai) {
			kol += a[j];
			j += i;
		}

		// Adding the number of the combinations to the final answer

		ret += (power(2 , kol ) - 1) * dp[i] % MOD ;
		ret = (ret % MOD + MOD) % MOD ;
	}
	cout << ret << endl;
    return 0;
}
