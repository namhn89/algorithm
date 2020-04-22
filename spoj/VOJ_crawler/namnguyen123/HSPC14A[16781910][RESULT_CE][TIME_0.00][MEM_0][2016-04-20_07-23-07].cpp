using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e6+5;
const int INF = 2e9+1;
int n;
int check(int x,int y)
{
    if (x > y) swap(x, y);
    if (x == 1)
    {
        return y - 1;
    }
    if (x == 0) return INF;
    return check(x, y%x) + y / x;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int res = INF;
    cin >> n;
    while(n--)
    {
        int N;
        cin >> N;
        FORE(i, 1, N/2)
        {
            res = min(res , check( i , N) );
        }
        if (res==INF)cout << 0 <<endl;

        else cout << res << endl;
    }


    return 0;
}
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	return 0;
}