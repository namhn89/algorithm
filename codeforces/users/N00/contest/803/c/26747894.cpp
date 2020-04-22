using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const long long INF = 1e6 + 1 ;
long long n , k ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    if (k > INF) {cout << -1 << endl ; return 0 ;}
    vector <long long> divisor ;
    for(long long i = 1 ; i * i <= n ; ++i )
    {
        if (n % i ) continue ;
        divisor.push_back(i) ;
        if (n != i * i) divisor.push_back(n / i) ;
    }
    long long ans = -1 ;
    sort(divisor.begin() , divisor.end()) ;
    for(int i = 0 ; i < divisor.size() ; ++i ){
         if (k * (k + 1) / 2 <= n / divisor[i] ) ans = divisor[i] ;
    }
    if (ans == -1) {cout << -1 << endl; return 0 ;}
    vector <long long> a(k) ;
    n /= ans ;
    for (int i = 0; i < k; ++i) {
        a[i] = (i + 1) * ans ;
    }
    n -= (k + 1) * k / 2;
    a[k - 1] += n * ans;

    for (int i = 0; i < k ; ++i ) cout << a[i] << ' ' ;
    cout << endl;
    return 0;
}
