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
ll f[MAXN][21];
ll a[MAXN];
ll n, K ;
long long int read_int(long long &a){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		a = ret;
	else
		a = -ret;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    read_int(n);
    read_int(K);
    FORE(i, 1, n ) read_int(a[i]);
    FORE(i, 1, n )
    {
        f[i][1] = 1 ;
        FOR(j, 1, i )
        {
            if(a[i] > a[j] )
            {
                FOR(k, 1, K )
                {
                    f[i][k+1] += (f[j][k]%MOD);
                    f[i][k+1] %= MOD;
                }
            }
        }
    }
    ll ans = 0 ;
    FORE(i , 1 , n ){
    ans = (ans + f[i][K]) % MOD ;
    }
    printf("%lld",ans);

        return 0;
    }
