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

inline void read (int &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("xorsum.inp","r",stdin);
    // freopen("xorsum.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long s, x ;
    cin >> s >> x ;
    if (x > s )
    {
        cout << 0 << endl;
        return 0 ;
    };
    if( (s - x) % 2 || ( ( (s - x) / 2 ) & x ))
    {
        cout << 0 << endl;
        return 0 ;
    }
    long long t = (s - x)/2 ;
    vector<int> num1, num2 ;
    if (t == 0 ) num1.push_back(0);
    while(t)
    {
        num1.push_back(t % 2);
        t /=2 ;
    }
    long long k = x ;
    while(k)
    {
        num2.push_back(k % 2);
        k /= 2 ;
    }
    while( num1.size() < num2.size()) num1.push_back(0);
    while( num2.size() < num1.size()) num2.push_back(0);
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    ll ans = 1 ;
    FOR(i, 0, num2.size() )
    {
        if (num1[i] == 0 && num2[i] == 1) ans = ans * 2ll ;
    }
    if (x == s) ans -= 2 ;
    cout << ans << endl;


    return 0;
}
