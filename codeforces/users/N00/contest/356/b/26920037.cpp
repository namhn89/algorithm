using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
int cnt[MAXN][30] ;
string a , b ;
long long n , m ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m ;
    cin >> a >> b ;
    long long nA = a.size() , nB = b.size() ;
    long long g = __gcd(nA , nB) ;
    long long l = nA * nB / g ;
    long long res = l ;
    for(int i = 0 ; i < nA ; ++i ) cnt[i % g][a[i] - 'a']++;
    for(int i = 0 ; i < nB ; ++i ) res -= cnt[i % g][b[i] - 'a'] ;
    cout << (nA * n / l) * res  << endl;

    return 0;
}
