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
typedef vector<int> VI ;
typedef vector<II> VII;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 100 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
string  s = "";
int f[MAXN] ;
int  n, k ;
string num_to_string(int x)
{
    string s = "" ;
    stack<char> st;
    while(x)
    {
        s.insert(0, 1, x % 10 + 48 );
        x /= 10 ;
    }
    return s ;
}
vector <int> prime ;
void sang()
{
    FORE(i, 1, 1000000 ) f[i] = 0 ;
    for(int i = 2 ; i*i <= 1000000 ; ++i)
    {
        if(!f[i])
        {
            for(int j = 2 ; j*i <= 1000000 ; ++j)
            {
                f[i*j] = 1 ;
            }
        }
    }
    FORE(i , 2 , 1000000 ) if(!f[i]) prime.push_back(i) ;
}
void Solve()
{
    deque<char> dq;
    for(int i = 0 ; i < s.size() ; i++ )
    {
        while(k>0 && dq.size()>0 && dq.back()<s[i])
        {
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }
    while(dq.size()>k)
    {
        cout << dq.front() ;
        dq.pop_front();
    }
}
int main()
{
    //freopen("KDEL.in","r",stdin);
    //freopen("KDEL.out","w",stdout);
    cin >> n >> k ;
    sang() ;
    int ans = 0 ;
    FOR(i , 0 , n )
    {
        string k = num_to_string(prime[i]);
        s = s + k ;
    }
    Solve();
    return 0;
}
