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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int n , nq , m ;
int a[5011] , f[50111] ;
priority_queue<II , vector<II> , greater<II> > q  ;
int main(){
    scanf("%d" , &n) ;
    FOR(i , 1 , n) scanf("%d", &a[i]) ;
    sort(a + 1 , a + 1 + n) ;
    memset(f , 0x3f , sizeof f) ;
    q.push(II(f[0] = 0 , 0)) ;
    while(!q.empty()){
        II P = q.top() ; q.pop() ;
        FOR(i , 1 , n){
            int y = (P.second + a[i]) % a[1] ;
            if(f[y] > P.first + a[i]){
                q.push(II(f[y] = P.first + a[i] , y)) ;
            }
        }
    }
    scanf("%d", &nq);
    while(nq--){
        scanf("%d" , &m) ;
        if(m >= f[m % a[1]]) printf("TAK\n") ;
        else printf("NIE\n") ;
    }
    return 0;
}
