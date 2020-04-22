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

inline void read (int &x) {
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(;((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    for(;c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;

#define BASE 1000000000
struct bigint
{
    vector < ll > digit ;
    void clear()
    {
        digit.clear();
    }
    void refine()
    {
        digit.push_back(0);
        for(int i = 0 ; i < digit.size() - 1 ; ++i )
        {
            digit[i + 1] += digit[i] / BASE ;
            digit[i] = digit[i] % BASE ;
            if(digit[i] < 0 )
            {
                digit[i] += BASE ;
                digit[i + 1] -- ;
            }
        }
        while(digit.size() >= 2 && digit.back() == 0 ) digit.pop_back();
    }
    bigint operator * (ll x)
    {
        bigint res ;
        res.digit.resize(digit.size() + 1);
        for(int  i = 0 ; i < digit.size() ; ++i )
        {
            res.digit[i] = digit[i] * x ;
        }
        res.refine();
        return res ;
    }
    void divide(ll x , bigint &q , ll &r)
    {
        q.clear();
        r = 0 ;
        for(ll i = digit.size() - 1 ; i >= 0 ; --i )
        {
            r = r * BASE + digit[i] ;
            q.digit.push_back(r / x);
            r = r % x ;
        }
        reverse(q.digit.begin(),q.digit.end());
        q.refine();
    }
    bigint operator / (ll x)
    {
        bigint q ;
        ll r ;
        divide(x , q , r);
        return q ;
    }
    void COUT()
    {
        refine();
        printf("%lld" , digit.back());
        if(digit.size() >= 2 )
        {
            for(ll i = digit.size() - 2 ; i >= 0 ; --i )
            {
                printf("%09lld",digit[i]);
            }
        }
        printf("\n");
    }
};

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    bigint ans ;
    ans.digit.push_back(1);
    int n , k ;
    cin >> n >> k ;
    n = n - k + 1 ;
    FORE(i , 1 , n ) ans = ans * 2 ;
    ans.COUT();

    return 0;
}
