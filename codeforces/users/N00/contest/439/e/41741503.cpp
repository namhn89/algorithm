using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int N = 1e5 + 5 ;
const int MAXN = 1e5 + 10 ;
long long fact[MAXN] , infact[MAXN] ;
long long power (long long a , long long n) {
	long long res = 1 ;
	while(n) {
		if (n & 1) res = (res * a) % MOD ;
		a = (a * a) % MOD ;
		n >>= 1 ;
	}
	return res ;
}
long long nCr (long long n , long long r) {
	if (r > n) return 0 ;
	long long res = fact[n] ;
	res = (res * infact[n - r]) % MOD ;
	res = (res * infact[r]) % MOD ;
	return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    fact[0] = infact[0] = 1 ;
    for(int i = 1 ; i < MAXN ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    infact[N - 1] = power(fact[N - 1] , MOD - 2) ;
    for(int i = N - 2 ; i >= 1 ; i--) infact[i] = (infact[i + 1] * (i + 1)) % MOD ;
    int nQuery ;
    scanf("%d", &nQuery) ;
    for(int i = 0 ; i < nQuery ; ++i) {
        int ans = 0 ;
    	int p , f ;
    	scanf("%d %d", &p , &f) ;
    	std::vector<int> v;
    	int y = p ;
    	for(int j = 2 ; j * j <= y ; ++j) {
    		 if (y % j == 0) {
    		 	  while(y % j == 0) y /= j ;
    		 	  v.push_back(j) ;
    		 }
    	}
    	if (y > 1) v.push_back(y)  ;
    	int sz = v.size() ;
    	for(int mask = 0 ; mask < (1 << sz) ; ++mask) {
    		int k = 1 ;
    		for(int j = 0 ; j < sz ; ++j ) if ((1 << j) & mask) k *= v[j] ;
    		if (__builtin_popcount(mask) & 1) ans -= nCr(p / k - 1 , f - 1) ;
    	    else ans += nCr(p / k - 1 , f - 1) ;
    	    ans %= MOD ;
    	}
    	ans = (ans + MOD) % MOD ;
    	printf("%d\n" , ans);

    }

    return 0;
}
