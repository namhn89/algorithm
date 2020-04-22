using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
bool isPrime (int n ) {
  for(int i = 2 ; i * i <= n ; ++i ) {
     if (n % i == 0 ) return false ;
  }
  return true ;
}
long long calc (int n , int p) {
   if (!isPrime(p)) return 0 ;
   if (n < p) return 0 ;
   n /= p ;
    long long res = n ;
    for(int i = 2 ; i < p && i <= n ; i ++ ){
        res -= calc (n , i );
    }
    return res;
}
vector <int> primes ;
long long Max ;
long long N ;
long long res ;
void DFS (int pos , long long prod , int add ) {
	if (prod > Max ) return;
	if (pos == primes.size() ) {
		if (add) res -= N/prod ;
		else res += N/prod ;
	}
	else {
		DFS(pos + 1 , prod , add );
		DFS(pos + 1 , prod * primes[pos] , 1 - add );
	}
}
long long calc2 (int n , int k ) {
	primes.clear();
	for(int i = 2 ; i <= k ; ++i ) if (isPrime(i)) primes.push_back(i);
	res = 0;
	Max = n;
	N = n ;
	DFS(0 , 1 , 0);
	return res;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int a , b , k ;
    cin >> a >> b >> k ;
    //cout << calc(b , k) - calc(a - 1 , k) << endl;
    cout << calc(b , k) - calc(a - 1 , k) << endl;
    return 0;
}
