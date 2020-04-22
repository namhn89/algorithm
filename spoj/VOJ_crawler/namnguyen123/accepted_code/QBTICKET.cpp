using namespace std;
#include<bits/stdc++.h>
#define open freopen("in.inp","r",stdin);freopen("in.out","w",stdout);
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define mp make_pair
#define FOR(i,a,b) for(int i = a ,_b = (b); i <= _b ; i ++ )
#define FOD(i,a,b) for(int i = a ,_b = (b); i >= _b ; i -- )
#define sz size()
#define pb push_back
#define vi vector<int>
#define low lower_bound
#define PI 2*acos(0)
#define DEB(X) cout << #X << " " <<  X ;
#define ce cout << endl ;
typedef pair<int,int> II ;
typedef long long ll ;
const ll INF = 1e15+7 ;
const int MOD = 1e9+7 ;
const int MAXN = 1e5+100 ;
const double eps = 1e-9 ;
double sqr( double a ) { return a*a; }
bool IsEqual(double a , double b){
    return abs(a-b) < eps ;
}
int l1 , l2 , l3 , c1 ,c2 , c3 ;
ll ans = 0 ;
int n , beg , ed  ;
ll a[MAXN] , f[MAXN] ;
ll min(ll a , ll b) {return (a < b) ? a : b ;}
int d(int i , int j){ return a[i] - a[j] ; }
void input(){
    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3 ;
    cin >> n ;
    cin >> beg >> ed ;
    FOR(i ,2 , n) cin >> a[i] ;
 
}
void optimize(){
    a[1] = 0 ;
    sort(a + 1 , a + 1 + n) ;
    if(beg > ed) swap(beg , ed) ;
    f[beg] = 0 ;
    FOR(i , beg+1 , ed){
        f[i] = INF ;
        FOD(j , i-1 , beg){
            ll v ;
            if(d(i,j) > l3) break ;
            if(d(i,j) > l2) v = c3 ;
            else if(d(i,j) > l1) v = c2 ;
            else v = c1 ;
            f[i] = min(f[i] , f[j] + v) ;
        }
    }
}
void output(){
    cout << f[ed] ;
 
}
int main(){
    #ifndef ONLINE_JUDGE
        open;
    #endif
    input() ;
    optimize() ;
    output() ;
    //printf("%lld" , f[ed]) ;
    return 0;
}
  