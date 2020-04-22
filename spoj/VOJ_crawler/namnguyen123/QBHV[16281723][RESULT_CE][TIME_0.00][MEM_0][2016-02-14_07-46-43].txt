using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=10;
int cnt[27] , n , m = 0 ;
string s , x ;
string a;
bool Free[MAXN] ;
void QSort(int l ,int r)
{
    if(l >= r) return ;
    int i = l ;
    int j = r ;
    int mid = s[(l+r)/2] ;
    while(i <= j)
    {
        while(s[i] < mid) i++ ;
        while(s[j] > mid) j-- ;
        if(i <= j)
        {
            if(i < j)
                swap(s[i] , s[j]) ;
            i++ ;
            j--;
        }
    }
    QSort(l , j) ;
    QSort(i , r) ;
}
int factorial(int n)
{
    int sum = 1 ;
    FORE(i, 1, n) sum *= i ;
    return sum ;
}
void enter(int i)
{
    FORE(j , 1 , n)
    {
        if(Free[j])
        {
            x[i] = s[j] ;
            Free[j] = false;
            if(i == n && x > a){
                FORE(k , 1 , n) printf("%c" , x[k]) ;printf("\n") ;
                a = x ;
            }
            else enter(i+1) ;
            Free[j] = true ;
        }
    }
}
int main()
{
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    cin >> s;
    n = s.size() ;
    FORD(i, n, 1) s[i] = s[i-1] ;
    QSort(1 , n) ;
    FORE(i, 1 ,n) Free[i] = true;
    FORE(i, 1, n) cnt[s[i] - 'A']++ ;
    int ans = factorial(n) ;
    FORE(i, 0, 25)
    {
        ans /= factorial(cnt[i]) ;
    }
    FORE(i, 1, n + 1) x = x + ' ' ;
    a  = "" ;
    cout << ans << endl;
    enter(1) ;

    return 0;
}
