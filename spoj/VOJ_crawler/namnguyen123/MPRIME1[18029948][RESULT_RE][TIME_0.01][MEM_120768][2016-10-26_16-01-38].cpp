using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

const int MOD = 1e9 + 7 ;
const int MAXN = 1e7 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

vector <int> prime ;
int f[MAXN] ;
int sum[MAXN] ;
int dp[MAXN] ;

void sang()
{
    FORE(i, 2, 11000 ) f[i] = 0 ;
    for(int i = 2 ; i * i <= 11000 ; ++i)
    {
        if(!f[i])
        {
            for(int j = 2  ; j * i <= 11000; ++j)
            {
                f[i*j] = 1 ;
            }
        }
    }
    for(int i = 2 ; i <= 11000 ; ++i)
    {
        if(!f[i])prime.push_back(i);
    }
}

int main()
{
     freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime.push_back(0);
    sang();
    int n = prime.size() - 1 ;
    // cout << n << endl;
    FORE(i, 1, n ) sum[i] = sum[i-1] + prime[i] ;
    FORE(i, 1, n )
    {
        FORE(j, i, n )
        {
            dp[sum[j] - sum[i-1]]++;
        }
    }
    while(cin >> n)
    {
        if(n == 0) break;
        cout << dp[n] << endl;
    }

    return 0;
}
