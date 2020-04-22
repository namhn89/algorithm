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
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef pair<int,int> II;
const int MAXN = 1e6 + 1 ;
int a[MAXN];
int n, logn ;
int D, L ;
int rmq_max[MAXN][30], rmq_min[MAXN][30] ;
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
bool check (int l, int r)
{
    int lv = log2(r - l + 1 );
    int get_max =  max (rmq_max[l][lv], rmq_max[r + 1 -( 1 << lv )][lv]) ;
    int get_min =  min (rmq_min[l][lv], rmq_min[r + 1 -( 1 << lv )][lv]) ;
    if (get_max - get_min <= D ) return true ;
    else return false ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    //freopen(".out","w",stdout);
    read(n) ;
    read(L) ;
    read(D) ;
    FORE(i, 1, n ) read(a[i]);
    FORE(i, 1, n ) rmq_max[i][0] = rmq_min[i][0] = a[i];
    int m = int(log2(n)) + 1 ;
    for(int k = 1 ; (1 << k) <= n ;  k++)
    {
        for(int i = 1 ; i + (1 << k ) - 1 <= n ; ++i)
        {
            rmq_max[i][k] = max( rmq_max[i][k-1], rmq_max[i + (1<<(k-1))][k-1]);
            rmq_min[i][k] = min( rmq_min[i][k-1], rmq_min[i + (1<<(k-1))][k-1]);
        }
    }
    int ans = 0 ;
    int j = 1 ;
    FORE(i, 1, n )
    {
        while(j < n && check(i , j + 1)) j++;
        ans += max(0 ,(j - (L + i)  + 1));
    }
    cout << ans << endl;




    return 0;
}
