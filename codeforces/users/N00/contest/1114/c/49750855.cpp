using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 1e5 + 5 ;
int N , M , K ;
int a[MAXN] ;

long long Get (long long n , long long x) {
   long long res = 0 ;
   while(n) {
       res += (n / x) ;
       n /= x ;
   }
   return res ;
}

vector < pair<long long,int> > getFact (long long n) {
    vector < pair <long long , int> > fact ;
    for (long long i = 2 ; i * i <= n ; ++i) {
        if (n % i == 0) {
            int cnt = 0 ;
            while(n % i == 0) {
                n /= i ;
                cnt ++ ;
            }
            fact.push_back(make_pair(i , cnt)) ;
        }
    }
    if (n > 1) {
        fact.push_back(make_pair(n , 1)) ;
    }
    return fact ;
}

int main()
{
#define TASK "test"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long N , M ;
    cin >> N >> M ;
    vector < pair<long long , int> > base = getFact(M) ;
    long long ans = max(N , M) ;
    for (int i = 0 ; i < base.size() ; ++i ) {
            long long p = base[i].st ;
            int pow = base[i].nd ;
            ans = min(ans , (Get(N , p) / pow) ) ;
    }
    cout << ans;


    return 0;
}

