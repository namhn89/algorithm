using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 1e5 + 5 ;

long long n , k;
int l , MOD;
map<long long , long long> F;
long long fibo(long long x)
{
    long long k = x/2;
    if(F.count(x)) return F[x] ;
    if(x % 2 == 0) return F[x] = ( fibo(k) * fibo(k) + fibo(k - 1) * fibo(k - 1) ) % MOD;
    else return	F[x] = ( fibo(k - 1) * fibo(k) + fibo(k) * fibo(k + 1) ) % MOD ;
}

long long power(long long a , long long b)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}
int main()
{
	cin >> n >> k >> l >> MOD;
	if (k >= (1LL << min(l , 62)) )
	{
		cout << "0" << endl ;
		return 0;
	}
	F[0] = 1 % MOD ;
	F[1] = 1 % MOD ;
	int zero = fibo(n + 1);
	int one = (power(2 , n ) - zero + MOD) % MOD;
	long long ans = 1 % MOD ;
	for (int i = 0; i < min(l , 62); i++) {
		if ((1LL << i) & k) ans = ( ans * one ) % MOD;
		else ans = ( ans * zero ) % MOD;
	}
	for (int i = 62; i < l; i++) ans = (ans * zero) % MOD;
	cout << ans << endl;
	return 0;
}
