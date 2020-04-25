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
const int MAXN = 1e5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
string num (int x)
{
    string t ;
    while(x)
    {
        int a = x % 10 ;
        x /= 10 ;
        t += char(a +'0');
    }
    reverse(t.begin(),t.end());
    return t ;
}

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "";
    string a ;
    cin >> a ;
    FORE(i, 1, MAXN )
    {
        s += num(i);
    }
    //cout << s << endl ;
    cout << s.find(a) + 1 << endl;




    return 0;
}
