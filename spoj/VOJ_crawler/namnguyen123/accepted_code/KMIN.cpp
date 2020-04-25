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
int a [55555], b [55555];
int main ()
{
	int m, n, k; scanf ("%d%d%d", &m, &n, &k);
	for (int i = 0; i < m; ++i) scanf ("%d", &a [i]);
	for (int i = 0; i < n; ++i) scanf ("%d", &b [i]);
	sort (a, a + m); sort (b, b + n);
	priority_queue <III, vector <III>, greater <III> > pq;
	pq.push (make_pair (a [0] + b [0], make_pair (0, 0)));
	II prev (-1, -1);
	while (k)
	{
		III tmp = pq.top (); pq.pop ();
		if (tmp.nd == prev) continue;
		int v = tmp.st, x = tmp.nd.st, y = tmp.nd.nd;
		printf ("%d\n", v);
		if (x + 1 < m) pq.push (make_pair (a [x + 1] + b [y], make_pair(x + 1, y)));
		if (y + 1 < n) pq.push (make_pair (a [x] + b [y + 1], make_pair(x, y + 1)));
		prev = tmp.nd;
		k--;
	}
	return 0;
}
