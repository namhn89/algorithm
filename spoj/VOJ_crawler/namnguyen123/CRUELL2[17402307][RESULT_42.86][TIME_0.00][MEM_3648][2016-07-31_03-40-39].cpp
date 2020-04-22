using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n;
double a [MAXN];
double check ( double x)
{
	double res = 0.0;
	FORE(i , 0 , n){
		res += a[i] * pow (x, i);
	}
	return res;
}
int main ()
{
	scanf ("%d", &n);
	FORE(i , 0 , n ) cin >> a[i] ;
	double l = -1e6, r = 1e6;
	while (1)
	{
		double mid = (l + r) / 2 ;
		double ans = check(mid);
		//cout << check(mid) << endl;
		if (abs (ans - 0) <= double(5e-4) ) break;
		if (ans < 0) l = mid ;
		else r = mid ;
	}
	printf ("%.0lf\n", l * 1000);
	return 0;
}
